#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i, a, n) for (ll i = (ll)a; i < (ll)n; i++)
#define RFOR(i, a, n) for (ll i = (ll)n - 1; i >= (ll)a; i--)
#define rep(i, n) FOR(i, 0, n)
#define rrep(i, n) RFOR(i, 0, n)
#define ALL(v) v.begin(), v.end()
#define bra(first, second) '(' << first << ',' << second << ')'
//constexpr ll MOD = 1000000007;
constexpr ll MOD = 998244353;
ll INF = 1001001001001001001;
long double EPS = 1e-9;
long double PI = 3.141592653589793238;
template <typename T>
void remove(std::vector<T> &vector, unsigned int index)
{
   vector.erase(vector.begin() + index);
}

using Graph = vector<vector<pair<ll,ll>>>;

// MOD確認

ll N,X,M;
ll m[200010];
ll ind[200010];

int main(){
   cin >> N >> X >> M;
   m[0] = X;
   ll flag = 0;
   rep(i,2*M){
      m[i+1] = (m[i] * m[i]) % M;
      if(flag == 0 && m[i+1] == 0) flag = i + 1;
   }
   ll num = 0,sum = 0;
   ll l = 0,r = 0;
   rep(i,2*M) ind[i] = -1;
   rep(i,2*M){
      if(ind[m[i]] != -1){
         r = i;
         l = ind[m[i]];
         num = r - l;
         break;
      }
      ind[m[i]] = i;
   }
   FOR(i,l,r) sum += m[i];
   //cout << l << ' ' << r << endl;
   //cout << m[l] << ' ' << m[r] << endl;
   ll ans = 0;
   if(flag){
      rep(i,min(N,flag)){
         ans += m[i];
      }
      cout << ans << endl;
      return 0;
   }
   rep(i,min(l,N)) ans += m[i];
   rep(i,(N - l) % num) ans += m[i+l];

   ans += sum * ((N - l) / num);
   cout << ans << endl;
}