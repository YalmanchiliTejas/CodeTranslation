#include<bits/stdc++.h>
#define rep(i,a,b) for (int i = (a); i <= (b); ++i)
#define drep(i,a,b) for (int i = (a); i >= (b); --i)
#define grep(i,u) for (int i = head[u],v = e[i].v; i; v = e[i = e[i].nxt].v)
#define il inline
#define LL long long
#define ULL unsigned LL
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
il LL read() {
	LL res = 0,f = 1; char ch = getchar(); while (!isdigit(ch)) {if (ch == '-') f = -f; ch = getchar();}
	while (isdigit(ch)) {res = res*10+ch-'0'; ch = getchar();} return res*f;
}
namespace qiqi {
	const int N = 3005; int n,P,c[N][N],s[N][N]; il int pow(int b,int k,int P) {int a = 1; while (k) {if (k&1) a = 1LL*a*b%P; b = 1LL*b*b%P; k >>= 1;} return a;}
	void main() {
		int ans = 0,x; n = read(); P = read(); s[0][0] = 1; rep(i,0,n+1) {c[i][0] = 1; rep(j,1,i) {c[i][j] = (c[i-1][j-1]+c[i-1][j])%P; s[i][j] = (s[i-1][j-1]+1LL*j*s[i-1][j]%P)%P;}}
		rep(i,0,n) {x = 0; rep(j,0,i) x = (x+1LL*s[i+1][j+1]*pow(pow(2,n-i,P),j,P)%P)%P; ans = (ans+(i&1?-1LL:1LL)*x*c[n][i]%P*pow(2,pow(2,n-i,P-1),P)%P)%P;} printf("%d\n",(ans+P)%P);
	}
}
int main() {
	qiqi::main(); return 0;
}