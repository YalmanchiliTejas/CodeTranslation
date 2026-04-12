#include <bits/stdc++.h>

using namespace std;
#define set_precision(ans,l) cout << fixed << setprecision(l)<<ans;
#define rep(i, a, b) for (int i = a; i < b; i++)
#define repb(i, a, b) for (int i = a; i >= b; i--)
#define vi vector<int>
#define vl vector<long long int>
#define Vi vector<vector<int>>
#define vpi vector<pair<int,int>>
#define seti set<int>
#define setl set<ll>
#define dseti set<int, greater<int>>
#define dsetl set<ll, greater<ll>>
#define mseti multiset<int>
#define msetl multiset<ll>
#define dmseti multiset<int, greater<int>>
#define dmsetl multiset<ll, greater<ll>>
#define sortA(arr) sort(arr.begin(), arr.end())
#define dsortA(arr) sort(arr.begin(), arr.end(), greater<ll>())
#define ssort(arr) stable_sort(arr.begin(), arr.end())
#define nth(v,n) nth_element(v.begin,v.begin+n-1,v.end())
#define dnth(v,n) nth_element(v.begin,v.begin+n-1,v.end(), greater<ll>())
#define init(a)  memset((a),0,sizeof(a))
#define pi pair<int,int>
#define pb push_back
#define pl pair<ll,ll>
#define ll long long
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define mod 1000000007
long double EPS = 1e-9;

/*struct comp {
  bool operator() (const int& lhs, const int& rhs) const
  {return lhs<rhs;}
};*/

ll cel(ll a,ll b){return((a-1)/b+1);} 
ll gcd(ll a, ll b){
    if (a < b)swap(a, b);
    return (b == 0)? a: gcd(b, a % b);
}
ll lcm(ll a,ll b){return (a*b)/gcd(a,b);}
ll po(ll x,ll y){
    ll ans=1;
    while(y){
        if(y&1){ans=(ans*x)%mod;}
        y>>=1;x=(x*x)%mod;
    }
    return ans;
}

int main()
{
    FIO;
    ll n,t,x,y,m,k,ans=0;
    cin>>n;vl v(n),pre(n,0);
    rep(i,0,n){cin>>v[i];}
    pre[0]=v[0];
    rep(i,1,n){pre[i]=pre[i-1]+v[i];}
    rep(i,0,n-1){
        ans=(ans+(v[i]*((pre[n-1]-pre[i])%mod))%mod)%mod;
    }
    cout<<ans;
    return 0;
}