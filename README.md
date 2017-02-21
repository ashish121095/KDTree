Purpose of this Project
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Implement KD tree and some basic operation of data structure to find all places within passed distance in real world (e.g.  find all gas station around 5 miles of your current location)

Requirements
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Object-oriented programming concepts in C++, Use and apply inheritance in C++, Design, implement, and use a K-D tree data structure,
Analyze operations for time complexity and space complexity of a data structure

About Project
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
I had to choose C++ as it was requirement for this project. C++ is very popular for object oriented programming and that's what
I had to use. I had used General Tree Data Structure to achieve desire result in this project. I have implemented K-D tree using
general tree data structure. I have created a tree data structure which contains an array of user desired size as a node’s field 
and contains one left and one right pointer. I have implemented insert, find, range Query and size functions for simplicity of 
this project. Insert function simply insert new node based on the size of an array field. Smaller array size of nodes would be 
inserted on the left side of the parent node and larger array size of nodes would be inserted on the right side of the parent node.
Find function finds an element with passed coordinates. Range query function find all possible elements within the range of passed
coordinates which is helpful to find all possible places in real world. Size function returns the size of the general tree. This 
project was also implemented on the basis of complexity. It maintains O(log n) complexity of KD Tree data structure.

