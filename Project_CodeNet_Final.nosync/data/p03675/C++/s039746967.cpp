#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  vector<int> A(0),B(0);
  for(int i=0;i<n;i++){
    int a;
    cin>>a;
    if(i%2==0)
      A.push_back(a);
    else
      B.push_back(a);
  }
  vector<int> C(0);
  if(n%2==0){
    reverse(B.begin(),B.end());
    for(int &i:B)
      C.push_back(i);
    for(int &i:A)
      C.push_back(i);
  }else{
    reverse(A.begin(),A.end());
    for(int &i:A)
      C.push_back(i);
    for(int &i:B)
      C.push_back(i);
  }
  for(int i=0;i<n;i++){
    cout<<C[i];
    if(i==n-1)
      cout<<endl;
    else
      cout<<' ';
  }
}