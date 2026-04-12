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
const int N=3005;
int n,mo,ans;
int S[N][N],C[N][N];
int power(int x,int y,int mo){
	int s=1;
	for (;y;y/=2,x=1ll*x*x%mo)
		if (y&1) s=1ll*s*x%mo;
	return s;
}
int main(){
	scanf("%d%d",&n,&mo);
	S[0][0]=1;
	For(i,0,n+1) C[i][0]=1;
	For(i,1,n+1) For(j,1,i){
		S[i][j]=(S[i-1][j-1]+1ll*S[i-1][j]*j)%mo;
		C[i][j]=(C[i-1][j-1]+C[i-1][j])%mo;
	}
	For(i,0,n){
		int val=(i&1?mo-C[n][i]:C[n][i]);
		int p=power(2,n-i,mo),vp=1;
		val=1ll*val*power(2,power(2,n-i,mo-1),mo)%mo;
		For(j,0,i){
			int vval=1ll*val*S[i+1][j+1]%mo;
			ans=(ans+1ll*vval*vp)%mo;
			vp=1ll*vp*p%mo;
		}
	}
	printf("%d\n",ans);
}