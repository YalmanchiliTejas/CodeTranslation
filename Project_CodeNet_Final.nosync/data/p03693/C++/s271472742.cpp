#include<bits/stdc++.h>
using namespace std;
int main(){
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  int a,b,c;
  cin>>a>>b>>c;
  int sum=a*100+b*10+c;
  if(sum%4==0) cout<<"YES"<<'\n';
  else cout<<"NO"<<'\n';
  return 0;
}
