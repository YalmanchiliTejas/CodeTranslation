#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pp pair<pair<ll, ll>,pair<ll, ll>>
#define pll pair<ll,ll>
#define pdd pair<double,double>
#define vii vector<int>
#define vll vector<ll>
#define mat vector<vector<ll>>
#define lb lower_bound
#define ub upper_bound
#define pb push_back
#define eb emplace_back
#define fi first
#define sc second
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep2(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,n) for(ll i=n-1;i>=0;i--)
#define all(x) x.begin(),x.end()
#define sz(x) (ll) (x).size()
#define pq priority_queue<ll>
#define pqg priority_queue<ll,vector<ll>,greater<ll>>
#define LB(v,x) (lower_bound(v.begin(),v.end(),x)-v.begin())
#define UB(v,x) (upper_bound(v.begin(),v.end(),x)-v.begin())
#define ERASE(v) sort(v.begin(),v.end());v.erase(unique(v.begin(),v.end()),v.end())
#define int ll
// #define ll int
using namespace std;
const ll INF = (1 << 30 ) - 1;
const ll LLINF = (1LL << 60LL);
const ll MOD = 1000000007;
const ll mod = 998244353;
const ll MAX = 2100000;
const double pi = acos(-1);
const double eps = 1e-10;
ll dx[8] ={1,0,-1,0,1,-1,1,-1};
ll dy[8] ={0,1,0,-1,1,-1,-1,1};
 
template<class T> 
inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> 
inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


ll dp0[110][4],dp1[110][4];

void solve(){
    string s;
    ll k;
    cin>>s>>k;
    ll n=s.size();
    ll a[200];
    rep(i,n) a[i]=s[i]-'0';
    dp0[0][0]=1;

    rep(i,n){
        rep(j,k+1){
            if(a[i]==0){
                dp0[i+1][j]+=dp0[i][j];
                dp1[i+1][j]+=dp1[i][j];
                if(j==k) continue;
                dp1[i+1][j+1]+=dp1[i][j]*9;
            }
            else{
                dp1[i+1][j]+=dp1[i][j];
                dp1[i+1][j]+=dp0[i][j];
                if(j==k) continue;
                dp1[i+1][j+1]+=dp1[i][j]*9;
                dp0[i+1][j+1]+=dp0[i][j];
                dp1[i+1][j+1]+=dp0[i][j]*(a[i]-1);

            }

        }
    }
    cout<<dp0[n][k]+dp1[n][k]<<endl;
    

}


signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    

    solve(); 


    return 0;
}
