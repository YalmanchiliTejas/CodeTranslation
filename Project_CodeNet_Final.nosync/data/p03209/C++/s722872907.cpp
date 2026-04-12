#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,d,c;
ll p[51],b[51],pb[51];
void dfs(ll i,ll j){
  if(i==j){
  }else if(i==1){
    if(j==2)
      c++;
    else if(j==3)
      c+=2;
    else if(j>3)
      c+=3;
  }else if(j<=pb[i-1]+1)
    dfs(i-1,j-1);
  else if(j==pb[i-1]+2)
    c+=p[i-1]+1;
  else{
    if(i==1)
      c+=3;
    else{
      c+=p[i-1]+1;
      dfs(i-1,j-pb[i-1]-2);
    }
  }
}
int main(){
  cin>>n>>d;
  p[0]=1;
  b[0]=0;
  pb[0]=p[0]+b[0];
  for(ll i=1;i<=50;i++){
    p[i]=p[i-1]*2+1;
    b[i]=b[i-1]*2+2;
    pb[i]=p[i]+b[i];
  }
  dfs(n,d);
  cout<<c<<endl;
}