#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
using namespace std;
#define reps(i,s,n) for(int i = s; i < n; i++)
#define rep(i,n) reps(i,0,n)
#define Rreps(i,n,e) for(int i = n - 1; i >= e; --i)
#define Rrep(i,n) Rreps(i,n,0)
#define ALL(a) a.begin(), a.end()
#define endl "\n"
typedef long long ll;
#define traceV(v) for(auto x:v)cout<<x<<" ";cout<<endl
#define traceM(mp) for(auto x:mp)cout<<x.first<<" "<<x.second<<endl

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll A,B,C,X,Y; cin>>A>>B>>C>>X>>Y;

  ll res = 10000000000;
  for(ll i=0; i<=max(X,Y); ++i) {     // i: ABの枚数*2
    ll a = max(X-i, 0LL);              // 必要なAの枚数
    ll b = max(Y-i, 0LL);              // 必要なBの枚数

    ll sum = A*a + B*b + C*(2*i);

    res = min(res, sum);
  }

  cout << res << endl;

  return 0;
}
