#include <bits/stdc++.h>
#define ll long long
#define re register
#define IL inline
using namespace std;
const int maxn=3e3+10;
template<typename T> void read(T &x){
	T f=1;x=0;
	char s=getchar();
	while(s<'0' || s>'9'){if(s=='-') f=-1;s=getchar();}
	while(s>='0' && s<='9'){x=(x<<3)+(x<<1)+s-48;s=getchar();}
	x*=f;
}
int n;
ll a[maxn];
ll f[maxn][maxn];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	read(n);
	for(re int i=1;i<=n;i++){
		read(a[i]);
		if(n&1){
			f[i][i]=a[i];
		}
		else f[i][i]=-a[i];
	}
	for(re int i=1;i<n;i++){
		for(re int j=1;j<=n-i;j++){
			if((n-i-1)&1)
				f[j][i+j]=min(f[j+1][i+j]-a[j],f[j][i+j-1]-a[i+j]);
			else f[j][i+j]=max(f[j+1][i+j]+a[j],f[j][i+j-1]+a[i+j]);
		}
	}
	cout<<f[1][n]<<endl;
	return 0;
}
