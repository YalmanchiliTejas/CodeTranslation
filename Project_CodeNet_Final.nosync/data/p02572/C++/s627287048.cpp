#include<iostream>
#define MAXN 200500

using namespace std;

int a[MAXN];
long long b[MAXN];
const long long m = 1e9+7;

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    b[0] = a[n-1];
    for (int i = 1; i < n-1; ++i) {
        b[i] = b[i-1] + a[n-1-i];
        b[i] %= m;
    }
    int sum = 0;
    for (int i = 0; i < n-1; ++i) {
        sum += (int)((a[i]*b[n-2-i] % m));
        sum %= m;
    }
    cout << sum;
    return 0;
}
