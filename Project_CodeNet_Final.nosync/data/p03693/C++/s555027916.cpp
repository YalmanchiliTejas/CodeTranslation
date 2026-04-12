///スマホコーディング
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
typedef long long ll;
const int inf=1e9;
int main(){
  string r,g,b;cin>>r>>g>>b;
  r+=g;r+=b;
  int a=stoi(r);
  if(a%4==0)cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
  return 0;
}