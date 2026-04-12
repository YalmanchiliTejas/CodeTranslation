#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1<<14,mo=998244353;
int lgM=14,M=1<<lgM;
int r[N];
ll a[N],b[N],w[N],jc[N],ny[N],c[N];
int n,m;
ll power(ll a,ll b=mo-2){
	ll ans=1;
	while (b){
		if (b&1)ans=ans*a%mo;
		a=a*a%mo;
		b>>=1;
	}return ans;
}
void prep(){
	w[0]=1;
	w[1]=power(3,(mo-1)/M);
	for (int i=2;i<M;i++)w[i]=w[i-1]*w[1]%mo;
	jc[0]=ny[0]=1;
	for (int i=1;i<M;i++)jc[i]=jc[i-1]*i%mo;
	ny[M-1]=power(jc[M-1]);
	for (int i=M-1;i;i--)ny[i-1]=ny[i]*i%mo;
}
void dft(ll *a){
	for (int i=1;i<M;i++){
		r[i]=(r[i>>1]>>1)+(i&1)*(M>>1);
		if (r[i]<i)swap(a[i],a[r[i]]);
	}
	for (int n=1,ax=lgM-1;n<M;n<<=1,ax--){
		for (int i=n;i<M;i=(i+1)|n){
			ll A=a[i]*w[(i&(n-1))<<ax]%mo;
			a[i]=(a[i^n]-A+mo)%mo;
			a[i^n]=(a[i^n]+A)%mo;
		}
	}
}
void idft(ll *a){
	for (int i=1,j=M-1;i<j;i++,j--)swap(a[i],a[j]);
	dft(a);
	ll ny=power(M);
	for (int i=0;i<M;i++)a[i]=a[i]*ny%mo;
}
int main(){
	cin>>n>>m;
	prep();
	a[0]=1;
	for (int i=0;i<=n;i++)b[i]=ny[i+2];
	dft(b);
	for (int i=1;i<=m;i++){
		for (int i=n+1;i<M;i++)a[i]=0;
		for (int i=0;i<=n;i++)c[i]=a[i],a[i]=a[i]*ny[i];
		dft(a);
		for (int i=0;i<M;i++)a[i]=a[i]*b[i]%mo;
		idft(a);
		for (int i=0;i<=n;i++)a[i]=(a[i]*jc[i+2]%mo+c[i]*(mo-i))%mo;
	}
	ll ans=0;
	for (int i=0;i<=n;i++)ans=(ans+ny[i]*ny[n-i]%mo*jc[n]%mo*a[i])%mo;
	cout<<ans<<endl; 
}