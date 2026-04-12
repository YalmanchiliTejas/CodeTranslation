#include <bits/stdc++.h>
using namespace std;
#define ios ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define lop ios; ll t; cin>>t; while(t--)
#define pb push_back
#define vi vector<ll>
#define vivi vector<vector<ll>> 
#define vipa vector<pair<ll,ll>>
#define F first
#define S second
#define M 1000000007
#define kl "\n"
typedef long long ll;
ll lcm(ll x, ll y){ll k=x*y; k/=(__gcd(x,y)); return k;}
ll power(ll x,ll y){ ll r= 1;x = x % M;if(x==0) return 0; while(y>0) {if(y&1) r=(r*x)%M; y=y>>1; x=(x*x)%M;} return r;}  
void solve()
{ 
 ll n;
  cin>>n;
  if(n>=30)
    cout<<"Yes";
  else 
    cout<<"No";
}
int main() 
{ 
    //lop
    solve();
	return 0; 
} 


