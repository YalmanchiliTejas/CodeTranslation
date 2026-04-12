#define _CRT_SECURE_NO_WARNINGS

/* include ***********************/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

/* define *************************/
//for
#define REP(i,n) for(int i=0,i##_len=(int)(n);i<i##_len;i++)
#define REPS(i,n) for(int i=1,i##_len=(int)(n);i<=i##_len;i++)
#define RREP(i,n) for(int i=(int)(n)-1;i>=0;i--)
#define RREPS(i,n) for(int i=(int)(n);i>0;i--)
#define FOR(i,s,n) for(int i=(int)(s),i##_len=(int)(n);i<i##_len;i++)
#define RFOR(i,s,n) for(int i=(int)(s)-1,i##_len=(int)(n);i>=i##_len;i--)

//printf
#define PRINTD(d) printf("%d\n",(d))
#define PRINTL(d) printf("%lld\n",(d))

//memset
#define m0(s) memset(s,0,sizeof(s))
#define ml(s) memset(s,63,sizeof(s))
#define fill(s,c) memset(s,c,sizeof(s))

#define INF 1e9
#define MOD 1000000007

typedef long long ll;
typedef unsigned long long ull;

int diff[4][2] = {
	{ 0, -1 },
	{ -1, 0 },
	{ 1, 0 },
	{ 0, 1 },
};
//今回の変数
ll d[1000000];
ll e[3000000];

int Min(int a, int b) {
	return (a)<(b) ? (a) : (b);
}
int Max(int  a, int  b) {
	return (a) > (b) ? (a) : (b);
}
ll Minl(ll a, ll b) {
	return (a)<(b) ? (a) : (b);
}
ll Maxl(ll a, ll b) {
	return (a)>(b) ? (a) : (b);
}

int main() {
	int n;
	scanf("%d", &n);

	int h;
	int max = 0;
	int ans = 0;
	REP(i, n) {
		scanf("%d", &h);
		if (h >= max) {
			ans++;
			max = h;

		}
	}
		PRINTD(ans);
}