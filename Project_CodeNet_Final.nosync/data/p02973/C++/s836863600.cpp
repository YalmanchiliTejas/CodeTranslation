#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<cmath>
#include<iomanip>
#include<cstring>
#define initdp(a,b) for(int i=0;i<=a;i++)for(int j=0;j<=b;j++)dp[i][j]=-1;
#define fi first
#define se second
#define pb push_back
#define pii pair<int,int>
#define ll long long
#define pll pair<ll,ll>
#define rep(i,n) for(int i=0;i<n;i++)
#define repd(i,n) for(int i=n-1;i>=0;i--)
#define waste ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define inf 1e9+1
#define inf1 1e18+1
#define mod 1000000007
#define pie 3.14159265358979323846
#define N 1000005
#define mid(l,r) l+(r-l)/2
using namespace std;
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
int ddx[8]={1,1,0,-1,-1,-1,0,1},ddy[8]={0,1,1,1,0,-1,-1,-1};
void mad(ll &a,ll b){a=(a+b)%mod;if(a<0)a+=mod;}
ll gcd(ll a,ll b){ if(a>b)swap(a,b);if(!a)return b;return gcd(b%a,a);}

void solve(){
	int n;
	cin>>n;
	ll a[n];
	rep(i,n){cin>>a[i];}
	multiset<ll>ms;
	for(int i=0;i<n;i++){
		auto it=ms.lower_bound(a[i]);
		if(it==ms.begin()){
			ms.insert(a[i]);
		}
		else{
			it--;
			ms.erase(it);
			ms.insert(a[i]);
		}
	}
	cout<<ms.size();
}
int main()
{
	waste;
	int t;
	//cin>>t;
	t=1;
	while(t--){
		solve();
	}
}