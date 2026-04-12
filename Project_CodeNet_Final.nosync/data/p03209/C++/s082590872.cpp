#include <iostream>
#include <cstdio>
#define N 55
using namespace std;

typedef long long ll;
ll n, x, d1[N]{1}, d2[N]{1};

ll f(ll p) {
	ll re = 0;
	if (x <= 0) return 0;
	if (d1[p] <= x) {x -= d1[p]; return d2[p];}
	x--;
	re += f(p - 1) + f(0) + f(p - 1);
	x--;
	return re;
}

int main()
{
	ll i;
	cin >> n >> x;
	for (i = 1; i <= n; i++) {
		d1[i] = d1[i - 1] * 2 + 3;
		d2[i] = d2[i - 1] * 2 + 1;
	}
    cout << f(n) << endl;
    return 0;
}