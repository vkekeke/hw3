#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************
void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot)
{
    if(head == nullptr) { // empty
        smaller = nullptr;
        larger = nullptr;
        return;
    }

    if(head->val <= pivot) { // less than or equal
        smaller = head;
        head = head->next;
        llpivot(head, smaller->next, larger, pivot);
    } else { // greater than
        larger = head;
        head = head->next;
        llpivot(head, smaller, larger->next, pivot);
    }
}

