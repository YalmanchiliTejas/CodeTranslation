#include<bits/stdc++.h>
#define int long long 
#define rap(i,n) for(int i=0;i<n;i++)
using namespace std;
signed main(){
  string a,b,c;
  int n;
  cin>>a>>b>>c;
a = a + b + c;
n =std::stoi(a);
if(n%4==0){
  cout<<"YES\n";
}else{
  cout<<"NO\n";
}
}
