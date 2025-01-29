/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"

/* Add a prototype for a helper function here if you need */

void split(Node*& in, Node*& odds, Node*& evens)
{
  /* Add code here */
// WRITE YOUR CODE HERE
  if(in == nullptr)//Base Case
  {
    return;
  }

  Node* curr = in;
  in = in -> next;

  if(curr -> value % 2 == 0)//check if next val is even
  {
    curr -> next = evens;
    evens = curr;
  }
  else//if not even then odd
  {
    curr -> next = odds;
    odds = curr;
  }

  split(in, odds, evens);//use recursion for rest of list
}

/* If you needed a helper function, write it here */
