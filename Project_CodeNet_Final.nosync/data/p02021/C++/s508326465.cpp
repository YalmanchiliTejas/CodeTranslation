#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
    int n, t, avg, mintask = 10001,sum = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &t); sum += t;
        avg = sum / i;
        mintask = min(mintask, avg);
    }
    printf("%d\n", mintask);
    return 0;
}
