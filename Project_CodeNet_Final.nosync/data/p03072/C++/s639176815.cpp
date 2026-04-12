#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    int N;
    cin >> N;
    int mx = 0, ans = 0;
    for (int i = 0; i < N; ++i) {
        int a;
        cin >> a;
        if (a>=mx)
            ans++;
        mx=max(mx,a);
    }
    cout << ans << endl;
    return 0;
}
