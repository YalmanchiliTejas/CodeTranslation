#include <cstdio>

using namespace std;

long long a[50];

int main() {
    int n, i, j;
    long long ans = 0;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) scanf("%lld", &a[i]);
    
    while (1) {
        int f = 0;
        
        for (i = 0; i < n; i++) {
            if (a[i] >= n) {
                long long x = a[i] / n;
                
                f = 1;
                ans += x;
                
                for (j = 0; j < n; j++) {
                    if (j == i) {
                        a[j] -= x * n;
                    } else {
                        a[j] += x;
                    }
                }
            }
        }
        
        if (f == 0) break;
    }
    
    printf("%lld\n", ans);
    
    return 0;
}
