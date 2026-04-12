#include <bits/stdc++.h>
#pragma optimize("-O2")
#define pb push_back
#define fi first
#define se second
#define SIZE 10000
#define PAD 250
#define MOD 1000000000LL
#define MAXV 200111
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef vector<vector<long long> > mat;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<long long> vll;

ll n, a[200111];

int main () {
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)	scanf("%lld",a+i);
	if(n % 2LL == 0) {
		for(int i=0;i<n/2;i++)	printf("%lld ",a[n - 2*i]);
		for(int i=1;i<=n/2;i++)	printf("%lld ",a[2*i-1]);
	}
	else {
		for(int i=0;i<=n/2;i++)	printf("%lld ",a[n - 2*i]);
		for(int i=1;i<=n/2;i++)	printf("%lld ",a[2*i]);
	}
printf("\n");
}