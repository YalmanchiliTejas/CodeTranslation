#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define F(i,m,n) for(ll i=m;i<n;i++)
#define Fr(j,n,m) for(ll j=n;j>=m;j--)
#define vll vector<ll>
#define pll pair<ll,ll>
#define ff first
#define ss second
#define vpll vector< pll >
#define tlll tuple < ll ,ll,ll >
/*-------------------------------------*---------------------------------------*/

#define godspeed ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define deb(x) cout << #x << "=" << x << endl
#define cout_array(a) cout<<#a<<"=";for(auto x: a){ cout<<x<<" ";}cout<<endl

ll gcd(ll a,ll b){
    return (b?gcd(b,a%b):a);
}
const ll MAX_PRIME = 1e9+7;
const ll INF = 1e18;


/*I NEED YOU TO WORK FOR TWO HOURS ON THIS NO MATTER WHAT....THE RESULT DOESN'T MATTER.....ITS ALL ABOUT YOUR EFFORTS.
---------------------------------------------------------------------------------------------------------------------*/

ll fast_pow(ll x,ll y,ll z){
    if(y==0)return 1%z;
    else if(y==1)return x%z;
    if(y%2==0){
        ll res = fast_pow(x,y/2,z);
        return (res*res)%z;
    }
    else{
        ll res = fast_pow(x,y/2,z);
        ll temp = (res*res)%z;
        return ((x%z)*temp)%z;
    }
}
//---------------method for calculating general mod inverse-------uses extended euclid algo
ll gcdExtended(ll a, ll b, ll &x, ll &y){
    // ax+by = m
    if (a==0)         //gcd = b & ax+by = gcd(a,b)---x and y can be negative;
    {
        x = 0;
        y = 1;
        return b;
    }

    ll x1, y1;
    ll d = gcdExtended(b%a, a, x1, y1);
    x = y1-b/a*x1;           //use floor for negative values
    y = x1;
    return d;
}

ll modInverse(ll a, ll mod=MAX_PRIME){
    ll x, y;
    ll d = gcdExtended(a, mod, x, y);
    if (d!=1)        //gcd must be 1 for inverse to exist
    {
        return -1;
    }

    return (x%mod+mod)%mod;
}
int main() {
    godspeed
    ll special = modInverse(2);
    ll n;
    cin>>n;
    vll a(n);
    ll sum1 = 0;
    ll sum2 = 0;
    F(i,0,n){
        cin>>a[i];
        sum1+=a[i];
        sum1%=MAX_PRIME;
        sum2+=fast_pow(a[i],2,MAX_PRIME);
        sum2%=MAX_PRIME;
    }
    ll val = fast_pow(sum1,2,MAX_PRIME) - sum2;
    val = (val + MAX_PRIME)%MAX_PRIME;
    ll ans = (val*special)%MAX_PRIME;
    cout<<ans<<endl;
}
