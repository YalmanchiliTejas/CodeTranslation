#include<bits/stdc++.h>
#include<stack>
#include<iostream>
using namespace std;
int main(){
  int n;
  cin>>n;
  stack <char> st[100];
  
  while(1){
    string s;
    cin>>s;
    if(s == "quit") break;
    else if(s == "push"){
      int i;char c;
      cin>>i>>c;
      st[i].push(c);
    }else if(s == "pop"){
      int i;
      cin>>i;
      cout << st[i].top() << endl;
      st[i].pop();
    }else if(s == "move"){
      int in,to;
      cin>>in>>to;
      st[to].push(st[in].top());
      st[in].pop();
    }
  }
}