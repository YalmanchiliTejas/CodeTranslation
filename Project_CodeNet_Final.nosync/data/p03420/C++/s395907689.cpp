#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i, x, n) for(int i = x; i < (int)(n); ++i)

int main(){
	int n, k;
	scanf("%d%d", &n, &k);
	ll an = 0;
	f(b, k + 1, n + 1){
		int ln = b - k;
		an += n / b * (ll)ln;
		int lft = n % b;
		an += max(0, lft - k + 1);
	}
	if (k == 0)an -= n;
	printf("%lld\n", an);
}