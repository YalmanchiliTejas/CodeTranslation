#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;

long long N ,k;
long long res;

long long max_ (long long a, long long b) {return a < b ? b : a;}

int main () {
    scanf("%lld%lld", &N, &k);N++;
    for (long long b = k + 1;b < N; ++b) {
	long long x = b - k;
	res += N / b * x + max_(0, N - N / b * b - k);
    }
    printf("%lld\n", res - (!k) * (N - 1));
    return 0;
}
