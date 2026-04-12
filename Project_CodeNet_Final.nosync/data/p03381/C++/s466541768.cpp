#include<bits/stdc++.h>
using namespace std;
int n, a[200001], b[200001];
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i){
        scanf("%d", &a[i]);
        b[i] = a[i];
    }
    sort(a + 1, a + n + 1);
    int sz = a[n / 2], sz1 = a[n / 2 + 1];
    for (int i = 1; i <= n; ++i){
        if (b[i] <= sz) printf("%d\n", sz1);
        else if (b[i] >= sz1) printf("%d\n", sz);
    }
    return 0;
}
