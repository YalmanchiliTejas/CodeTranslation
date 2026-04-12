#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
  int x,y;
  cin>>x>>y;
  string s;
  int z=0;
  for(int i=0;i<x;i++){
    cin>>s;
    for(int j=0;j<y;j++){
      if(s[j]=='#'){
        z++;
      }
    }
  }
  if(z==x+y-1){
    cout<<"P";
  }
  else{
    cout<<"Imp";
  }
  cout<<"ossible"<<endl;
}