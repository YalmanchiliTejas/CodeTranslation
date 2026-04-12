#include <bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define space putchar(' ')
#define enter putchar('\n')
#define eps 1e-10
#define MAXN 200005
//#define ivorysi
using namespace std;
typedef long long int64;
typedef unsigned int u32;
typedef double db;
template<class T>
void read(T &res) {
    res = 0;T f = 1;char c = getchar();
    while(c < '0' || c > '9') {
	if(c == '-') f = -1;
	c = getchar();
    }
    while(c >= '0' && c <= '9') {
	res = res * 10 +c - '0';
	c = getchar();
    }
    res *= f;
}
template<class T>
void out(T x) {
    if(x < 0) {x = -x;putchar('-');}
    if(x >= 10) {
	out(x / 10);
    }
    putchar('0' + x % 10);
}
const int MOD = 1000000007;
int N,M,L;
char s[MAXN];
bool flag = 0;
int f[MAXN][2],dp[MAXN],sum[MAXN][2];
int inc(int a,int b) {
    return a + b >= MOD ? a + b - MOD : a + b;
}
int mul(int a,int b) {
    return 1LL * a * b % MOD;
}
void update(int &x,int y) {
    x = inc(x,y);
}
void Solve1() {
    int ans = 0;
    f[1][1] = 1;f[1][0] = 1;
    for(int i = 2 ; i <= N ; ++i) {
	f[i][0] = f[i - 1][1];
	f[i][1] = inc(f[i - 1][1],f[i - 1][0]);
    }
    ans = inc(f[N][0],f[N][1]);
    memset(f,0,sizeof(f));
    f[1][0] = 1;
    for(int i = 2 ; i < N ; ++i) {
	f[i][0] = f[i - 1][1];
	f[i][1] = inc(f[i - 1][1],f[i - 1][0]);
    }
    ans = inc(ans,MOD - f[N - 1][1]);
    out(ans);enter;
}
void Solve2() {
    dp[0] = 1;sum[0][0] = 1;
    for(int i = 1 ; i <= N ; ++i) {
	if(i >= 2) {
	    int t = sum[i - 2][i & 1];
	    if(i > L + 1) update(t,MOD - sum[i - L - 2][i & 1]);
	    dp[i] = t;
	}
	sum[i][0] = sum[i - 1][0];sum[i][1] = sum[i - 1][1];
	sum[i][i & 1] = inc(sum[i][i & 1],dp[i]);
	
    }
    int ans = dp[N];
    for(int i = 1 ; i <= L ; i += 2) {
	update(ans,mul(i,dp[N - i - 1]));
    }
    out(ans);enter;
}
void Init() {
    read(N);read(M);
    scanf("%s",s + 1);
    while(M >= 1 && s[M] == s[1]) --M;
    L = N;
    if(M == 0) flag = 1;
    else {
	for(int i = 1 ; i <= M ; ++i) {
	    if(s[i] != s[1]) continue;
	    else {
		int j = i;
		while(s[j + 1] == s[1]) ++j;
		int t = j - i + 1;
		if(i == 1) {
		    if(t % 2 == 0) L = min(L,t + 1);
		    else L = min(L,t); 
		}
		else {
		    if(t % 2 == 1) L = min(L,t);
		}
		i = j;
	    }
	}
    }
    if(L == N) flag = 1;
    if(flag) Solve1();
    else Solve2();
}
int main() {
#ifdef ivorysi
    freopen("f1.in","r",stdin);
#endif
    Init();
}
