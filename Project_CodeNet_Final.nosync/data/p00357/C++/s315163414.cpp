#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(a) (a).begin(),(a).end()
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) {
        cin >> a[i];
    }
    int M = 0;
    bool cheak = true;
    rep(i, n) {
        if (i > M) cheak = false;
        int D = a[i] / 10;
        M = max(M, i + D);
    }
    reverse(all(a));
    M = 0;
    rep(i, n) {
        if (i > M) cheak = false;
        int D = a[i] / 10;
        M = max(M, i + D);
    }
    puts((cheak) ? "yes" : "no");
    return 0;
}
