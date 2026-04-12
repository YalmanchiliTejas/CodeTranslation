#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<queue>
#include<stack>
#include<cassert>
#include<numeric>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
using namespace std;
const int INF = 1001001001;
const long long LINF = 1001002003004005006ll;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
typedef long long ll;
typedef pair<int,int> P;

int main(){
  ll n;
  ll x,m;
  cin >> n >> x >> m;
  ll ans = 0;
  map<int,int> mp;
  vector<int> v;
  rep(i,n){
    if(mp.count(x)==0){
      mp[x]=i;
      ans += x;
      v.push_back(x);
      x = (x*x)%m;
    }else{
      ll sum = 0;
      ll cl = i-mp[x];
      rep(j,cl){
        sum+=v[mp[x]+j];
      }
      ll left = n-i;
      //cout << sum << " " << cl << " " << left << endl;
      ans += (left/cl)*sum;
      left %= cl;
      rep(j,left){
        ans+=v[mp[x]+j];
      }
      cout << ans << endl;
      return 0;
    }
  }
  cout << ans << endl;
  return 0;
}