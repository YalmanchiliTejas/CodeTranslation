#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)x.size())
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=(a); i<=(b); i++)
#define per(i,a,b) for (register int i=(a); i>=(b); i--)
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
template<class T> inline void read(T &x){
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
template<class T> inline void umin(T &x, T y){x=x<y?x:y;}
template<class T> inline void umax(T &x, T y){x=x>y?x:y;}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 233333,mo=1e9+7;
int n,m,f[N],qz[N];char s[N];
void init(int n, int lim){//<=lim
	umin(lim,n);//f[i]=sigma f[i-1..i-lim]
	f[0]=1;qz[0]=1;
	rep(i,1,n){
		f[i]=(qz[i-1]-(i-lim-1>=0?qz[i-lim-1]:0)+mo)%mo;
		qz[i]=(qz[i-1]+f[i])%mo;
	}
}
int main() {
	read(n);read(m);scanf("%s",s+1);
	int cnt=0;rep(i,1,m)cnt+=s[i]=='R';
	if(cnt==0||cnt==m){
		static int f[N];
		f[0]=1;f[1]=2;rep(i,2,n)f[i]=(f[i-1]+f[i-2])%mo;
		printf("%d\n",(f[n-1]+(n-3>=0?f[n-3]:1))%mo);
		return 0;
	}
	if(n&1){puts("0");return 0;}
	int lim=1e9;int j;for(j=1;j<=m;j++)if(s[j]!=s[1])break;j--;
	if(j%2==0)lim=j+1;
	rep(i,1,m)if(s[i]==s[1]){
		int j;for(j=i;j<=m;j++)if(s[j]!=s[i])break;
		//[i,j-1]
		if((j-i)%2&&j-1<m)umin(lim,j-i);
		i=j-1;
	}
//	cerr<<lim<<endl;
	lim++;init(n/2,lim/2);int res=0;//%2==0
	for(int i=2;i<=min(lim,n);i+=2)res=(res+1LL*i*f[(n-i)/2])%mo;
	cout<<res;
	return 0;
}
