#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,a[100];
  cin>>n;
  cin>>a[0];
  int m=a[0],cn=1;
  for(int i=1;i<n;i++){
    cin>>a[i];
    if(m<=a[i]){
      cn++;
      m=a[i];
    }
  }
  cout<<cn<<endl;
}