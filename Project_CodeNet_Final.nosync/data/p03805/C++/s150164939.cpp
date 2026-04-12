#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll MOD = 1e9+7;

#define vec     vector<int>
#define vecll   vector<ll>
#define vec2    vector<vector<int>>
#define vec2ll  vector<vector<ll>>
#define vpair   vector<pair<int, int>>
#define vpairll vector<pair<ll, ll>>
#define vecst   vector<string>
#define vecb    vector<bool>

#define rep(i,n)         for(ll i=(ll)0; i<(ll)n; i++)
#define REP(i,m,n)       for(ll i=(ll)m; i<(ll)n; i++)
#define arr(var, n)      vec var(n); rep(i,n){cin >> var[i];}
#define arrll(var, n)    vecll var(n); rep(i,n){cin >> var[i];}
#define arrst(var, n)    vecst var(n); rep(i,n){cin >> var[i];}
#define all(var)         (var).begin(), (var).end()
#define sortall(var)     sort(all(var))
#define uniqueall(v)     v.erase(unique(v.begin(), v.end()), v.end());
#define f_sum(var)       accumulate(all(var), 0)
#define f_sumll(var)     accumulate(all(var), 0LL)
#define chmin(v1, v2)    v1 = min(v1, v2)
#define chmax(v1, v2)    v1 = max(v1, v2)
#define mpair(v1, v2)    make_pair(v1, v2)
#define pb(var)          push_back(var)
#define prt(var)         cout << (var) << "\n"
#define prtd(n, var)     cout << fixed << setprecision(n) << var << "\n"
#define prtfill(n, var)  cout << setw(n) << setfill('0') << var;
#define prt2(v1, v2)     cout << v1 << " " << v2 << "\n"
#define prt3(v1, v2, v3) cout << v1 << " " << v2 << " " << v3 << "\n"
#define prtall(v)        rep(i,v.size()){cout<<v[i]<<(i!=v.size()-1?" ":"\n");}
void prtok(bool ok){prt((ok ? "YES" : "NO"));}
//----------------------------------------------------------------
int divi[1001];

int main(void) {
  int n, m;
  cin >> n >> m;

  bool cango[n][n];
  rep(i,n){
    rep(j,n){
      cango[i][j]=false;
    }
  }

  rep(i,m){
    int a, b;
    cin >> a >> b;
    a--; b--;
    cango[a][b]=true;
    cango[b][a]=true;
  }

  vec v;
  rep(i,n-1){
    v.pb(i+1);
  }

  int ans=0;
  do {
    rep(i,v.size()){
      int from, to;
      if(i==0) from=0;
      else from=v[i-1];
      to=v[i];
      if(!cango[from][to]) break;
      if(i==v.size()-1) ans++;
    }
  } while (next_permutation(all(v)));

  prt(ans);
}
