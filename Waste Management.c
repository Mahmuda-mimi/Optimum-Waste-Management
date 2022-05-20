#include <stdio.h>

void iteration(float matrix_new[15][15], int column, int waste_type[13]);
//step 1
int main()
{
    float matrix[15][15];
    float trans_matrix[15][15];
    int i, j;
    int row, column;
    int waste_type[13];
    float land_cap, recycle_cap;

    FILE *file;
    file = fopen("Group-6_FINAL_PROJECT_FILE.txt", "w");
    if (file == NULL)
    {
        printf("\n  File doesn't exist");
    }
    else
    {
        printf("\n  File is opened\n");
        printf("\n  Optimum Cost of Managing Different Wastes of Any Municipality In Bangladesh \n\n");
        //The waste types are indexed based on types. It is printed for the user so that they can input the type number
        printf("  Types available:\n  0 = Construction & Demolition \n  1 = Metal \n  2 = Paper \n  3 = Plastics \n  4 = Food \n  5 = Wood \n  6 = Horticultural \n  7 = Ash & Sludge \n  8 = Textile/Leather \n  9 = Used Slag \n  10 = Glass \n  11 = Scrap Tyres \n  12 = Others \n");
        //Number of types of wastes will determine number of variables for this minimization problem
        //Number of variables will determine the column number in the cost matrix
        fflush(stdin);
        printf("\n  Please enter how many types of wastes are generated daily in your municipality: \n");
        fprintf(file, "\n  ................ User Input ................. \n\n");
        printf("\n  Number of types of waste: ");
        scanf("%d", &column);
        fprintf(file, "\n  Number of types of waste: %d\n", column);
        printf("\n");

        //User won't get every waste from the list printed above. The types will vary according to what type of waste user gets each day
        //So, the type number is stored into 'waste_type[13]' array below.
        printf("  Please enter the type of waste: \n\n");
        fprintf(file, "\n  Waste types are: \n\n");
        for (i = 0; i < column; i++)
        {

            printf("  Type: ");
            scanf("%d", &waste_type[i]);
            fprintf(file, "  Type: ");
            fprintf(file, "%d\n", waste_type[i]);
            fprintf(file, "\n");
            printf("\n");
        }
        //This problem has two constraint functions
        //Taking input of the capacity of the constraints functions below from user
        printf("\n  Please enter the landfill capacity (tons/day):  ");
        scanf("%f", &land_cap);
        fprintf(file, "\n  The landfill capacity (tons/day): %f", land_cap);
        fprintf(file, "\n");

        printf("\n  Please enter the recycling capacity (tons/day):  ");
        scanf("%f", &recycle_cap);
        fprintf(file, "\n  The recycling capacity (tons/day): %f", recycle_cap);
        fprintf(file, "\n");
        fflush(stdin);

        float waste_process_rate[2][13] = {{0.01, 0.01, 0.56, 0.96, 0.82, 0.34, 0.27, 0.90, 0.96, 0.02, 0.86, 0.06, 0.93},
                                           {0.99, 0.99, 0.44, 0.04, 0.18, 0.66, 0.73, 0.10, 0.04, 0.98, 0.14, 0.94, 0.07}};
        for (i = 0; i < 2; i++)
        {
            //i=0 means first constrant equation; i= 1 means second constraint equation
            for (j = 0; j < column; j++)
            {
                matrix[i][j] = waste_process_rate[i][waste_type[j]];
                //storing landfilling coefficients based on waste types into the first constrant equation
                //storing recycling coefficients based on waste types into the second constrant equation
            }
        }

        matrix[0][column] = land_cap;
        matrix[1][column] = recycle_cap;
        //The objective function: The total cost of waste processing, Z= C1X1 + C2X2 + C3X3 + .......... + CNXN; N= Waste type
        //Cost of unit waste processing by waste type (BDT/unit): C1, C2, C3, ......., C13.
        //The cost will be minimized.
        //Taking the unit cost of each type of waste as input from user below
        printf("\n  Please enter the cost of unit waste processing by waste type (BDT/ton): \n\n");
        for (i = 0; i < column; i++)
        {
            printf("  For waste type %d: ", waste_type[i]);
            scanf("%f", &matrix[2][i]); // storing the cost values into the third row of the matrix
            printf("\n");
        }
        fprintf(file, "\n");
        fprintf(file, "\n  The cost of unit waste processing by waste type (BDT/ton): \n");
        for (i = 0; i < column; i++)
        {
            fprintf(file, "\n  For waste type %d: %f \n", waste_type[i], matrix[2][i]);
        }

        //Transposing the matrix
        for (i = 0; i < column + 1; i++)
        {
            for (j = 0; j < 3; j++)
            {
                trans_matrix[i][j] = matrix[j][i];
            }
        }

        //setting up the matrix for iteration 1
        float matrix_new[15][15];
        for (j = 0; j < 2; j++)
        {
            matrix_new[0][j] = -trans_matrix[column][j];
        }
        //putting values to constraints columns
        for (i = 0; i < column; i++)
        {
            for (j = 0; j < 2; j++)
            {
                matrix_new[i + 1][j] = trans_matrix[i][j];
            }
        }
        for (i = 0; i < column + 1; i++)
        {
            matrix_new[i + 1][column + 2] = trans_matrix[i][2];
        }
        //Adding identity matrix
        for (i = 0; i < column + 1; i++)
        {
            for (j = 2; j < column + 2; j++)
            {
                if (j == i + 1)
                {
                    matrix_new[i][j] = 1;
                }
                else
                {
                    matrix_new[i][j] = 0;
                }
            }
        }

        //calling the iteration function
        iteration(matrix_new, column, waste_type);
        printf("\n  File is written successfully \n");
        fclose(file);
        //step 9
    }
}

