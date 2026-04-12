#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define LLMAX (1ll << 60) - 1
#define llMAX (1 << 30) - 1
#define MOD 1000000007 
#define NMAX 1000*100+1
#define MSET(x,y) memset(x,y,sizeof(x))
#define gcd(a,b) __gcd(a,b)
#define all(x)  x.begin(),x.end()
#define vi vector<ll>
#define prll(x)    for(auto it=x.begin();it!=x.end();it++) cout<<*it<<' '; cout<<endl;
#define in(x,n)   for(ll e=0;e<n;e++){ll y;cin>>y;x.pb(y);}
#define vl vector<long long>
#define ii pair<ll,ll>
#define pll pair<ll,ll>
#define vii vector<ii>
#define F first
#define S second
#define mp make_pair


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    ll a[30];
    cin>>n;
    for(int i=0;i<n;i++){
    	cin>>a[i];
	}
	ll m=-1,ans=0;
	for(int i=0;i<n;i++){
    	if(a[i]>=m)
    	ans++;
    	m=max(m,a[i]);
	}
	cout<<ans;
    return 0;
}
 