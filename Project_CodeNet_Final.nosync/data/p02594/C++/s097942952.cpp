#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 1e18
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define pb push_back
#define ff first
#define ss second
#define vll vector<ll>
#define pii pair<ll,ll>
#define sz(v) (v).size()
#define srt(v) sort(v.begin(),v.end())
#define ull unsigned long long
#define tell(a) cout<<a<<" "
#define el cout<<endl
#define rev(v) reverse(v.begin(),v.end())
#define rep(i,a,n) for(int i=a;i<n;i++)
#define ld long double
#define mem(a,b) memset(a,b,sizeof(a) )
#define M 4000010
#define md 1000000007

ll power(ll x, ll y, ll p){ll res = 1;x = x % p;while (y > 0){   if (y & 1)res = (res*x) % p;y = y>>1;
x = (x*x) % p;}return res;}
/*inline ll add(ll a,ll b){return (a+b)%md;}
inline ll mul(ll a,ll b){return (a*b)%md;}
ll f[M],iv[M];
ll C(ll n,ll r){return mul(f[n],mul(iv[r],iv[n-r]));}
void prep_fac(){
    f[0]=1;
    rep(i,1,M)f[i]=mul(i,f[i-1]);
    iv[M-1]=power(f[M-1],md-2,md);
    for(ll i=M-2;i>=0;--i)iv[i]=mul(i+1,iv[i+1]);
}*/



int main()
{
	IOS;
	int n;
	cin>>n;
	if(n>=30)
	cout<<"Yes";
	else
	cout<<"No";
}

