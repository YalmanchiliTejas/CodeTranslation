#include <bits/stdc++.h>

using namespace std;

char v[5];

int main(){
  cin>>v;
  
  if(v[0]==v[1] && v[1]==v[2])
    cout<<"No";
  else
    cout<<"Yes";
  
  return 0;
}
