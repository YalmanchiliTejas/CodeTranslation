#include <bits/stdc++.h>

using namespace std;

#define all(x) x.begin(), x.end()
#define inf ((int) 1e9)
#define Linf ((long long) 1e18)

typedef long long ll;
typedef long double ld;

const int N = 123456;
const int M = 1234567;
const int P = 400004;
const int A = 256;

ll ncr(int n, int r){

	if(n < r)
		return 0;

	if(n < 0 || r < 0)
		return 0;

	if(n == r)
		return 1;

	return ncr(n - 1, r - 1) + ncr(n - 1, r);
}


void qsort(auto * a, int i, int j){

	if(i >= j) return;

	int l = i;
	int r = j;

	while(r > l){ 

		while(r > l && a[r] >= a[l]) r--;

		if(a[r] < a[l]){
			swap(a[r], a[l]);
		}

	}	

	qsort(a, i, r - 1);
	qsort(a, r + 1, j);

	return;
}


auto bpow(auto base, auto exp, auto MOD){

	ll ans = 1;
	for(; exp; exp>>=1){
		if(exp & 1)
			ans = (ans * base) % MOD;
		base = (base * 1ll * base) % MOD;
	}

	return ans;
}

int main(int argc, char const *argv[])
{
	
	#ifdef Cyborg1o1
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif	

	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int a, b, c;
	cin >> a >> b >> c;

	int num = a * 100 + b * 10 + c;

	if(num % 4 == 0)
		puts("YES");
	else
		puts("NO");

	return 0;					
}