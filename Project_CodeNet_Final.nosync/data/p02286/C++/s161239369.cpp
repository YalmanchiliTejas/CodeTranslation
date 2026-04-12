#include<iostream>
#include<sstream>
using namespace std;

typedef struct Node {
  int key;
  int priority;
  struct Node* right;
  struct Node* left;
} Node_t;

//Node_t* Tree;

///////////////////////////////////////////////////////////////////////////////////////////


Node_t* rightRotate(Node_t* t)
{
  Node_t* s = t->left;
  t->left = s->right;
  s->right = t;
  return s; // root of the subtree
}


Node_t* leftRotate(Node_t* t)
{
  Node_t* s = t->right;
  t->right = s->left;
  s->left = t;
  return s; // root of the subtree
}

Node_t* Node(int k, int p)
{
  Node_t* n;
  n = new Node_t;
  n -> key = k;
  n -> priority = p;
  n -> left = NULL;
  n -> right = NULL;
  return n;
}


Node_t* insert(Node_t* t, int key, int priority)
{
  //cout << "k= " << key << " p= " << priority << endl;

  if (t == NULL)
    {
      return Node(key, priority);               // 葉に到達したら新しい節点を生成して返す

      if( key == t -> key)
	return t;  
    }                               // 重複したkeyは無視

  if (key < t -> key) 
    {                              // 左の子へ移動
      t->left = insert(t->left, key, priority);   // 左の子へのポインタを更新

      if (t->priority < t->left->priority)          // 左の子の方が優先度が高い場合右回転
	t = rightRotate(t);
    }

  else
    {                                       // 右の子へ移動
      t->right = insert(t->right, key, priority); // 右の子へのポインタを更新

      if(t->priority < t->right->priority)         // 右の子の方が優先度が高い場合左回転
	t = leftRotate(t);
    }
  return t;


  
}



Node_t* erase(Node_t* t, int key)
{
  if(t == NULL)
    return NULL;

  if(key == t->key)
    {
      if(t->left == NULL && t->right == NULL )
	return NULL;
    

      else if (t->left == NULL)
	t = leftRotate(t);

      else if (t->right == NULL)
	t = rightRotate(t);

      else
	{
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



void trace_inorder( Node_t *root ) 
{
  if (root == NULL)
    {
      return;
    }
  trace_inorder( root->left ); // 左部分木を探索
  cout << " "<< root -> key; // この部分木の根の記号を出力
  trace_inorder( root->right ); // 右部分木を探索
}


void trace_preorder( Node_t *root ) 
{
  if (root == NULL)
    {
      return;
    }
  cout << " " << root -> key; // この部分木の根の記号を出力
  trace_preorder( root->left ); // 左部分木を探索
  trace_preorder( root->right ); // 右部分木を探索
} 


void print(Node_t* T)
{
  //cout << "print" << endl;
  trace_inorder(T);
  cout << endl;
  trace_preorder(T);
  cout << endl;
}

void find(Node_t* T, int k)
{
  //cout << "find " << k <<endl;
  while (T != NULL) 
    {

      if (T -> key == k)
	{
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



int main()
{
  int qnum;
  cin >> qnum;
  //cout << "q= " << qnum << endl;

  int i, k ,p;
  string s;
  Node_t* Tree=NULL;
  for(i=0; i<qnum; i++)
    {
      cin >> s;

      if(s == "insert")
	{
	  cin >> k >> p;
	  Tree = insert(Tree,k,p);
	  // cout << "hello" << endl;
	}

      else if(s == "print")
	{
	  print(Tree);
	}

      else if(s == "find")
	{
	  cin >> k;
	  find(Tree,k);
	}
      else if(s == "delete")
	{
	  cin >> k;
	  Tree = erase(Tree,k);
	  //print(Tree);
	  //cout << k <<endl;
	}

      else 
	cout << "error" <<endl;
    }

  return 0;
}


