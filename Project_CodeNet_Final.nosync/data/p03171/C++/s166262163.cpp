#include <bits/stdc++.h>
using namespace std;
 
#define ll long long 
#define llinf 1e17
#define nllinf -4e18
 
#define vll vector<ll>
#define sll set<ll>
#define pll pair<ll,ll> 
#define vpll vector<pair<ll,ll > >
 
#define repup(a,b,i) for(i=a;i<=b;i++)
#define repdown(a,b,i) for(i=b; i>=a; i--)
#define repupx(a,b,i,x) for(i=a;i<=b;i+=x)
	
#define repit(v,it) for(it=v.begin(); it!=v.end(); it++)
#define itall(v) v.begin(),v.end()
#define pb push_back
#define pf push_front
#define mp make_pair
#define fr first
#define sc second
 
#define err(n) cout<<n<<" ";
#define t1 cout<<",";
 
ll MOD= 1e9 +7;

ll dp[3005][3005];

int main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
ll i,j,k;

ll n;cin>>n;
ll a[n];repup(0,n-1,i)cin>>a[i];

ll l,r;
repdown(0,n-1,l){
	repup(l,n-1,r){
		if(l==r){dp[l][r]=a[l];continue;}
		dp[l][r]= max(a[l]-dp[l+1][r], a[r]- dp[l][r-1]);
	}
}
cout<<dp[0][n-1];

}