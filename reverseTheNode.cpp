#include <iostream>
using namespace std;

class node {
public:
  int data;
  node *next;

  node(int data) {
    this->data = data;
    this->next = NULL;
  }
};

node *add(node *root) {
  int data;
  cin >> data;
  if (root == NULL) {
    root = new node(data);
    return root;
  }

  node *temp = root;
  while (temp->next != NULL) {
    temp = temp->next;
  }
  temp->next = new node(data);
  return root;
}

void print(node *root) {
  while (root != NULL) {
    cout << root->data << " ";
    root = root->next;
  }
  return;
}

// reverse the node on Linked List

node *reverseTheNode(node *root) {
  if (root == NULL)
    return root;

  node *prev = NULL;
  node *n = NULL;
  node *curr = root;

  while (curr != NULL) {
    n = curr->next;
    curr->next = prev;
    prev = curr;
    curr = n;
  }

  root = prev;

  return root;
}

int main() {
  // your code goes here
  node *root = NULL;
  cout << "Enter number of nodes you want to enter to the linkedlist: ";
  int n;
  cin >> n;

  for (int i = 1; i <= n; i++) {
    root = add(root);
  }
  print(root);
  cout << endl;

  root = reverseTheNode(root);
  print(root);
  cout << endl;

  return 0;
}