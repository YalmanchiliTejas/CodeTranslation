#include<iostream>
#include<sstream>
using namespace std;

typedef struct Node {
  int key,priority;
  struct Node* right;
  struct Node* left;
} Node_t;

Node_t* rightRotate(Node_t* t){
  Node_t* s = t->left;
  t->left = s->right;
  s->right = t;
  return s;
}


Node_t* leftRotate(Node_t* t){
  Node_t* s = t->right;
  t->right = s->left;
  s->left = t;
  return s;
}

Node_t* Node(int k, int p){
  Node_t* n;
  n = new Node_t;
  n -> key = k;
  n -> priority = p;
  n -> left = NULL;
  n -> right = NULL;
  return n;
}


Node_t* insert(Node_t* t, int key, int priority){


  if (t == NULL){
      return Node(key, priority);
    }
  if( key == t -> key)return t;
  if (key < t -> key){
      t->left = insert(t->left, key, priority);
      if (t->priority < t->left->priority)
	     t = rightRotate(t);
     }

  else{
      t->right = insert(t->right, key, priority);
      if(t->priority < t->right->priority)
	     t = leftRotate(t);
     }
  return t;
}



Node_t* erase(Node_t* t, int key){
  if(t == NULL)
    return NULL;

  if(key == t->key){
      if(t->left == NULL && t->right == NULL )
	return NULL;


      else if (t->left == NULL)
	t = leftRotate(t);

      else if (t->right == NULL)
	t = rightRotate(t);

      else{
	  if(t->left->priority > t->right->priority)
	    t = rightRotate(t);

	  else
	    t = leftRotate(t);
	}

      return erase(t,key);

    }

  if(key < t->key)
    t->left = erase(t->left,key);

  else
    t->right = erase(t->right,key);

  return t;
}



void traceInOrder( Node_t *root ){
  if (root == NULL){
      return;
    }
  traceInOrder( root->left );
  cout << " "<< root->key;
  traceInOrder( root->right );
}


void tracePreOrder( Node_t *root ){
  if (root == NULL){
      return;
    }
  cout << " " << root->key;
  tracePreOrder( root->left );
  tracePreOrder( root->right );
}


void print(Node_t* T){
  traceInOrder(T);
  cout << endl;
  tracePreOrder(T);
  cout << endl;
}

void find(Node_t* T, int k){
  while (T != NULL){
      if (T->key == k){
	cout << "yes"<<endl;
	return;
	}

      else if (k < T -> key)
	T = T -> left;
      else
	T = T -> right;
    }
  cout << "no" << endl;
}



int main(){
  int num;
  cin >> num;
  int i, k ,p;
  string s;
  Node_t* Tree=NULL;
  for(i=0; i<num; i++){
      cin >> s;

      if(s == "insert"){
	  cin >> k >> p;
	  Tree = insert(Tree,k,p);
	}

      else if(s == "print"){
	  print(Tree);
	}

      else if(s == "find"){
	  cin >> k;
	  find(Tree,k);
	}
      else if(s == "delete"){
	  cin >> k;
	  Tree = erase(Tree,k);
	}

      else
	cout << "error" <<endl;
    }

  return 0;
}

