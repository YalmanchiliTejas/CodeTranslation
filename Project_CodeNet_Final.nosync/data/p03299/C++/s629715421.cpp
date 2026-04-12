#include<bits/stdc++.h>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;++i)
#define add(x,y)(x=((ll)y+x)%mo)
#define ll long long
using namespace std;
const int N=105,mo=1e9+7;
int n,nn,v,ans;
int h[N],w[N],h2[N],f[N][N];
int ksm(int x,int y){
	int t=1;
	for(;y;y>>=1,x=(ll)x*x%mo)if(y&1)t=(ll)t*x%mo;
	return t;
}
int main(){
	ios::sync_with_stdio(0);
	cin>>n;
	fo(i,1,n)cin>>h[i],h2[i]=h[i];
	sort(h2+1,h2+n+1);
	nn=unique(h2+1,h2+n+1)-h2-1;
	f[0][0]=1;
	fo(i,1,n){
		w[i]=lower_bound(h2+1,h2+nn+1,h[i])-h2;
		if(v=f[i-1][0]){
			f[i][0]=(ll)v*2%mo;
			if(h[i-1]<h[i]){
				fo(j,w[i-1]+1,w[i]){
					if(j==1)f[i][j]=(ll)2*ksm(2,h[i]-h2[1])%mo*(ksm(2,h2[1]-1)-1)%mo;
					else f[i][j]=(ll)v*2*ksm(2,h[i]-h2[j])%mo*(ksm(2,h2[j]-h2[j-1])-1)%mo;
				}
			}	
		}
		int p;
		if(h[i-1]<h[i])p=ksm(2,h[i]-h[i-1]);
		fo(j,1,nn)if(v=f[i-1][j]){
			if(h[i-1]>=h[i]){
				if(j<=w[i])add(f[i][j],v);
				else add(f[i][0],v*2);
			}else{
				add(f[i][j],v*p);
			}
		}
	}
	fo(i,0,nn)add(ans,f[n][i]);
	cout<<ans;
}