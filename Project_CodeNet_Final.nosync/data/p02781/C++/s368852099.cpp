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
const ll MAX = 1100000;
const double pi = acos(-1);
const double eps = 1e-10;
ll dx[8] ={1,0,-1,0,1,-1,1,-1};
ll dy[8] ={0,1,0,-1,1,-1,-1,1};
 
template<class T> 
inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> 
inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }



void solve(){
    string s;
    ll k;
    cin>>s>>k;
    ll n=s.size();
    ll ans=0;
    for(ll i=1;i<n;i++){
        if(k==1){
            ans+=9;
        }
        else if(k==2){
            if(i==1) continue;
            ans+=9*(i-1)*9;
        }
        else if(k==3){
            if(i<k) continue;
            ans+=9*(i-1)*(i-2)/2*9*9;
        }
    }

    ll a=s[0]-'0';
    if(k==1) ans+=a;
    else if(k==2){
        ans+=(a-1)*(n-1)*9;
        bool ok=false;
        rep2(i,1,n){
            if(s[i]=='0'&&ok==false) continue;
            if(ok) ans+=9;
            else{
                if(s[i]!='0') ok=true;
                ll b=s[i]-'0';
                ans+=b;
            }
        }
    }
    else if(k==3){
        ans+=(a-1)*(n-1)*(n-2)/2*9*9;
        bool ok=false;
        ll sum=0;
        rep2(i,1,n){
            if(s[i]=='0'&&ok==false) continue;
            if(sum==1&&s[i]!='0'){
                ans+=(s[i]-'0');
                ans+=(n-i-1)*9;
                sum=0;
            }
            if(ok){
                ans+=(n-i-1)*9*9;
            }
            else{
                if(s[i]!='0') ok=true;
                ll b=s[i]-'0';
                ans+=(b-1)*(n-i-1)*9;
                sum=1;
            }
        }

    }
    // cout<<n<<endl;
    cout<<ans<<endl;


}


signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    
     

    solve(); 


    return 0;
}
