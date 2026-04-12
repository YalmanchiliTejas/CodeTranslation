#include<bits/stdc++.h>
using namespace std;
#define MAX_N 100005
int N,Q;
bool t[MAX_N];
bool u[MAX_N];

int main(){
  cin>>N>>Q;
  
  t[1]=true;
  u[1]=u[2]=true;
  for(int i=0;i<Q;i++){
    int a,b;
    cin>>a>>b;

    if(t[a-1]||t[a+1]){
      u[b]=true;
    }
    if(t[b-1]||t[b+1]){
      u[a]=true;
    }
    
    swap(t[a],t[b]);
    swap(u[a],u[b]);
    if(t[a])u[a-1]=u[a]=u[a+1]=true;
    if(t[b])u[b-1]=u[b]=u[b+1]=true;
  }

  int ans=0;
  for(int i=1;i<=N;i++){
    if(u[i]){
      ans++;
      //      cout<<i<<endl;
    }
    
  }
  cout<<ans<<endl;
  
  return 0;
}
