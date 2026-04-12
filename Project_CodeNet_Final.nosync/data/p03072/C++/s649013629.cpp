#include <bits/stdc++.h>
using namespace std;
int main (){
  int n;
  cin>>n;
  int h[n];
  int i,x,m=0,c=0;
  for(i=0;i<n;i++){
    cin>>x;
    if(m<=x){
      m=x;
      c++;
    }
  }
  cout<<c;
}
      
    