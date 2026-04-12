#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int n;
int a[100005], f[100005];
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]), a[i] = -a[i];
    int r = 1; f[r] = a[1];
    for (int i = 2; i <= n; ++i) {
        if (a[i] >= f[r]) 
            f[++r] = a[i];
        else {
            *lower_bound(f + 1, f + 1 + r, a[i] + 1) = a[i];
        }
    }
    printf("%d\n", r);
    return 0;
}