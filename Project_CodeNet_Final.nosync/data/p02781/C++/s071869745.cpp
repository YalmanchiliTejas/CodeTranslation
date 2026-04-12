#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
#define rep(a,b,c) for(int a=b;a<=c;a++)
#define int __int128
#define min(a,b) a<b?a:b 
template<class T>inline void read(T& x) {
	T f=1;x=0;char s=getchar();
	while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
	while(s>='0'&&s<='9'){x=(x<<1)+(x<<3)+(s&15);s=getchar();}
	x*=f;
}
inline void print(int x,char s) {
    if(x>=10) { print(x/10,'S'); }
    putchar(x%10+'0');
    if(s!='S') putchar(s);
}
inline void print(int x) {
    if(x>=10) { print(x/10); }
    putchar(x%10+'0');
}
template<class T>inline T fabs(T a) { return a>0?a:-a; }
char s[102];
int n,num[102],x,f[102][4];
inline int dfs(int k,int sx,int cnt) {
	if(k>n) return (cnt==x);
	if(cnt>x) return 0;
	if(!sx&&f[k][cnt]) return f[k][cnt];
	int mx,ans=0;
	if(sx) mx=num[k];
	else mx=9;
	rep(i,0,mx) {
		if(i==0) ans+=dfs(k+1,(sx&&(i==mx)),cnt);
		else ans+=dfs(k+1,(sx&&(i==mx)),cnt+1);
	}
	return f[k][cnt]=ans;
}
signed main() {
	scanf("%s",s+1);
	n=strlen(s+1);
	rep(i,1,n) num[i]=s[i]-'0';
	read(x);
	print(dfs(1,1,0));
}
