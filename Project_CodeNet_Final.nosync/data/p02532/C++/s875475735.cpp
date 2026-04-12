#include<iostream>
#include<stack>
#include<queue>
using namespace std;
stack <string> st[101];
queue <string> qu;
int n,c,d;
string a,b;
int main(){
  while(1){
    cin>>a;
    if(a=="quit")break;
    if(a=="pop"){
      cin>>c;
      qu.push(st[c].top());
      st[c].pop();
    }
    if(a=="push"){
      cin>>c>>b;
      st[c].push(b);
    }
    if(a=="move"){
      cin>>d>>c;
      st[c].push(st[d].top());
      st[d].pop();
    }
  }
  while(!qu.empty()){
    cout<<qu.front()<<endl;
    qu.pop();
  }
  
  return 0;
}