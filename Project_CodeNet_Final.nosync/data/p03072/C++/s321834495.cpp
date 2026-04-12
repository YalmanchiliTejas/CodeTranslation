#include <bits/stdc++.h>
#define rep(i,a,n) for(int i=a; i<n; ++i)
#define ll long long int
#define vi vector<int>
using namespace std;

int n;
vi h;

int main() {
    cin >> n;
    h.resize(n);
    rep(i,0,n) cin >> h[i];
    int cnt=0;
    int _max = h[0];
    rep(i,0,n-1) {
        if (h[i]>=_max) cnt++;
        _max = (h[i+1]>_max) ? h[i+1] : _max;
    }
    if (h[n-1] >= _max) cnt++;
    cout << cnt << '\n';
    return 0;
}