#include<bits/stdc++.h>
using namespace std;

struct node{
  node* l;
  node* r;
  int value;
  int priority;
  node(int x=0,int y=0){
    l=NULL;
    r=NULL;
    value=x;
    priority=y;
  }
};

typedef node* Node;

int cc=0;
node t[500005];

Node MakeNode(int x=0,int y=0){
  Node res=&t[cc];
  cc++;
  res->value=x;
  res->priority=y;
  return res;
}

Node left_rotate(Node root){
  Node right=root->r;
  root->r = right->l;
  right->l = root;
  return right;
}

Node right_rotate(Node root){
  Node left=root->l;
  root->l = left->r;
  left->r = root;
  return left;
}

Node insert(Node root,int val,int pri){
  
  if(root==NULL){
    return MakeNode(val,pri);
  }
  
  if( val < root->value ){
    root->l = insert( root->l , val , pri );

    if( root->l->priority > root->priority ){
      root = right_rotate(root);
    }
    
  }else if( val > root->value ){
    root->r = insert( root->r , val , pri );
    
    if( root->r->priority > root->priority ){
      root = left_rotate(root);
    }
    
  }else{
    
  }
  return root;
}

bool find(Node root,int target){
  if( root == NULL )return false;
  if( root->value == target )return true;
  if( root->value > target )return find(root->l,target);
  if( root->value < target )return find(root->r,target);
  return false;
}

Node erase(Node root,int target){
  if( root == NULL )return root;
  if( root->value == target ){
    
    if( root->l == NULL ){
      return root->r;
    }
    if( root->r == NULL ){
      return root->l;
    }

    if( root->l->priority > root->r->priority ){
      root = right_rotate(root);
    } else {
      root = left_rotate(root);
    }
    return erase(root,target);
  }
  
  if( root->value > target ){
    root->l=erase(root->l,target);
    return root;
  }
  if( root->value < target ){
    root->r=erase(root->r,target);
    return root;
  }

  assert(0);
}

void dfsA(Node root){
  if(root==NULL)return;
  printf(" %d", root->value);
  dfsA(root->l);
  dfsA(root->r);
}

void dfsB(Node root){
  if(root==NULL)return;
  dfsB(root->l);
  printf(" %d", root->value);
  dfsB(root->r);
}

Node T=NULL;

int main(){

  int m;
  scanf("%d",&m);

  char str[100];
  int x,y;
  
  for(int i=0;i<m;i++){
    scanf("%s",str);
    if(str[0]=='i'){
      scanf("%d %d",&x,&y);
      T=insert(T,x,y);
      
    }else if(str[0]=='f'){
      scanf("%d",&x);
      if( find(T,x) )printf("yes\n");
      else printf("no\n");
      
    }else if(str[0]=='d'){
      scanf("%d",&x);
      if( find(T,x) ){
        T=erase(T,x);
      }
      
    }else if(str[0]=='p'){
      dfsB(T);
      printf("\n");
      dfsA(T);
      printf("\n");
      
    }else{
      assert(0);
    }

  }
  return 0;
  /*
  int tmp[10]={3,1,4,5,2,0,6,9,7,8};

  int q;
  cin>>q;
  for(int i=0;i<q;i++){
    int id;
    cin>>id;
    T=insert(T,id, tmp[id] );
  }

  T=erase(T, 7);
  
  dfs(T);
  cout<<endl;
  */

}

