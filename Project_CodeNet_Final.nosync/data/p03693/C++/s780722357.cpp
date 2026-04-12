#include<bits/stdc++.h>
using namespace std;

int main(){
  int a,b,c;
  cin >>a>>b>>c;
  if((100*a+b*10+c)%4==0)
  cout <<"YES"<<endl;
  else
    cout<<"NO"<<endl;
  return 0;
}