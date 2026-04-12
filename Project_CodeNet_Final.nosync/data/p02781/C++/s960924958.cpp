#include <bits/stdc++.h>
using namespace std;
#define int long long
string n;int ans,k;
int g(int a,int b){
  int res=1;
  for(int i=0;i<b;i++)res*=a-i;
  for(int i=1;i<=b;i++)res/=i;
  while(b--)res*=9;
  return res;
}
int f(int i,int a){
  int res=0,rem=n.size()-i;
  if(rem<a)return 0;
  if(!a)return 1;
  if(n[i]=='0')return f(i+1,a);
  return f(i+1,a-1)+(n[i]-'1')*g(rem-1,a-1)+g(rem-1,a);
}

signed main(){
  cin>>n>>k;
  cout<<f(0,k)<<endl;
}
