#include <bits/stdc++.h>
#define pb push_back
#define all(a) a.begin(),a.end()
#define forn(i,n) for(int i=0;i<int(n);i++)
#define forr(i,n) for(int i=int(n-1);i>=0;i--)
#define fora(i,a,b) for(int i=int(a);i<=int(b);i++)
#define forb(i,a,b) for(int i=int(a);i>=int(b);i--)
#define mod 1000000007
using namespace std;
using ll=long long int;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<ll> vii;
typedef pair<ll ,ll> pii;
const int dx[]={-1,1,0,0};
const int dy[]={0,0,-1,1};
void solve()
{
	ll n;
	cin>>n;
	ll arr[n];
	forn(i,n)cin>>arr[i];
	ll pre[n];
	pre[0]=arr[0];
	fora(i,1,n-1)pre[i]=(pre[i-1]+arr[i])%mod;
	ll ans=0;
	for(int i=n-1;i>=1;i--)
	{
		ans+=arr[i]*pre[i-1];
		ans%=mod;
	}
	cout<<ans%mod<<endl;
	
}
int main()
{
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);
    int t=1;
  //  cin>>t;
    while(t--)
	solve();
    return 0;
}
