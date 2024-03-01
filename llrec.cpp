#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************


void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot){
  
  if(head == NULL){
    smaller = NULL;
    larger = NULL;
    return;
  }

  Node* temp = head->next;

  if(head->val > pivot){

    larger = head;
    llpivot(temp,smaller,larger->next,pivot);
  }
  else{

    smaller = head;
    llpivot(temp,smaller->next,larger,pivot);
  }
  head = NULL;
  
  
  

}