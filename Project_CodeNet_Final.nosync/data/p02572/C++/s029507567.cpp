// @gaurav_512
#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vii;
typedef unordered_map<int,int> umii;
typedef unordered_map<ll,ll> umll;

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define bs(v,val) binary_search(v.begin(),v.end(),val)
#define mod 1000000007
#define ff first
#define ss second
#define fi(n) for(int i=0;i<n;i++)
#define fj(n) for(int j=0;j<n;j++)
#define all(v) v.begin(),v.end()
#define pb push_back
#define m_p make_pair
#define endl '\n'

struct custom_hash {    // anti-hack for unordered_map. To declare: unordered_map<long long, int, custom_hash> safe_map;
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        x ^= FIXED_RANDOM;
        return x ^ (x >> 16);
    }
};

ll power(ll x, ll y, ll p)
{  
    ll res = 1;
    x = x % p;  
    if (x == 0) return 0;
    while (y > 0){  
        if (y & 1)  res = (res*x) % p;  
        y = y>>1;
        x = (x*x) % p;  
    }  
    return res;  
}
ll modInverse(ll n, ll p)
{
    return power(n, p-2, p); 
}
// ********** CODE STARTS HERE ****************//

void solve()
{
	int n;
	cin >> n;
	vi a(n);
	fi(n)cin>>a[i];
	ll sum = 0;
	fi(n)sum+=a[i];
	ll sum_square = 0;
	// const int mod = 1000000007;
	fi(n){sum_square += 1ll*a[i]*a[i];sum_square%=mod;}
	sum%=mod;
	sum = sum*sum;
	ll res = ((sum-sum_square+mod)%mod+mod)%mod;
	cout<<(modInverse(2,mod)*res)%mod;
   
}


int main()
{
    int t;
    // cin>>t;
    // while(t--)
     solve();

	return 0;
}