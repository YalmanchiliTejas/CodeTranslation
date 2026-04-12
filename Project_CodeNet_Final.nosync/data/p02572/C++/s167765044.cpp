//Sum of product of pairs 

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define int long long
#define rep(i,x,y) for(ll i=x;i<y;i++)
#define nvarep(n,a) ll n;cin>>n;vector<ll>a(n);rep(i,0,n)cin>>a[i]
#define vecrep(n,a,type) vector<type>a(n);rep(i,0,n)cin>>a[i]
#define YN(flag) (flag?"Yes":"No")
#define lcm(a,b) (a/__gcd(a, b)*b)
#define range(a) (a).begin(),(a).end() 
#define pb push_back
#define mp make_pair
#define nnn "\n"
#define spa " "
using P = pair<ll,ll>;
using graph = vector<vector<ll>>;
const int inf = 2147483647;//2*10^9
const ll INF = 9223372036854775807;//9*10^18
int mod = 1000000007;

signed main (){
    nvarep(n,a);
    reverse(range(a));
    vector<int>t(n,0);
    rep(i,1,n){
        t[i]=a[i-1]+t[i-1];
    }
    int ans = 0;
    rep(i,1,n){
        ans=(ans+(t[i]%mod*a[i]%mod)%mod)%mod;
    }
    cout<<ans<<nnn;
    return 0;
}