// created by mtnshh
 
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
 
#define ll long long
#define ld long double
 
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repb(i,a,b) for(ll i=a;i>=b;i--)
 
#define err() cout<<"=================================="<<endl;
#define errA(A) for(auto i:A)   cout<<i<<" ";cout<<endl;
#define err1(a) cout<<#a<<" "<<a<<endl
#define err2(a,b) cout<<#a<<" "<<a<<" "<<#b<<" "<<b<<endl
#define err3(a,b,c) cout<<#a<<" "<<a<<" "<<#b<<" "<<b<<" "<<#c<<" "<<c<<endl
#define err4(a,b,c,d) cout<<#a<<" "<<a<<" "<<#b<<" "<<b<<" "<<#c<<" "<<c<<" "<<#d<<" "<<d<<endl
 
#define pb push_back
#define all(A)  A.begin(),A.end()
#define allr(A)    A.rbegin(),A.rend()
#define ft first
#define sd second
 
#define pll pair<ll,ll>
#define V vector<ll>
#define S set<ll>
#define VV vector<V>
#define Vpll vector<pll>
 
#define endl "\n"
 
const ll logN = 20;
const ll M = 998244353;
const ll INF = 1e12;
#define PI 3.14159265
 
const ll N = 3005;

ll dp[N];
ll A[N];

ll ans=0;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n,s;
	cin>>n>>s;
	rep(i,0,n)	cin>>A[i];
	ll ans=0;
	rep(j,0,n){
		repb(k,s,A[j]+1){
			dp[k] += dp[k-A[j]];
			dp[k] %= M;
		}
		dp[A[j]] += (j+1);
		dp[A[j]] %= M;
		ans += dp[s];
		ans %= M;
	}
	ans %= M;
	cout<<ans<<endl;
    return 0;
}