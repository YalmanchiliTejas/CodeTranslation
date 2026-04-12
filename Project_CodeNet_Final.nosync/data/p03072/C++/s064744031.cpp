#include<bits/stdc++.h>
using namespace std;
int n,A[1000001],i,c,mx;
int main(){
  cin>>n;
  cin>>A[0];
  mx=A[0];
  for(i=1;i<n;i++){
    cin>>A[i];
   if(A[i]>=mx){
     mx=A[i];
     c++;}}
  cout<<c+1;}