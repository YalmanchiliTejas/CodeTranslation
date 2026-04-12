/* Bismillahirrahmanirrahim */
/* Author : Jehian Norman Saviero (@Reiva5) */
#include <bits/stdc++.h>

// MACROS SAMPAH
#define Jehian using
#define Norman namespace
#define Saviero std

Jehian Norman Saviero;

// MACROS TYPE
typedef long l;
typedef long long ll;
typedef unsigned long ul;
typedef unsigned long long ull;
typedef double ld;
typedef pair<int,int> pi;
typedef pair<l,l> pl;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<l> vl;
typedef vector<ll> vll;

// MACROS FOR PRINT
#define nl printf("\n")
#define sp printf(" ")

// MACROS FOR ATTRIBUTE
#define fi first
#define se second

// MACROS FOR FUNCTION AND METHOD
#define eb emplace_back
#define mp make_pair
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define ALL(x) (x).begin(), (x).end()
#define ALLN(x,n) (x), (x)+(n)
#define CUBE(x) (SQR(x)*(x))
#define SET(x,y) fill_n(x, sizeof(x)/sizeof(x[0]), y)
#define SQR(x) ((x)*(x))
#define SSORT(x,sz) sort(ALLN(x,sz))
#define RESET(x) memset((x), 0, sizeof(x))
#define VSORT(x) sort(ALL(x))

// MACROS READ INPUT
#define sci(x) scanf("%d", &x)
#define scl(x) scanf("%ld", &x)
#define scll(x) scanf("%lld", &x)
#define scf(x) scanf("%f", &x)
#define scd(x) scanf("%lf", &x)
#define scld(x) scanf("%Lf", &x)
#define scul(x) scl(x)
#define scull(x) scll(x)

int main() {
	int N;
	sci(N);
	int arr[N];
	for (int i = 0; i < N; ++i) sci(arr[i]);
	int cnt = 0;
	int last = -1;
	for (int i = 0; i < N; ++i) {
		if (last <= arr[i]) {
			++cnt;
			last = arr[i];
		}
	}
	printf("%d\n", cnt);
	return 0;
}