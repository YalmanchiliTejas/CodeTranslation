#include <bits/stdc++.h>
using namespace std;
#define reps(i,s,n) for(int i = s; i < n; i++)
#define rep(i,n) reps(i,0,n)
#define Rreps(i,n,e) for(int i = n - 1; i >= e; --i)
#define Rrep(i,n) Rreps(i,n,0)
#define ALL(a) a.begin(), a.end()
#define fi first
#define se second
#define endl "\n"
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;

//const ll MOD = 998244353;
const ll MOD = (1e+9) + 7;
const ll INF = 2e+9 + 10;
typedef pair<ll, ll> P;


int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int r,g,b; cin >>r>>g>>b;
  int num = 100*r+10*g+b;
  if(num%4 == 0) cout << "YES" <<endl;
  else cout << "NO" << endl;

  return 0;
}