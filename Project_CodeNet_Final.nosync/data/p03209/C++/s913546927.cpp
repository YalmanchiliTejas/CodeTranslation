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

int p[100000];
int y[100000];
int z[100000];
int ans[100000];
ll b[51][2];

int diff[4][2] = {
	{ 0, -1 },
	{ -1, 0 },
	{ 1, 0 },
	{ 0, 1 },
};

int Min(int a, int b) {
	return (a)<(b) ? (a) : (b);
}
int  Max(int  a, int  b) {
	return (a) > (b) ? (a) : (b);
}
void Swap(int *a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}void hSwap(int x[], int i, int j)
{
	int temp;

	temp = x[i];
	x[i] = x[j];
	x[j] = temp;
}

void ShowData(int x[], int left, int right)
{
	int i;
	for (i = left; i <= right; i++)printf("%d  ", x[i]);
	printf("\n");
}
void QSort(int x[], int left, int right, int n) {
	int i, j;	//左端,右端
	int pivot;	//軸

	i = left;
	j = right;
	pivot = x[(left + right) / 2];

	while (1) {
		if (n > 0) {				//n>0なら昇順、n<=0なら降順
			while ((x[i] < pivot) && (i <= right))i++;	//軸値より大きい要素
			while ((pivot < x[j]) && (i <= right))j--;	//軸値より小さい要素
		}
		else {
			while ((x[i] > pivot) && (i <= right))i++;	//軸値より小さい要素
			while ((pivot > x[j]) && (i <= right))j--;	//軸値より大きい要素
		}
		if (i >= j)	break;
		hSwap(x, i, j);
		i++; j--;
	}
	//ShowData(x, left, right);

	if (left < i - 1)QSort(x, left, i - 1, n);
	if (j + 1 <  right)QSort(x, j + 1, right, n);
}

int gcd(int a, int b) {
	if (b == 0)return a;
	int tmp = a%b;
	a = b;
	b = tmp;
	return gcd(a, b);
}

ll dfs(int n, ll x) {
	if (x < 1) {
		return 0;
	}
	else if (x >= b[n][0]) {
		return b[n][1];
	}
	else {
		ll v = 0;
		v+=dfs(n - 1, x - 1);
		if (x > b[n - 1][0] + 1)v++;
		if (x > b[n - 1][0] + 2) v += dfs(n - 1, x-(b[n - 1][0] + 2));
		return v;
	}
}


int main() {
	int n;
	ll x;
	scanf("%d%lld", &n,&x);
	b[0][0] = 1;
	b[0][1] = 1;
	REPS(i, n) {
		b[i][0] = b[i - 1][0] * 2 + 3;
		b[i][1] = b[i - 1][1] * 2 + 1;
	}
	ll ans=dfs(n,x);
	PRINTL(ans);
}