#include <bits/stdc++.h>
using namespace std;
int arr[20001];
int main() {

    int n, m, i;
    for (; ;) {
        i = 1;
        std::scanf("%d %d", &n, &m);
        if (n == 0 && m == 0) break;
        arr[0] = 0;
        for (; i <= n; i++) std::scanf("%d", &arr[i]);
        for (i = n+1; i <= n+m; i++) std::scanf("%d", &arr[i]);
        sort(arr, arr+n+m+1);
        int maxlen = 0;
        for (int i = 1; i <= n+m; i++) maxlen = max(maxlen, arr[i] - arr[i-1]);
        printf("%d\n", maxlen);
    }
    return 0;
}

