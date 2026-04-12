#include <bits/stdc++.h>
using namespace std;
string n;int ans,k;
int g(int a,int b){
  int res=6;
  while(b--)res*=(a-b)*9,res/=b+1;
  return res/6;
}
int f(int i,int a){
  int rem=n.size()-i;
  return (rem<a?0:!a?1:n[i]=='0'?f(i+1,a):f(i+1,a-1)+(n[i]-'1')*g(rem-1,a-1)+g(rem-1,a));
}

int main(){
  cin>>n>>k;
  cout<<f(0,k)<<endl;
}
