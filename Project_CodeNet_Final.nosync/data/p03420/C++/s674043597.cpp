#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int main() {
    long long a, b;
    cin >> a >> b;
    if (b == 0) {
	cout << a * a;
	return 0;
    }
    long long ans = 0;
    for (long long i = b + 1; i <= a; ++i) {
	ans += (a + 1) / i * (i - b);
	if ((a + 1) % i >= b) {
	    ans += (a + 1) % i - b;
	}
    }
    cout << ans;
    return 0;
}
