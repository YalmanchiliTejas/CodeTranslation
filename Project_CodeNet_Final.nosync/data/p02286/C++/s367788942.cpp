#include <iostream>
#include <sstream>
#include <cstdio>
#include <stdlib.h>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct node{
  int key ;
  int priority;
  int right;
  int left;
  long unsigned int p;
};
node nullNode{-1,-1,0,0,0};
int _nodeDelete(node,int);
int nodeDelete(node,int);
vector <node> treap;
bool isNull(node t){
  //if(&t ==nullptr) return true;
  if(t.key ==-1 && t.priority == -1)return true;
  return false;
}
int rightRotate(node t){
  long unsigned int s = t.left;
  treap[t.p].left = treap[s].right;
  treap[s].right = t.p;
  return s;
}
int leftRotate(node t){
  long unsigned int s = t.right;
  treap[t.p].right = treap[s].left;
  treap[s].left = t.p;
  return s;
}
int mkNode(int key,int priority){
  node s = {key,priority,0,0,treap.size()};
  treap.push_back(s);
  return s.p;
}
int insert(node t,int key, int priority){
  int tmp;
  if(isNull(t))return mkNode(key,priority);
  if(key == t.key)return t.p;
  if(key < t.key){
    tmp = insert(treap[t.left],key,priority);
     treap[t.p].left =tmp;
     if(t.priority < treap[tmp].priority)
      t = treap[rightRotate(treap[t.p])];
  }
  else {
    tmp= insert(treap[t.right],key,priority);
    treap[t.p].right = tmp;
    if(t.priority < treap[tmp].priority)
      t = treap[leftRotate(treap[t.p])];
  }
  return t.p;
}
int nodeDelete(node t,int key){
  int tmp;
  if(isNull(t))return 0;
  if(key < t.key){
    tmp = nodeDelete(treap[t.left],key);
    treap[t.p].left = tmp;
  }
  else if (key > t.key){
    tmp = nodeDelete(treap[t.right], key);
    treap[t.p].right = tmp;
  }
  else
    return _nodeDelete(t, key);
  return t.p;
}
int _nodeDelete(node t,int key){
  int tmp;
  if (isNull(treap[t.left]) && isNull(treap[t.right]))        
        return 0;
  else if (isNull(treap[t.left])){
    tmp = leftRotate(t);
      t = treap[tmp];
    }                       
    else if (isNull(treap[t.right])){                   
      tmp =rightRotate(t);
      t = treap[tmp];
    }
    else{                                       
        if (treap[t.left].priority > treap[t.right].priority ){
          tmp = rightRotate(t);
          t = treap[tmp];
        } 

        else{
          tmp =leftRotate(t);
          t = treap[tmp];
        }
    }
  return nodeDelete(t, key);
}
void preorder_print(node t){
  if(isNull(t))return;
  cout<<" "<<t.key;
  preorder_print(treap[t.left]);
  preorder_print(treap[t.right]);
}
void inorder_print(node t){
  if(isNull(t))return;
  inorder_print(treap[t.left]);
  cout<<" "<<t.key;
  inorder_print(treap[t.right]);
}
bool find(node t, int key){
  bool flag = false;
  if(t.key ==-1);
  else if(key==t.key) flag = true;
  else if(key>(t.key))flag = find(treap[t.right],key);
  else if(key<(t.key)) flag = find(treap[t.left],key);
  return flag;
}
int main(){
  int n,key,p;
  bool flag=false;
  string str;
  int root;
  cin>>n;
  treap.push_back(nullNode);
  for(int i=0;i<n;i++){
    cin>>str;
    if(str=="insert"){
      cin>>key>>p;
      if(flag)
        root = insert(treap[root],key,p);
      else{
        root = mkNode(key,p);
        flag = true;
      }
    }
    else if (str=="print"){

      inorder_print(treap[root]);
      cout<<endl;
      preorder_print(treap[root]);
      cout<<endl;
    }
    else if (str == "delete"){
      cin >> key;
      root = nodeDelete(treap[root],key);
    }
    else if (str == "find"){
      cin>>key;
      if(find(treap[root],key))cout<<"yes"<<endl;
      else cout<<"no"<<endl;
    }
   }


  return 0;
}

