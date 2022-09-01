# Calculating Optimum	Cost of Managing	Different	Wastes	of	Any Municipality	of Bangladesh	Using	C	Program

**Problem Statement:**

<p align="justify">Poor  waste  management  is  a  crucial  problem  in  Bangladesh. Every  day,  the  amount  of household, industrial, medical, electronic, and other wastes are increasing. More than half of these wastes are dumped in open spaces illegally without proper treatment, which is threatening for both environment and public health. So, the authority wants to improve the current solid waste management (SWM) system in a way where different wastes will be treated differently, and the management of all wastes will be cost-effective. The authority wants to develop a system that can determine quantities of different types of wastes that are to be processed, when the management capacities and unit costs for each types of wastes are provided. With the help of this system, any municipality can determine the daily quantity of wastes it wants to process.</p>  

**Objective:**

<p align="justify">To develop a C program for any area (for instance, a municipality of Bangladesh) to determine the total amount of processed wastes based on their type, and the minimum cost to manage these wastes effectively considering the resource constraints.</p>

**Input:**

**Types of waste generated per day:** 
<p align="justify">Type 0 = Construction & Demolition, Type 1 = Metal, Type 2 = Paper/Cardboard,  Type 3 = Plastics, Type 4 = Food, Type 5 = Wood, Type 6 = Horticultural, Type 7 = Ash & Sludge, Type 8 = Textile/Leather, Type 9 = Used Slag, Type 10 = Glass, Type 11 = Scrap Tyres, Type 12 = Others (stones, ceramic, rubber, etc.)</p>

**Maximum capacity of nearby Landfill Site & Recycling Plant (tons/day):**  
**Unit cost of waste processing based on each waste type (BDT/ton):** 

**Output:**

**Total amount of processed wastes (tons/day):**  

**Minimum cost required to manage different wastes (BDT/ day):**

**Constants:**

**Percentage contribution of waste to different distribution centers:** 



|**Type** |**Waste Type** |**Recycling Rate (R)** |**Disposal Rate after Treatment (L)** |
| - | - | :-: | :-: |
|0 |Construction& Demolition |99% |1% |
|1 |Metal |99% |1% |
|2 |Paper/Cardboard |44% |56% |
|3 |Plastics |4% |96% |
|4 |Food |18% |82% |
|5 |Wood |66% |34% |
|6 |Horticultural |73% |27% |
|7 |Ash & Sludge |10% |90% |
|8 |Textile/Leather |4% |96% |
|9 |Used Slag |98% |2% |
|10 |Glass |14% |86% |
|11 |Scrap Tyres |94% |6% |
|12 |Others (stones, ceramic, rubber, etc.) |7% |93% |
Source: *Waste Statistics and Overall Recycling (2020).*

**Workflow:**

**Step 1:** _User inputs:_ <p align="justify">Number of waste types to be processed (n) and the types (Type 1 = Construction & Demolition, Type 2 = Metal, Type 3 = Paper/Cardboard, Type 4 = Plastics, Type 5 = Food, Type 6 = Wood, Type 7 = Horticultural, Type 8 = Ash & Sludge, Type 9 = Textile/Leather, Type 10 = Used Slag, Type 11 = Glass, Type 12 = Scrap Tyres, Type 13 = Others (stones, ceramic, rubber, etc.). This determines the number of decision variables in the constraint and objective function equations. Here in this problem, the type of waste is limited up to 13. The decision variables will be:</p>

X<sub>1</sub> , X<sub>2</sub> , X<sub>3</sub> ....... X<sub>N</sub>; N= Total number of types of wastes = 13.

**Step 2:** _User input:_ <p align="justify">Landfill capacity (unit/day), recycling plant capacity (unit/day). This will determine the constraint limits for landfill disposal and recycling.</p>

<p align="justify">L<sub>1</sub>X<sub>1</sub> + L<sub>2</sub>X<sub>2</sub> + L<sub>3</sub>X<sub>3</sub> + .......... + L<sub>N</sub>X<sub>N</sub> <= Landfill Capacity; L = Percentage of each type of waste to be processed for landfill which is constant and is fixed in the equation.</p>

<p align="justify">R<sub>1</sub>X<sub>1</sub> + R<sub>2</sub>X<sub>2</sub> + R<sub>3</sub>X<sub>3</sub> + .......... + R<sub>N</sub>X<sub>N</sub> <= Recycling Capacity; R = Percentage of each type of waste to be processed by recycling which is constant and is fixed in the equation.</p>

**Step 3:** _User input:_ <p align="justify">Cost of unit waste processing by waste type (BDT/unit): C<sub>1</sub>, C<sub>2</sub>, C<sub>3</sub>.......C<sub>N</sub>. This will determine the objective function. The cost will be minimized.</p>

<p align="justify">Total cost of waste processing, Z = C<sub>1</sub>X<sub>1</sub> + C<sub>2</sub>X<sub>2</sub> + C<sub>3</sub>X<sub>3</sub> + .......... + C<sub>N</sub>X<sub>N</sub></p>

**Step 4:** <p align="justify">After determining the number of decision variables, constraint equations and objective function based on user input, the optimization problem will be solved.</p>

**_Output:_** 
X<sub>1</sub> = Total quantity of type 1 waste to be processed (unit/ day),
X<sub>2</sub> = Total quantity of type 2 waste to be processed (unit/ day),
X<sub>3</sub> = Total quantity of type 3 waste to be processed (unit/ day),
.
.
X<sub>N</sub> = Total quantity of type N waste to be processed (unit/ day).
Z = Minimize waste treatment cost (BDT/day).

**Sample:**

<p align="justify">For example, let’s say 3 types of wastes are to be processed in a municipality. The three types of waste that have been found are: food waste, paper waste and metal waste.</p>

**_User Inputs_:**
**Maximum capacity of nearby Landfill Site & Recycling Plant:**

Landfill Site: 1800 tons/day
Recycling Plant: 475 tons/day

**Unit cost of waste processing based on waste type (BDT/ton):**

A<sub>2</sub> = 3900 BDT/ton of metal waste to be processed

A<sub>3</sub> = 3000 BDT/ton of paper waste to be processed

A<sub>5</sub> = 3200 BDT/ton of food waste to be processed

**Types of waste generated per day:**

<p align="justify">Number, n = 3. Types: Type 2, Type 3, Type 5. This will determine the number of decision variable. For this sample example, there will be 3 decision variables X<sub>2</sub> , X<sub>3</sub> , X<sub>5</sub> which are:</p>

X<sub>2</sub> = Total quantity of metal waste to be processed per day

X<sub>3</sub> = Total quantity of paper waste to be processed per day

X<sub>5</sub> = Total quantity of food waste to be processed per day

**Constraints:**

For recycling, the constraint is:

0.18X<sub>2</sub> + 0.99X<sub>2</sub> + 0.44X<sub>5</sub> <= 475

For landfill disposal, the constraint is:

0.82X<sub>2</sub> + 0.1X <sub>3</sub>+ 0.56X<sub>5</sub> <= 1800

**_Output_:**

Minimize waste treatment cost (BDT/day), Z= (A<sub>2</sub>X<sub>2</sub> + A<sub>3</sub>X<sub>3</sub> + A<sub>5</sub>X<sub>5</sub> ) = (3900X<sub>2</sub> + 3000X<sub>3</sub> + 3200X<sub>5</sub>)

Total amount of processed wastes (tons/day)


**Reference:**

<p align="justify">_Waste Statistics and Overall Recycling_. (2020). Retrieved from https://www.nea.gov.sg/our-services/waste-management/waste-statistics-and-overall-recycling</p>
