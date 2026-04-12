#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<cctype>
#define REP(i,a,b) for(register int i=(a); i<(b); i++)
#define REPE(i,a,b) for(register int i=(a); i<=(b); i++)
#define PERE(i,a,b) for(register int i=(a); i>=(b); i--)
using namespace std;
typedef long long ll;
/*char buf[1<<21], *p1=buf, *p2=buf;
#define getchar() (p1==p2 && (p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
template <class T> inline void read(T&x) {
	x=0; char ch; do ch=getchar(); while(ch<=' ');
	while(ch>' ') {x=x*10+ch-'0'; ch=getchar();}
}*/
#define MAXN 200007
char N[107], *p;
int k;
int l;
int C(int i, int j) {
	if(i<j) return 0;
	int ans=1;
	REP(k,0,j) ans*=i--;
	while(j) ans/=j--;
	return ans;
}
int calc2(int i, int k) {
	int p=1;
	REP(j,0,k) p*=9;
	return C(l-i,k)*p;
}
int calc1(int i, int k) {
	if(k==0) return 1;
	int ans=0;
	ans += calc2(i+1,k);
	/*1..p[i]-1*/if(p[i]>'1') ans+=(p[i]-'1')*calc2(i+1,k-1);
	int t=i+1; while(p[t]=='0') t++;
	if(t<l) {
		/*p[i]*/ans+=calc1(t,k-1);
	} else if(k==1) ans++;
	return ans;
}
int main() {
	//memset(dp,-1,sizeof dp);
	scanf("%s", N); p=N;
	while(*p=='0') p++;
	scanf("%d", &k);
	l=strlen(p);
	int ans=0;
	ans = calc1(0,k);
	printf("%d\n", ans);
	return 0;
}

