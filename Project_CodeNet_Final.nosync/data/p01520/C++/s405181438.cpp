#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,t,e,a,f=0;
  cin>>n>>t>>e;
  for(int i=0;i<n;i++){
    cin>>a;
    if((t+e)/a*a>=t-e){
      f=1;
      cout<<i+1<<endl;
      break;
    }
  }
  if(!f)cout<<-1<<endl;
  return 0;
}