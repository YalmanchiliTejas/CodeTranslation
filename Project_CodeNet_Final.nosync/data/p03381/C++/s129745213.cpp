#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
  int i,j,cnt=0;
  int n;
  cin>>n;
  int x[n];
  for(i=0;i<n;i++)cin>>x[i];
  int y[n];
  for(i=0;i<n;i++)y[i]=x[i];
  sort(y,y+n);
  int mi=y[n/2-1],ma=y[n/2];
  for(i=0;i<n;i++){
    if(x[i]<=mi)cout<<ma<<endl;
    else cout<<mi<<endl;
  }
}