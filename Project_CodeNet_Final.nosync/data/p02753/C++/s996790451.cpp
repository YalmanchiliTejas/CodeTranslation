// Etavioxy
#include<cstdio>
#include<cctype>
#include<algorithm>
#include<cstring>
#include<cmath>
#define ll long long
#define il inline
#define rep(i,s,t) for(register int i=(s);i<=(t);i++)
#define rev_rep(i,s,t) for(register int i=(s);i>=(t);i--)
#define each(i,u) for(int i=head[u];i;i=bow[i].nxt)
#define file(s) freopen(s".in","r",stdin),freopen(s".out","w",stdout)
#define pt(x) putchar(x)
using namespace std;
il int ci(){
	register char ch; int f=1;
	while(!isdigit(ch=getchar())) f=ch=='-'?-1:1;
	register int x=ch^'0';
	while(isdigit(ch=getchar())) x=(x*10)+(ch^'0');
	return f*x;
}

//

char s[10];

int main(){
	scanf("%s",s+1);
	if( s[1]==s[2] && s[2]==s[3] ) puts("No");
	else puts("Yes");
	return 0;
}
