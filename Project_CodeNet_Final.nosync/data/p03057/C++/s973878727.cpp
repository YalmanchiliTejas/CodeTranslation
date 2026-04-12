#include <bits/stdc++.h>
#define clr(x) memset(x,0,sizeof x)
#define For(i,a,b) for (int i=(a);i<=(b);i++)
#define Fod(i,b,a) for (int i=(b);i>=(a);i--)
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define fi first
#define se second
#define outval(x) cerr<<#x" = "<<x<<endl
#define outtag(x) cerr<<"-----------------"#x"-----------------\n"
#define outarr(a,L,R) cerr<<#a"["<<L<<".."<<R<<"] = ";\
                    For(_x,L,R) cerr<<a[_x]<<" ";cerr<<endl;
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair <int,int> pii;
LL read(){
    LL x=0,f=0;
    char ch=getchar();
    while (!isdigit(ch))
        f=ch=='-',ch=getchar();
    while (isdigit(ch))
        x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
    return f?-x:x;
}
const int N=200005,mod=1e9+7;
int Pow(int x,int y){
	int ans=1;
	for (;y;y>>=1,x=(LL)x*x%mod)
		if (y&1)
			ans=(LL)ans*x%mod;
	return ans;
}
void Add(int &x,int y){
	if ((x+=y)>=mod)
		x-=mod;
}
void Del(int &x,int y){
	if ((x-=y)<0)
		x+=mod;
}
int Add(int x){
	return x>=mod?x-mod:x;
}
int Del(int x){
	return x<0?x+mod:x;
}
int n,m;
char s[N];
int dp[N],pre[N];
int main(){
	n=read(),m=read();
	cin>>(s+1);
	int p=1;
	while (p<=m&&s[p]==s[1])
		p++;
	p--;
	if (p==m){
		For(i,2,n)
			dp[i]=i;
		For(i,1,n){
			Add(dp[i],pre[i-2]);
			pre[i]=Add(pre[i-1]+dp[i]);
		}
		cout<<Add(dp[n]+1)<<endl;
		return 0;
	}
	if (n&1)
		return puts("0"),0;
	int maxlen=p+(~p&1);
	int las=p+1;
	For(i,p+2,m)
		if (s[i]!=s[1]){
			if ((i-las-1)&1)
				maxlen=min(maxlen,i-las-1);
			las=i;
		}
	n/=2,maxlen=(maxlen+1)/2;
	For(i,1,maxlen)
		dp[i]=i*2;
	For(i,1,n){
		Add(dp[i],Del(pre[i-1]-pre[max(0,i-maxlen-1)]));
		pre[i]=Add(pre[i-1]+dp[i]);
	}
	cout<<dp[n]<<endl;
	return 0;
}