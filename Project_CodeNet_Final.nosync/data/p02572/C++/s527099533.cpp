#include<iostream>
#include<numeric>
#include<math.h>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<climits>
#define fi first
#define se second
#define pb push_back
#define pii pair<int,int>
#define ll long long
#define mkp make_pair
#define pll pair<ll,ll>
#define rep(i,from,to) for(int i=from;i<to;i++)
#define repd(i,from,till) for(int i=from;i>=till;i--)
#define waste ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define inf 1e9+1
#define mod 1000000007
#define inf1 1e18+1
#define pie 3.14159265358979323846
#define N 100005
using namespace std;

int solve(){
    int n;
    cin>>n;
	ll a[n];
	ll sum[n+1];
	sum[0]=0;
	rep(i,0,n){
		cin>>a[i];
		sum[i+1]=(sum[i]+a[i])%mod;
	}
	ll mul=0;
	rep(i,0,n){
		ll val=(sum[n]-sum[i+1]);
		val+=mod;
		val%=mod;
		val*=a[i];
		val%=mod;
		mul+=val;
		mul%=mod;
	}
	cout<<mul<<endl;
	return 0;
}
int main(){
    waste;
    int t;
    //cin>>t;
    t=1;
    while(t--){
       	solve();
    }
}
