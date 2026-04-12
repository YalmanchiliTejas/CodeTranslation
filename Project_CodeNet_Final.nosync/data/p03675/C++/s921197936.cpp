#include <cstdio>

using namespace std;

int a[200000];
int b[200000];

int main() {
    int n, i, j, k;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    
    for (i = n - 1, j = 0, k = n - 1; i >= 0; ) {
        b[j++] = a[i--];
        if (i >= 0) b[k--] = a[i--];
    }
    
    for (i = 0; i < n; i++) {
        if (i > 0) putchar(' ');
        
        printf("%d", b[i]);
    }
    puts("");
    
    return 0;
}
