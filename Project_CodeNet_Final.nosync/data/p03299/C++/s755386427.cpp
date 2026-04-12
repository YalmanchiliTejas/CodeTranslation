#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
using namespace std;
const int mo=1000000007;
int n,a[105];
int power(int x,int y){
	int s=1;
	for (;y;y/=2,x=1ll*x*x%mo)
		if (y&1) s=1ll*s*x%mo;
	return s;
}
pii operator *(const pii &a,const pii &b){
	int sum=2ll*(a.fi+a.se)*(b.fi+b.se)%mo;
	return pii(2ll*a.fi*b.fi%mo,sum);
}
pii F(int l,int r,int v){
	if (l==r)
		return pii(power(2,a[l]-v-1),0);
	int mnv=1<<30,las=l;
	pii vf;
	For(i,l,r) mnv=min(mnv,a[i]);
	For(i,l,r+1)
		if (a[i]==mnv||i==r+1){
			if (las!=i){
				pii vson=F(las,i-1,mnv);
				int v1=vf.fi,v2=vf.se;
				int v3=2ll*vson.fi%mo,v4=vson.se;
				if (las==l) vf=pii(v3,v4);
				else{
					vf.fi=1ll*v1*v3%mo;
					vf.se=(2ll*(v1+v2)*(v3+v4)+mo-vf.fi)%mo;
				}
			}
			if (i!=r+1){
				if (i==l) vf=pii(1,0);
				else{
					int v1=vf.fi,v2=vf.se;
					vf=pii(v1,(v1+2ll*v2)%mo);
				}
			}
			las=i+1;
		}
	vf.fi=1ll*vf.fi*power(2,mnv-v-1)%mo;
	return vf;
}
int main(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&a[i]);
	pii ans=F(1,n,0);
	printf("%d",2ll*(ans.fi+ans.se)%mo);
}