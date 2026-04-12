 #include<bits/stdc++.h>
#define tmp(x) std::cout<<"& "<<(x)<<" &\n"
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
#define mp make_pair
#define pii pair<int,int>
typedef long long ll;
ll qpow(ll a,ll n,ll p){
	ll ans=1;
	while(n){
		if(n&1)
			ans*=a,ans%=p;
		a*=a,a%=p;
		n>>=1;
	}
	return ans;
}

using namespace std;
const int maxn=2e5+100;
const int p=1e9+7;
int n,t;
int a[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
 	cin>>n;
 	ll tot=0;
 	rep(i,1,n){
 		cin>>a[i];
 		tot+=a[i];
	 }
	 tot%=p;
	 tot=(tot*tot)%p;
	 ll k=0;
	 rep(i,1,n){
		k=(k+1ll*a[i]*a[i]%p)%p;
	 }
	 tot=(tot-k+p)%p;
	 if(tot%2==0)tot=tot/2;
	 else tot=1ll*tot*qpow(2,p-2,p)%p;
	 cout<<tot;
 
 
 
    return 0;
}
