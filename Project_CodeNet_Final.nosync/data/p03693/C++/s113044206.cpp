#include <bits/stdc++.h>
using namespace std;

int main() {
  string a,b,c;
  cin>>a>>b>>c;
  string rgb=a+b+c;
  int abc=stoi(rgb);
  if(abc % 4==0){
    cout<<"YES"<<endl;
  }
  else{
    cout<<"NO"<<endl;
  }
}
