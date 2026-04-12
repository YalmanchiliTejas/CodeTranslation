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

//printf
#define PRINTD(d) printf("%d\n",(d))
#define PRINTL(d) printf("%lld\n",(d))

//memset
#define m0(s) memset(s,0,sizeof(s))
#define ml(s) memset(s,63,sizeof(s))
#define fill(s,c) memset(s,c,sizeof(s))

#define INF 1e9

typedef long long ll;

int diff[4][2] = {
	{ 0, -1 },
	{ -1, 0 },
	{ 1, 0 },
	{ 0, 1 },
};

int Min(int a, int b) {
	return (a)<(b) ? (a) : (b);
}
ll Max(ll a, ll b) {
	return (a) > (b) ? (a) : (b);
}
void Swap(int *a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int main(){
	int h,w;
	scanf("%d%d", &h,&w);
	char a[100][101];
	REP(i, h) {
		scanf("%s", a[i]);
	}
	int f[100][2] = { 0 };
	REP(i, h) {
		int flag = 0;
		REP(j, w) {
			if (a[i][j] == '#') {
				flag = 1;
				break;
			}
		}
		if (!flag)f[i][0] = 1;
	}
	REP(i, w) {
		int flag = 0;
		REP(j, h) {
			if (a[j][i] == '#') {
				flag = 1;
				break;
			}
		}
		if (!flag)f[i][1] = 1;
	}
	REP(i, h) {
		if (f[i][0])continue;
		REP(j, w) {
			if (f[j][1])continue;
			printf("%c", a[i][j]);
		}
		puts("");
	}
	/*
	puts("");
	REP(i, 100) {
		printf("%d ", f[i][0]);
		printf("%d", f[i][1]);
		puts("");
	}*/
}