//User defined function
void iteration(float matrix_new[15][15], int column, int waste_type[13])
{
    int i, j;
    float min = 0;
    int piv_row, piv_col;

    FILE *file;
    file = fopen("Group-6_FINAL_PROJECT_FILE.txt", "a");
    //Finding pivot column
    for (j = 0; j < column + 3; j++)
    {
        if (min > matrix_new[0][j])
        {
            min = matrix_new[0][j];
            piv_col = j;
        }
    }
    //Finding pivot row
    float division[15];
    int m = 1;
    for (i = 1; i < column + 1; i++)
    {
        division[i] = matrix_new[i][column + 2] / matrix_new[i][piv_col];
        m++;
    }

    float min_div = division[1];
    for (i = 1; i < m; i++)
    {
        if (min_div >= division[i])
        {
            min_div = division[i];
            piv_row = i;
        }
    }

    // Calculating new pivot row below
    float iteration1[15][15];
    for (j = 0; j < column + 3; j++)
    {
        iteration1[piv_row][j] = matrix_new[piv_row][j] / matrix_new[piv_row][piv_col];
    }

    //Finding other rows
    for (i = 0; i < column + 1; i++)
    {
        if (i == piv_row)
        {
            continue;
        }

        for (j = 0; j < column + 3; j++)
        {
            iteration1[i][j] = matrix_new[i][j] - (matrix_new[i][piv_col] * iteration1[piv_row][j]);
        }
    }

    int test;
    //step 6
    //Checking if iteration is needed again
    for (j = 0; j < 2; j++)
    {
        if (iteration1[0][j] < 0)
        {
            test = 1;
        }
    }
    //step 7
    if (test == 1)
    {
        //Direct recursion: iteration function calling itself
        iteration(iteration1, column, waste_type);
    }
    //step 8
    else
    {
        float a[13];
        for (i = 0, j = 2; j < column + 2; i++, j++)
        {
            a[i] = iteration1[0][j];
        }

        printf("\n  Total quantity of waste to be processed per day by waste types: \n");
        for (i = 0; i < column; i++)
        {
            printf("\n  Type %d: %f (tons/day).\n", waste_type[i], a[i]);
        }

        fprintf(file, "\n");
        fprintf(file, "\n");
        fprintf(file, "\n  ................ Program Output ................. \n\n");
        fprintf(file, "\n  Total quantity of waste to be processed per day by waste types: \n");

        for (i = 0; i < column; i++)
        {
            fprintf(file, "\n  Type %d: %f (tons/day).\n", waste_type[i], a[i]);
        }

        float c[2];
        c[0] = iteration1[0][column + 2];
        printf("\n  Minimum cost required to process wastes: ");
        printf("%f (BDT/day)", c[0]);
        printf("\n");
        fprintf(file, "\n");
        fprintf(file, "\n  Minimum cost required to process wastes: %f (BDT/day)", c[0]);
        fprintf(file, "\n");
        fprintf(file, "\n");
    }
}
