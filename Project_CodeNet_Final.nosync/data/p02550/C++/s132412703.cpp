#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, from, to) for (ll i = from; i < (to); ++i)
#define mp(x,y) make_pair(x,y)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define pb push_back
using ll = long long;
using ld=long double;
using vin=vector<int>;
using vvin=vector<vin>;
using vll=vector<ll>;
using vvll=vector<vll>;
using vst=vector<string>;
using P = pair<ll,ll>;
const int inf=998244353;
const ll INF=9e18;
const long double PI = acos(-1.0);
template <typename T> bool chmin(T &a, const T& b){if(a > b){a = b;return true;}return false;}
template <typename T> bool chmax(T &a, const T& b){if(a < b){a = b;return true;}return false;}
template<class T> inline void Yes(T condition){ if(condition) cout << "Yes" << endl; else cout << "No" << endl; }
template<class T> inline void YES(T condition){ if(condition) cout << "YES" << endl; else cout << "NO" << endl; }
const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };

ll sum[110000];

int main(){cout<<fixed<<setprecision(20);
		   ll n,m,x;
           cin>>n>>x>>m;
           ll loopsize=-1;
           ll start=-1;
           ll loopval=-1;
           map<ll,ll> cnt;
           ll a=x;
           bool ok=false;
           rep(i,1,n+1){
             sum[i]=sum[i-1];
             if(cnt[a]!=0){
               loopsize=i-cnt[a];
               start=cnt[a];
               loopval=sum[i]-sum[start-1];
               break;
             }
             else{
             sum[i]+=a;
             cnt[a]=i;
             a=a*a%m;
             }
             if(i==n){
              ok=true; 
             }
           }
           if(ok){
            cout<<sum[n]<<endl;
             return 0;
           }
           
           ll ans=sum[start-1];
           ll times=(n-start+1)/loopsize;
           ans+=times*loopval;
           ll R=(n-start+1)%loopsize;
           rep(i,0,R){
            ans+=sum[start+i]-sum[start-1+i]; 
           }
           cout<<ans<<endl;
}