#include<bits/stdc++.h>
#define del(a,i) memset(a,i,sizeof(a))
#define ll long long
#define inl inline
#define il inl void
#define it inl int
#define ill inl ll
#define re register
#define ri re int
#define rl re ll
#define INF 0x3f3f3f3f
#define lowbit(x) (x&(-x))
#define mid ((l+r)>>1)
using namespace std;
template<class T>il read(T &x){
	x=0;int f=1;char k=getchar();
	for(;k>'9'||k<'0';k=getchar()) if(k=='-') f=-1;
	for(;k>='0'&&k<='9';k=getchar()) x=x*10+k-'0';
	x*=f;
}
template<class T>il _print(T x){
	if(x>9) _print(x/10);
	putchar(x%10+'0');
}
template<class T>il print(T x){
	if(x<0) putchar('-'),x=-x;
	_print(x);
}
const int N = 1e2+5;
int n,k,bit[N],cnt;
char s[N];
double dp[N][N];
double DFS(int pos,int pre,int limit,int num){
	if(!pos) return num==k;
	if(!limit&&pre&&dp[pos][num]!=-1)
		return dp[pos][num];
	int up=limit?bit[pos]:9;
	double ans=0;
	for(ri i=0;i<=up;++i)
		ans+=DFS(pos-1,pre||i,limit&&(i==up),num+(i!=0));
	if(pre&&!limit) dp[pos][num]=ans;
	return ans;
}
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	scanf("%s",s+1),read(k);
	n=strlen(s+1);
	for(ri i=0;i<=n;++i)
		for(ri j=0;j<=n;++j)
			dp[i][j]=-1;
	for(ri i=n;i;--i)
		bit[++cnt]=s[i]-'0';
	printf("%.0f",DFS(cnt,0,1,0));
	return 0;
}