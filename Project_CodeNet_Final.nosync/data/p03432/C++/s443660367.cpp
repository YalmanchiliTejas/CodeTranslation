#include<bits/stdc++.h>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;++i)
#define ff(i,a,b)for(int i=a,_e=b;i<_e;++i)
#define fd(i,a,b)for(int i=b,_e=a;i>=_e;--i)
#define dot(a,b) ff(k,0,Q)a[k]=(ll)a[k]*b[k]%mo
#define ll long long
using namespace std;
const int N=(1<<14)+5,mo=998244353;
int n,m,ans;
int Q,o,f[2][N],a[N],b[N],h[N],w[N],jc[N],ny[N];
int ksm(int x,int y){
	int t=1;
	for(;y;y>>=1,x=(ll)x*x%mo)if(y&1)t=(ll)t*x%mo;
	return t;
}
void dft(int *a,int sig){
	ff(i,1,Q)if(h[i]>i)swap(a[i],a[h[i]]);ll A;
	for(int i=1;i<Q;i<<=1)for(int j=0;j<Q;j+=i*2)
		ff(k,0,i)A=(ll)w[i+k]*a[i+j+k],a[i+j+k]=(-A+a[j+k])%mo,a[j+k]=(A+a[j+k])%mo;
	if(sig){
		reverse(a+1,a+Q);
		int y=ksm(Q,mo-2);
		ff(i,0,Q)a[i]=(ll)(a[i]+mo)*y%mo;
	}
}
int main(){
	cin>>n>>m;
	jc[0]=1;
	fo(i,1,n+2)jc[i]=(ll)jc[i-1]*i%mo;
	ny[n+2]=ksm(jc[n+2],mo-2);
	fd(i,0,n+1)ny[i]=(ll)ny[i+1]*(i+1)%mo;
	for(Q=1;Q<=n*2;Q<<=1);
	ff(i,1,Q)h[i]=(h[i>>1]>>1)|(i&1?Q>>1:0);
	for(int i=1;i<Q;i<<=1){
		int g=ksm(3,(mo-1)/(i*2));w[i]=1;
		ff(j,1,i)w[i+j]=(ll)w[i+j-1]*g%mo;
	}
	f[0][0]=1;
	fo(j,1,m){
		o^=1;
		fo(i,0,n){
			a[i]=(ll)f[!o][i]*ny[i]%mo;
			b[i]=i?ny[i+2]:0;
			f[o][i]=(ll)((ll)(i+1)*i/2+1)%mo*f[!o][i]%mo;
		}
		ff(i,n+1,Q)a[i]=b[i]=0;
		dft(a,0);dft(b,0);dot(a,b);dft(a,1);
		fo(i,0,n)f[o][i]=((ll)a[i]*jc[i+2]+f[o][i])%mo;
	}
	fo(i,0,n)ans=((ll)f[o][i]*jc[n]%mo*ny[i]%mo*ny[n-i]+ans)%mo;
	cout<<ans;
}