# ECE 370 Linked Lists
The original code was created by me for ECE 370 course. I plan to review the code and make adjustments/improvements.
Assignment details are shown below:
--------------
This program is to implement a number of functions on a linked list.
 
Insertion of a node to a linked list, by given criteria
Deletion of a node on a linked list, by given criteria
Search a node on a linked list, by given criteria
Sorting a linked list, by given criteria
Visit: print out information (name and score) in each and every node on the linked list, from the first node to the last
 
Node structure:
Info Field:                        	Name (only one string, for simplicity)
Score (an integer)
Link: a pointer
 
Insertion criteria:
The linked list insertion is based on alphabetical order of the given names.
If a node on the list has the same name as the one that is to be inserted, then the
existing one is deleted and the new one is inserted.
Deletion criterion
For a given name, delete that name associated node from the linked list, if it exists.
Search criteria:
For a given name, search on the linked list if there is a node that has this name.
If found, print out the node info: Name and Score. One single line for each
searched node.
If not found, print out “not found”.
The search process cannot change any info or node on the list.
Given a criterion, sort the linked in either ascending or descending order.
 
The program reads from a5.txt for actions (insertion, deletion, or search):
%SEARCH, %INSERT, %DELETE, %VISIT, %SORTASC, %SORTDES, %END
 
The “VISIT” command directs the program to print out information (name and score) in each and every node on the linked list, from the first node to the last.
The “SORTASC” is to sort the list according to the scores, in ascending order.
The “SORTDES” is to sort the list according to the scores, in descending order.
The “END” command ends the program running, but not closing the window.
