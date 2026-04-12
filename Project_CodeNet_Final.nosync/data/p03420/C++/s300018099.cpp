#include <cstdio>

int main() {
long long r = 0;
int i, n, m;
scanf("%d%d", &n, &m);
if (m == 0) {
printf("%lld\n", (long long)n * n);
return 0;
}
for (i = m + 1; i <= n; i++) {
r += n / i * (i - m);
if (n % i >= m) r += n % i - m + 1;
}
printf("%lld\n", r);
return 0;
}