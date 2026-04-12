#include <bits/stdc++.h>
using namespace std; 
#define lp(var,start,end) for (ll var = start; var <end ; ++var)
#define rlp(var,start,end) for(ll var = start; var>=end ; var--)
#define ios ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll long long int
#define ld long double
#define fi first 
#define se second 
#define mp make_pair
#define pb push_back
#define ull unsigned long long int
#define vll vector<ll>
#define vld vector<ld>
#define pll pair<ll,ll> 
#define pld pair<ld,ld> 
#define vpll vector<pll>
#define vpld vector<pld>
#define all(X) X.begin(),X.end()
#define mo 1000000007
ll gcd(ll a ,ll b){if(a%b==0)return b;return gcd(b,a%b);}
ll poww(ll a,ll n){if(n==0)return 1;ll p=poww(a,n/2);p=(p*p)%mo;if(n%2)p=(a*p)%mo;return p;}
////////////////////////////////////////////////////

ll tn ; ll dp[200005]; ll ans[200005]; 
void solve()
{
 ll n ; 
 cin>>n; 
 ll a[n]; 
 for(int i =0; i<n ; i++)
 cin>>a[i]; 
 if(n==2)
 {
 	cout<<max(a[0],a[1])<<endl ;return; 
 }
 dp[0]=a[0]; 
 dp[1]=a[1];
 dp[2]= a[2]+a[0]; ans[1] = max(a[0],a[1]);
 ans[2]=max(a[2],max(a[1],a[2])); 
 for(int i =3; i<n ; i++)
 {  dp[i]= a[i]+dp[i-2]; 
 	if(i%2==0)
 	{
 		ans[i]= max(ans[i-2]+a[i], max(ans[i-1],dp[i-2]));
	 }
	 else
	 {
	 	ans[i]= max(a[i]+ans[i-2],dp[i-1]); 
	 }
 
 }
cout<<ans[n-1]<<endl; 
}
int main()
{ ios; 

ll t ;t = 1; 
  for(tn = 1; tn<=t; tn++)
	solve(); 
	return 0 ; 
}