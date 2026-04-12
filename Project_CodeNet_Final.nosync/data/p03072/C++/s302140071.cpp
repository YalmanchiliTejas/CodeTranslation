#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
using namespace std;
int main() {
    int n, h[30], max=0, cnt=0;
    cin >> n;
    rep(i, n){
        cin >> h[i];
    }
    rep(i, n){
        if (h[i] >= max) cnt++, max = h[i];
    }
    cout << cnt;
}