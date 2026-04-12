#include<bits/stdc++.h>
using namespace std;
int main(){
  string a;
  cin>>a;
  bool a01=0,a02=0,a12=0;
  if(a[0]!=a[1]||(a[0]!=a[2]&&a[1]==a[0]))a01=1;
  if(a[0]!=a[2]||(a[0]!=a[1]&&a[2]==a[0]))a02=1;
  if(a[1]!=a[2]||(a[2]!=a[0]&&a[1]==a[2]))a12=1;
  if(a01&&a02&&a12) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}
