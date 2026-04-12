#include<bits/stdc++.h>
using namespace std;

int main(){
int a,b,c;
  cin>>a>>b>>c;
  int d=b+c;
  if(a%d<c)
    cout<<a/d-1<<endl;
  else
    cout<<a/d<<endl;
}
