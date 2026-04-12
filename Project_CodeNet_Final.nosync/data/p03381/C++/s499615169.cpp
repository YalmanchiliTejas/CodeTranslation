#include<bits/stdc++.h>
using namespace std;
#define int long long
#define sz(x) (int)(x.size())
#define fi first
#define se second
#define pii pair<int, int>
const int N = 2e5 + 10;

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n;
    cin >> n;
    int a[n];
    int b[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b , b + n);
    for(int i = 0; i < n; i++) {
        int mid = n / 2 - 1;
        if(a[i] <= b[mid]) {
            cout << b[mid + 1] << "\n";
        }else {
            cout << b[mid] << "\n";
        }
    }
}