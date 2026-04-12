#include <cstdio>

int a[300000];


int main(void) {
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++)
        scanf("%d", &a[i]);
    n--;

    for(int i=n; i>=0; i-=2)
        printf("%d ", a[i]);
    for(int i=1-(n%2); i<=n; i+=2)
        printf("%d ", a[i]);
    return 0;

}