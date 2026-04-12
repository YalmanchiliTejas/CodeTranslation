#include<bits/stdc++.h>
using namespace std;
#define dbg_var(x) cout << #x << ": " << x << endl;
#define forn(i,a,b)for(int i=a;i<=b;++i)
template <typename T>
void dbg_vector(const T& v)
{
  for (size_t i = 0; i < v.size(); ++i) cout << v[i] << " ";
  cout << endl;
}
void dbg() { cerr << endl; }
template <typename Head, typename... Tail>
void dbg(Head H, Tail... T)
{
  cerr << H << ' ';
  dbg(T...);
}
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
struct pair_hash {
    template <class T1, class T2>
    size_t operator () (const pair<T1,T2> &p) const {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);

        return h1 ^ h2;
    }
};
inline ll lmin(ll a,ll b){if(a<b)return a;return b;}
inline ll lmax(ll a,ll b){if(a>b)return a;return b;}
inline ll labs(ll a){if(a<0)return -a;return a;}
const ll INF=1e18;
const ll P_HASH=31;
const ll MOD=1e9+7;
const ld EPS=1e-8;

int main()
{
  /*freopen("input.txt","w",stdout);
  cout<<300000<<" "<<300000<<endl;
  for(int i=1;i<=299999;++i)
  {
    cout<<i<<" "<<i+1<<endl;
  }
  return 0;*/
  //freopen("input.txt","r",stdin);
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int x;cin>>x;
  if(x==7||x==5||x==3)cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
}

/*

*/
