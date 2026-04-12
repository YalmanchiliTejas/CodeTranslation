#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    int h;
    int highest = 0;
    int res = 0;

    rep(i, n){
        cin >> h;
        if(h >= highest) ++res;
        highest = max(h, highest);
    }
    cout << res << endl;
}