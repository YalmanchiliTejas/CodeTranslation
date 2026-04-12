#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
const int maxn = 10005;
const int mod = 998244353;
int add(int x,int y) { x+=y; return x>=mod?x-mod:x; }
int sub(int x,int y) { x-=y; return x<0?x+mod:x; }
int mul(int x,int y) { return 1ll*x*y%mod; }
int sqr(int x) { return 1ll*x*x%mod; }
int fac[maxn],inv[maxn];
char s1[maxn],s2[maxn];
int n;
int f[maxn][maxn];
int GC(int x,int y) {  if(x<y) return 0;return mul(fac[x],mul(inv[y],inv[x-y])); }
int main() {
	fac[0] = 1; inv[0] = inv[1] = 1;
	for(int i=1;i<=10000;i++) fac[i] = mul(fac[i-1],i);
	for(int i=2;i<=10000;i++) inv[i] = mul(inv[mod%i],mod-mod/i);
	for(int i=1;i<=10000;i++) inv[i] = mul(inv[i-1],inv[i]);
	scanf("%s%s",&s1[1],&s2[1]); n = strlen(s1+1);
	int A=0,B=0;
	for(int i=1;i<=n;i++) if((s1[i]-'0')|(s2[i]-'0'))(s1[i]==s2[i] ?A++:B++);
	B/=2;
	if((!A)||(!B)) { printf("%d",sqr(fac[A+B])); return 0; }
	for(int i=0;i<=B;i++) f[0][i] = sqr(fac[i]);
	for(int i=1;i<=A;i++) {
		for(int j=1;j<=B;j++) {
			f[i][j] = add( mul(f[i][j-1],sqr(j)) , mul(f[i-1][j],mul(i,j)) );
		}
	}
//cerr<<f[A][B]<<endl;
	int ans = 0;
	for(int i=0;i<=A;i++) {
		ans = add(ans,mul(f[A-i][B],mul(GC(A,i),mul(GC(A+B,i),sqr(fac[i])))));
	}
	printf("%d",ans);
}