#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int a,b,c;
  cin>>a>>b>>c;
  int sum=0;
  sum+=(a*100)+(b*10)+(c*1);
  //cout<<sum<<endl;
  if(sum%4==0) cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
  return 0;
}
