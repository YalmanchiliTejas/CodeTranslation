/*   _/                _/                 _/_/_/   _/
  _/_/_/_/   _/_/   _/_/_/_/   _/_/    _/       _/_/
   _/     _/    _/   _/     _/    _/  _/_/_/     _/
  _/     _/    _/   _/     _/    _/  _/    _/   _/
   _/_/   _/_/       _/_/   _/_/      _/_/     _/ */
#include<iostream>
#include<algorithm>
#include<cmath>
#include<iomanip>
#include<set>
#include<map>
#include<queue>
#include<vector>
using namespace std;
using ll=long long;
const int MOD=1e9+7;
const double pi=3.14159265358979323846;
const int inf=2e9;
const ll INF=1e18;
using P=pair<int,int>;
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
int main() {
  cin.tie(0),cout.tie(0);
  ios::sync_with_stdio(false);
  ll a,b,c,x,y,ans=0;
  cin >> a >> b >> c >> x >> y;
  //ABピザの無駄な重複をなくす
  ans+=min(x,y)*min(a+b,c*2);
  if(x-min(x,y)>0) {
    ans+=(x-min(x,y))*min(a,c*2);
  }
  else if(y-min(x,y)>0) {
    ans+=(y-min(x,y))*min(b,c*2);
  }
  cout << ans << "\n";
}