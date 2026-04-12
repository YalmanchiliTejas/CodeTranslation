#include<bits/stdc++.h>
using namespace std;
#define res register int
#define ll long long
//#define cccgift
//#define getchar()(p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
//char buf[1<<21],*p1=buf,*p2=buf;
template<typename T>
inline void read(T &x)
{
    static char ch;bool f=1;
    for(x=0,ch=getchar();!isdigit(ch);ch=getchar()) if(ch=='-') f=0;
    for(;isdigit(ch);x=(x<<1)+(x<<3)+(ch^48),ch=getchar());x=f?x:-x;
}
template<typename T>
void print(T x)
{
    if (x<0) x=-x,putchar('-');
    if (x>9) print(x/10);
    putchar(x%10+48);
}
template<typename T>
inline void print(T x,char ap) {print(x);if (ap) putchar(ap);}
template<typename T>
inline void chkmax(T &x,const T &y) {x=x<y?y:x;}
template<typename T>
inline void chkmin(T &x,const T &y) {x=x<y?x:y;}
int f[101][4],n,k;
char s[101];
int dfs(int len,int ans,bool ff) {
	if(ans>k) return 0;
	int tot=0;
	if(!len) return ans==k;
	if(!ff&&~f[len][ans]) return f[len][ans];
	int end=ff?s[len]-'0':9;
	for(res i=0;i<=end;++i) tot+=dfs(len-1,ans+(i>0),ff&&i==end);
	if(!ff) f[len][ans]=tot;
	return tot;
}
int main()
{
	memset(f,255,sizeof(f)),scanf("%s",s+1),n=strlen(s+1),reverse(s+1,s+1+n),read(k),print(dfs(n,0,true),'\n');
	return 0;
}
/* stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?), set tle
    * do something instead of nothing and stay organized
*/ 