#include <bits/stdc++.h>
using namespace std;

constexpr int MAX = 500010;

struct Node{
  int key;
  int priority;
  Node* left;
  Node* right;
  Node* p;
};

Node gT[MAX];
Node* gRoot = nullptr;

Node* Delete( Node* t, int key );
Node* _Delete( Node* t, int key );

Node* RotateRight( Node* t ){
  Node* s = t->left;
  t->left = s->right;
  s->right = t;
  return s;
}

Node* RotateLeft( Node* t ){
  Node* s = t->right;
  t->right = s->left;
  s->left = t;
  return s;
}

Node* MakeNode( int k, int p ){
  Node* x = new Node;
  x->key = k;
  x->priority = p;
  x->left = x->right = x->p = nullptr;
  return x;
}

Node* Insert( Node* t, int key, int priority ){
  if( t == nullptr ){
    Node* x;
    return x = MakeNode( key, priority );
  }
  if( key == t->key ){
    return t;
  }

  if( key < t->key ){
    t->left = Insert( t->left, key, priority );
    if( t->priority < t->left->priority ){
      t = RotateRight( t );
    }
  }else{
    t->right = Insert( t->right, key, priority );
    if( t->priority < t->right->priority ){
      t = RotateLeft( t );
    }
  }
  return t;
}

Node* Find( int k ){
  Node* x = gRoot;
  while( x != nullptr ){
    if( k == x->key ) return x;
    if( k < x->key ) x = x->left;
    else x = x->right;
  }
  return nullptr;
}

Node* Delete( Node* t, int key ){
  if( t == nullptr ) return nullptr;
  if( key < t->key ) t->left = Delete( t->left, key );
  else if( key > t->key ) t->right = Delete( t->right, key );
  else return _Delete( t, key );
  return t;
}

Node* _Delete( Node* t, int key ){
  if( t->left == nullptr && t->right == nullptr ) return nullptr;
  else if( t->left == nullptr ) t = RotateLeft( t );
  else if( t->right == nullptr ) t = RotateRight( t );
  else{
    if( t->left->priority > t->right->priority ){
      t = RotateRight( t );
    }else{
      t = RotateLeft( t );
    }
  }
  return Delete( t, key );
}


void Inorder( Node* s ){
  if( s == nullptr ) return;

  Inorder( s->left );
  cout << " " << s->key;
  Inorder( s->right );
}

void Preorder( Node* s ){
  if( s == nullptr ) return;

  cout << " " << s->key;
  Preorder( s->left );
  Preorder( s->right );
}

int main(){
  for( int i = 0; i < MAX; i++ ){
    gT[i].left = gT[i].right = gT[i].p = nullptr;
  }
  
  int m; cin >> m;
  for( int i = 0; i < m; i++ ){
    char cmd[10]; cin >> cmd;
    if( cmd[0] == 'i' ){
      int key, p; cin >> key >> p;
      gRoot = Insert( gRoot, key, p );
    }else if( cmd[0] == 'p' ){
      Inorder( gRoot ); cout << endl;
      Preorder( gRoot ); cout << endl;
    }else if( cmd[0] == 'f' ){
      int key; cin >> key;
      if( Find( key ) != nullptr ) cout << "yes" << endl;
      else cout << "no" << endl;
    }else if( cmd[0] == 'd' ){
      int key; cin >> key;
      gRoot = Delete( gRoot, key );
    }
  }
}

