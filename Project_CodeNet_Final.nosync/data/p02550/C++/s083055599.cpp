#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll MOD = 1000000007;

#define vec              vector<int>
#define vecll            vector<ll>
#define vecd             vector<double>
#define vecst            vector<string>
#define vecb             vector<bool>
#define v2(v,n,m,init)   vector<vector<int>>  v(n, vector<int>(m, init))
#define vb2(v,n,m,init)  vector<vector<bool>> v(n, vector<bool>(m, init))
#define vll2(v,n,m,init) vector<vector<ll>>   v(n, vector<ll>(m, init))

#define rep(i,n)         for(ll i=(ll)0; i<(ll)n; i++)
#define REP(i,m,n)       for(ll i=(ll)m; i<(ll)n; i++)
#define arr(var, n)      vec var(n); rep(i,n){cin >> var[i];}
#define arrll(var, n)    vecll var(n); rep(i,n){cin >> var[i];}
#define arrst(var, n)    vecst var(n); rep(i,n){cin >> var[i];}
#define all(var)         (var).begin(), (var).end()
#define sortall(var)     sort(all(var))
#define uniqueall(v)     v.erase(unique(v.begin(), v.end()), v.end());
#define pb(var)          push_back(var)
#define prt(var)         cout << (var) << "\n"
#define prtd(n, var)     cout << fixed << setprecision(n) << (var) << "\n"
#define prtfill(n, var)  cout << setw(n) << setfill('0') << (var);
#define prt2(v1, v2)     cout << (v1) << " " << (v2) << "\n"
#define prt3(v1, v2, v3) cout << (v1) << " " << (v2) << " " << (v3) << "\n"
#define prtall(v)        rep(i,v.size()){cout<<v[i]<<(i!=v.size()-1?" ":"\n");}
template <typename T>
bool chmax(T &a, const T& b){if(a<b){a=b; return true;} return false;}
template <typename T>
bool chmin(T &a, const T& b){if(a>b){a=b; return true;} return false;}
//------------------------------------------------------------------

int main(void){
  ll n, x, m;
  cin >> n >> x >> m;

  vecll tasu(m);
  rep(i,m){
    tasu[i] = (i*i)%m;
  }
  map<int, int> mp;
  vector<int> v;
  ll nxt=x;
  int ct=0;
  while(1){
    if(mp[nxt]>0) break;
    //prt(nxt);
    v.push_back(nxt);
    ct++;
    mp[nxt]++;
    nxt = (nxt*nxt)%m;
  }

  ll ans=0;
  ll circle=0;
  int chk;
  bool found=false;
  rep(i,v.size()){
    if(n<=0) break;
    if(!found && nxt!=v[i]){
      ans += v[i];
      n--;
    } else if(!found && nxt==v[i]){
      circle += v[i];
      found=true;
      chk=i;
    } else if(found){
      if(nxt==v[i]) break;
      circle += v[i];
    }
  }

  ans += circle * (n/(ct-chk));
  rep(i,n%(ct-chk)){
    ans += v[chk+i];
  }

  prt(ans);


}
