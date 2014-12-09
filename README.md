04_Linked_List_Lab
==================

Implement a simple linked list using pointers and classes.

Requirements
------------

1. Add, remove, get, and set should be O(1) if `i == 0` or if `i == size()-1`
2. Add, remove, get, and set should throw a string exception if `i >= size()`. Find should throw a string exception if `i > size()`
3. Do not leak memory (make sure remove and the destructor do the right thing)
4. `size()` is O(1) time (keep track of the numItems when you add or remove, so you can just return the variable)

Reading
=======
"Open Data Structures," Chapter 3, up through section 2 (DLList), http://opendatastructures.org/ods-cpp/3_Linked_Lists.html

Questions
=========

#### 1. Which of the above requirements work, and which do not? For each requirement, write a brief response.

1. Works, all constant time.
2. Works, says that it is out of bounds.
3. Works, destructor deletes every node properly.
4. Works, just returns numItems.

#### 2. If we did an ArrayList instead of a LinkedList, which of the public methods would be faster, and which would be slower? Explain your answer.
		The add and remove functions would be slower because every time you add one or remove one from the middle of the array, everything that comes after
		it would need to move forward or backwards one. The get and set would be faster though because finding a variable at a specific part of the
		array is really quick.

#### 3. What is one question that confused you about this excercise, or one piece of advice you would share with students next semester?
		My advice is to make sure you know how to properly use pointers before attempting this.
