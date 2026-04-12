#include <bits/stdc++.h>

using namespace std;
#define int int64_t
#define rep(i, a, n) for (int i = (a); i < (n); ++i)
#define reps(i, a, n) for (int i = (a); i < (n); --i)
#define all(x) (x).begin(), (x).end()
#define gsort(x, n) sort((x), (x + n) greater<int>())
#define rv(s) reverse((s).begin(), (s).end())
#define setout(n, x) setw(n) << setfill(x)
#define Fixed(n) fixed << setprecision(n)
#define pb(x, a) (x).push_back(a)
#define fb(x, a) (x).flont_back(a)
#define eb(x, a) (x).emplaes_back(a)
using pii = pair<int, int>;
constexpr int INF = 0x3f3f3f3f;
constexpr long long LINF = 0x3f3f3f3f3f3f3f3fLL;
const long long mod = 1e9 + 7;

signed main()
{
   cin.tie(nullptr);
   ios_base::sync_with_stdio(false);

   int n,cnt;
   cin>>n;
   vector<int> x(n),y;

   rep(i,0,n){
      cin>>x[i];
      y.push_back(x[i]);
   }
   
   sort(all(x));
   cnt = n / 2;

   rep(i,0,n){
      if(y[i] < x[cnt]) cout<<x[cnt]<<'\n';
      else if(y[i] >= x[cnt]) cout<<x[cnt-1]<<'\n';
   }
}