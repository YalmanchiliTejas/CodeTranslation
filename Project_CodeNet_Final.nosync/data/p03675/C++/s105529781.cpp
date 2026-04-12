#include <cstdio>
#include <algorithm>

int a[1000000];

int main(){
    int n;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);

    for (int i = n; i > 0; i -= 2)
        printf("%d ", a[i]);
    for (int i = 1 + n % 2; i <= n; i+=2)
        printf("%d ", a[i]);

    return 0;
}
