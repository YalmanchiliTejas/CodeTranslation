#include<bits/stdc++.h>
using namespace std;
#define r(i,n) for(int i=0;i<n;i++)
#define fi first
#define se second
#define mk make_pair
int main(){
  int n,t=0,x=0;
  cin>>n;
  int a[n];
  r(i,n)cin>>a[i];
  for(int i=n-1;i>=0;i-=2){
    if(t++)cout<<' ';
    cout<<a[i];
    if(i==0)x++;
  }
  for(int i=x;i<n;i+=2){
    if(t++)cout<<' ';
    cout<<a[i];
  }cout<<endl;
}