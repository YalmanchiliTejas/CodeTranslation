//written by newbiechd
#include <cstdio>
using namespace std;
const int N = 100003;
char s[N], c;
int main() {
    register int n, k, i;
    scanf("%d%s%d", &n, s + 1, &k), c = s[k];
    for (i = 1; i <= n; ++i)
        putchar(s[i] == c ? c : '*');
    return 0;
}
