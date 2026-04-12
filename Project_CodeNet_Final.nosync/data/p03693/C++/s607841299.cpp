#include <bits/stdc++.h> 

using namespace std;
using ll=long long;
using ull=unsigned long long;
using pii=pair<int,int>;

#define INF LONG_MAX
#define MOD 1000000007
#define rng(a) a.begin(),a.end()
#define rrng(a) a.end(),a.begin()

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int r,g,b;
  cin>>r>>g>>b;
  if((r*100+g*10+b)%4==0)cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
  return 0;
}
