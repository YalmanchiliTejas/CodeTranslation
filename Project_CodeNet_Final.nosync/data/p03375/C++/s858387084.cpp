#include<bits/stdc++.h>
#define ll long long
#define db double
#define lowbit(p) (p&(-p))
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define A first
#define B second
using namespace std;
void read(int &x){
	x=0; char c=getchar(); int p=1;
	for (;c<48;c=getchar())if (c=='-')p=-1;
	for (;c>47;c=getchar())x=(x<<1)+(x<<3)+(c^48);
	x*=p;
}
void read(ll &x){
	x=0; char c=getchar(); int p=1;
	for (;c<48;c=getchar())if (c=='-')p=-1;
	for (;c>47;c=getchar())x=(x<<1)+(x<<3)+(c^48);
	x*=p;
}
void Min(int &x,int y){
	if (x>y)x=y;
}
void Max(int &x,int y){
	if (x<y)x=y;
}
void Min(ll &x,ll y){
	if (x>y)x=y;
}
void Max(ll &x,ll y){
	if (x<y)x=y;
}
/*
##题意:
n种配料,求多少个集合满足每种配料至少出现两次.

##分析:
dp[x]表示有x种酱不合法的方案数

然后令f[x][y]表示x碗面,有y不合法的酱,注意这x碗都是不合法的,那么有
f[x][y]=f[x][y-1]*(x+1)			+f[x-1][y-1]
		扔到之前的碗里或者不扔	开一个新的碗
(x<=n&&y<=n)//其实差不多就是斯特林数

然后再来考虑可以随便放的酱
那么
f[x][y]*2^(2^(n-y)*(x+1));

*/
ll ksm(ll a,ll b,ll mo){
	ll res=1;
	for (;b;b>>=1){
		if (b&1)res=res*a%mo;
		a=a*a%mo;
	}
	return res;
}
#define M 3005
ll f[M][M*2],mo,c[M][M],res;
int n;
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	freopen("1.in","r",stdin);
	read(n); read(mo);
	int i,j;
	ll g;
	f[0][0]=1;
	for (i=1;i<M;i++){
		for (j=1;j<2*M;j++){
			f[i][j]=(f[i-1][j]*j%mo+f[i-1][j-1])%mo;
		}
	}
	c[0][0]=1;
	for (i=1;i<=n;i++){
		c[i][0]=1;
		for (j=1;j<=n;j++){
			c[i][j]=(c[i-1][j]+c[i-1][j-1])%mo;
		}
	}
	for (i=0;i<=n;i++){
        g=0;
        for (j=0;j<=i;j++){
            g+=ksm(ksm(2,n-i,mo),j,mo)*f[i+1][j+1];
        	g%=mo;
        }
        g=g*ksm(2,ksm(2,n-i,mo-1),mo)%mo*c[n][i]%mo;
    	if (i&1)res-=g;
    	else res+=g;
    }
	res=(res%mo+mo)%mo;
	printf("%lld\n",res);
	return 0;
}