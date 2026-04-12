#include <bits/stdc++.h>
using namespace std;

int n, cur = 1, ans, sz;
int a[1<<20], p[1<<20];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    int f = n % 2, l = 0, r = n - 1;
    for (int i = n - 1; i >= 0; i--) {
        if (i % 2 == f) p[r--] = i;
        else p[l++] = i;
    }
    for (int i = 0; i < n; i++) cout << a[p[i]] << ' ';
}