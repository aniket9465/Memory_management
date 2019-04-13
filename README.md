# Problem Statement

## Tasks

- Implement the following algorithms in C or C++ without using existing/predefined classes.

  - LRU - Counter Method
  - LRU - Stack Method
  - LRU - Aging Register Method
  - Apprx. LRU - Clock Method

- Compare the contrast the results by testing the algorithms with different corner cases. 

- Draw the graph for the number of frames vs. the number of page faults. 

- Draw the graph for the average time taken to execute the algorithms for different corner cases. 

- Perform the complexity analysis.

- Write your comments/critical analysis/study report on your results and complexity. 

# Solution 
## Code 
All the code for the respective algorithms are in folders by the corresponding name. The code is simply executable after compilation using the command:  

`g++ <file>.cpp -o <file>`

For more insight into using the code, please refer to the [screenshots](Screenshots)

The object code files are also added in the respective directories. The codes for the different algorithms can be found here:
  - [LRU - Counter Method](Counter)
  - [LRU - Stack Method](Stack)
  - [LRU - Aging Register Method](Aging_register)
  - [Apprx. LRU - Clock Method](Clock)

## Test files
The test files are put in the [`Test_files`](Test_files) directory and are generated using the [`test_file_generator.cpp`](Test_files/test_file_generator.cpp) generator 

## Graphs 
The graphs are added in the [`Graphs`](Graphs) directory. They are made using matplotlib in an ipynb notebook found [here](Plot.ipynb)

## Report 
The report file (pdf) is added [here]()

## Group Members
- Aniket Goyal (17114011)
- Bhavye Jain (17114020)
- Kaustubh Trivedi (17114044)
- Roodram Paneri (17114066)
- Saurabh Singh (17114068)
- Twarit Waiker (17114074)
- Shivansh Bindal (17115088)
