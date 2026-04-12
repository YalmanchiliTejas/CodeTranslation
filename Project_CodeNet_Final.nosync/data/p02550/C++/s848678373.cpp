#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define po pop_back
#define fi first
#define se second
#define hello ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define MOD 998244353  
using namespace std;
bool comp(ll a,ll b){if(a>b)return true;else return false;}
int isP(ll n){if(n==1)return 0;if(n==2 || n==3)return 1;for(ll i=2;i<=sqrt(n);i++){if(n%i==0)return 0;}return 1;}
ll power(ll a,ll b){if(b==0)return 1;if(b==1) return a;ll t=power(a,b/2);if(b%2==1) return t*t*a;else return t*t;}
ll powMOD(ll x,ll y){if(y==0)return 1;if(y==1)return x;ll t=powMOD(x,y/2);if(y%2==1)return t*t%MOD*x%MOD;else return t*t%MOD;}
bool cmp(pair<ll,ll> p1,pair<ll,ll> p2){if(p1.fi>p2.fi) return true;if(p1.fi==p2.fi && p1.se>p2.se) return true;return false;}

int main()
{
    hello;
    
    ll t; 
//    cin>>t;
	t=1;
	
	while(t--){
		ll n,x,m;
		cin>>n>>x>>m;
		bool hai[m]={};
		for(ll i=0;i<m;i++){
			if(i*i%m==0) hai[i]=1;
		}
		bool hogya[m]={};
		ll ans=0;
		ll cnt=0;
		ll ho[m]={};
		ll cn[m]={};
		while(cnt<n){
			if(hai[x]){
				ans+=x;
				break;
			}
			if(hogya[x]){
				ll val=ans-ho[x];
				ll l=n-cnt;
				ll le=l/(cnt-cn[x]);
				ans+=le*val;
				l-=le*(cnt-cn[x]);
				for(ll i=1;i<=l;i++){
					ans+=x;
					x=x*x%m;
				}
				break;
			}
			ho[x]=ans;
			cn[x]=cnt;
			hogya[x]=1;
			cnt++;
			ans+=x;
			x=x*x%m;
		}
		cout<<ans<<"\n";
	}
    
    return 0;  
}