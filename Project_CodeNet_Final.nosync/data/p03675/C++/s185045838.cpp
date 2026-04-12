#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

int main() {
    int n;
    cin >> n;
    vector<int> res(n);
    vector<int> a(n);
    for(int i=0; i<n; ++i) {
        cin >> a[i];
    }
    if(n & 1) {
        for(int i=0; i<(n+1)/2; ++i) {
            res[i] = a[n-1-i*2];
        }
        for(int i=(n+1)/2; i<n; ++i) {
            res[i] = a[1+(i - (n+1)/2)*2];
        }
    } else {
        for(int i=0; i<n; ++i) {
            if(i < n/2) {
                res[i] = a[n-1-2*i];
            } else {
                res[i] = a[2*(i-n/2)];
            }
        }
    }
    for(int i=0; i<n; ++i) {
        cout << res[i] << " \n"[i == n-1] << flush;
    }
}
