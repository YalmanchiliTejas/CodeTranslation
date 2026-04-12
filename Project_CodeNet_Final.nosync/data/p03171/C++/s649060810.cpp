#include <bits/stdc++.h>
using namespace std;

#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define watch(x) cout << (#x) << " is " << (x) << endl
#define f(t) for(ll i =0;i<t;i++)
#define bs(a,x) binary_search(a.begin(),a.end(),x)
#define ll long long int
#define ul unsigned long int
#define ld long double
#define umpi unordered_map<int,int> 
#define umpl unordered_map<ll,ll> 
#define vi vector<int>
#define vl vector<ll>
#define fill(a,p) memset(a,p,sizeof(a))
#define pb push_back
#define mod 1000000007
#define N 100005
#define all(a) a.begin(),a.end()
#define point pair<ll,ll>
#define endl "\n"

const int inf = 1000000007;
const ll linf = 1ll * inf * inf;
const ll MAXIMUM =2005;

inline ll mul(ll a, ll b){ return (a * 1ll * b) % mod; }
inline ll sub(ll a, ll b){ ll c = a - b; if(c < 0) c += mod; return c; }
inline ll add(ll a, ll b){ ll c = a + b; if(c >= mod) c -= mod; return c; }
inline ll max(ll a, ll b){return a>b?a:b;}
inline ll minim(ll a, ll b){return a<b?a:b;}

struct hash_pair { 
    template <class T1, class T2> 
    size_t operator()(const pair<T1, T2>& p) const
    { 
        auto hash1 = hash<T1>{}(p.first); 
        auto hash2 = hash<T2>{}(p.second); 
        return hash1 ^ hash2; 
    } 
};

ll power(ll x, ll y,ll p) 
{ 
    ll res = 1;      
     x = x % p;    
    while (y > 0) 
    { 
        if (y & 1) 
            res = (res*x) % p; 
            y = y>>1;  
            x = (x*x) % p;   
    } 
    return res; 
}

ll modInverse(ll n,ll p) 
{ 
    return power(n, p-2, p); 
} 


ll lcm(ll a,ll b){
  return (a*b)/__gcd(a,b);
}

bool comp(const point &p1,const point &p2){
	if(p1.first!=p2.first)return p1.first<p2.first;
	else return p1.second<p2.second;
}

string to(char x){
	string s(1,x);
	return s;
}

int main()
{
	fio;
	ll n;cin>>n;
	vl a(n);
	f(n)cin>>a[i];
	point dp[n][n];
	for(ll i=0;i<n;i++){
		dp[i][i].first=a[i];
		dp[i][i].second=0;
	}
	for(ll k=1;k<n;k++){
		for(ll i=0;i+k<n;i++){
			ll j=i+k;
			if(a[i]+dp[i+1][j].second>a[j]+dp[i][j-1].second){
				dp[i][j].first=a[i]+dp[i+1][j].second;
				dp[i][j].second=dp[i+1][j].first;
			}else{
				dp[i][j].first=a[j]+dp[i][j-1].second;
				dp[i][j].second=dp[i][j-1].first;
			}
		}
	}
	cout<<dp[0][n-1].first-dp[0][n-1].second<<endl;
}