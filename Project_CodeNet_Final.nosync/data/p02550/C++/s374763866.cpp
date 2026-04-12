#ifdef __LOCAL
  #define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
template<typename T> bool chmax(T &a,T b) {if(a<b) {a=b; return true;} return false;}
template<typename T> bool chmin(T &a,T b) {if(a>b) {a=b; return true;} return false;}
#define itn int
#define fi first
#define se second
#define intmax numeric_limits<int>::max()
#define llmax numeric_limits<ll>::max()
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define rrep(i,n) for(int i=(int)(n)-1;i>=0;i--)
#define rrep1(i,n) for(int i=(int)(n);i>=1;i--)
#define all(vec) vec.begin(),vec.end()
#define sortt(vec) sort((vec).begin(),(vec).end())
#define rsort(vec) sort((vec).rbegin(), (vec).rend())
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef tuple<ll,ll,ll> tlll;
typedef tuple<int,int,int> tiii;
const ll mod=1e9+7;
const int inf=1<<30;
const ll lnf=1ll<<60;


int main(){
  ll n,x,m; cin >> n >> x >> m;
  if(x==0||m==1){
    cout << 0 << endl;
    return 0;
  }
  if(x==1){
    cout << n << endl;
    return 0;
  }
  vector<int> v;
  map<int,int> mp;
  vector<int> cycle;
  ll ans=0;
  itn T=n;
  while(T--){
    if(mp.count(x)){
      rep(i,mp[x]) ans+=v[i];
      for(int i=mp[x];i<v.size();i++) cycle.push_back(v[i]);
      break;
    }
    mp[x]=v.size();
    v.push_back(x);
    x=x*x%m;
  }
  if(cycle.empty()){
    rep(i,n) ans+=v[i];
    cout << ans << endl;
    return 0;
  }
  vector<ll> s((cycle.size())+1);
  rep(i,cycle.size()) s[i+1]=s[i]+cycle[i];
  ans+=(n-mp[x])/cycle.size()*s[cycle.size()];
  ans+=s[(n-mp[x])%cycle.size()];
  cout << ans << endl;
}