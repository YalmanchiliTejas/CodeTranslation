#include<bits/stdc++.h>
#define ll long long
#define fr(i,x,y) for(int i=(x);i<=(y);i++)
#define rf(i,x,y) for(int i=(x);i>=(y);i--)
#define frl(i,x,y) for(int i=(x);i<(y);i++)
using namespace std;
const int N=10000002;
const int p=998244353;
int n;

void read(int &x){
	char ch=getchar();x=0;
	for(;ch<'0'||ch>'9';ch=getchar());
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<3)+(x<<1)+ch-'0';
}

void Add(ll &x,ll y){
	x+=y;
	while(x>=p) x-=p;
	while(x<0) x+=p;
}

ll qpow(ll a,ll n){
	ll ans=1;
	for(;n;n>>=1,a=a*a%p) if (n&1) ans=ans*a%p;
	return ans;
}

ll fac[N],inv[N];
void init(){
	fac[0]=1;
	frl(i,1,N) fac[i]=fac[i-1]*i%p;
	inv[N-1]=qpow(fac[N-1],p-2);
	rf(i,N-2,0) inv[i]=inv[i+1]*(i+1)%p;
}

ll C(int n,int m){ return fac[n]*inv[m]%p*inv[n-m]%p; }

int main(){
	cin>>n;
	init();
	ll ans=qpow(3,n);
	ll pw=2;
	rf(i,n,n/2+1){
		Add(ans,-C(n,i)*pw%p);
		pw=pw*2%p;
	}
	cout<<ans<<endl;
	return 0;
}