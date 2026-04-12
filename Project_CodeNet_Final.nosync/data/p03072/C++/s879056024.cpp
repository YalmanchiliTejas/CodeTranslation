#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  int m=0;
  int c=0;
  for(int i=0;i<n;i++){
    int h;
    cin>>h;
    if(m<=h){
      c++;
      m=h;
    }
  }
  cout<<c<<endl;
}