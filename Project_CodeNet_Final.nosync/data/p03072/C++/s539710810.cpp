#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long ll;
int main() {
    // ifstream in("data1.txt");
    // cin.rdbuf(in.rdbuf());
    int N;
    cin >> N;
    vector<int> v(N);
    rep(i, N) cin >> v[i];

    int ans = 1;
    if(N == 1) {
        cout << ans << endl;
        return 0;
    }

    int max = v[0];
    for(int i = 1; i < N; i++) {
        if(max <= v[i]) {
            ans++;
            max = v[i];
        }
    }
    cout << ans << endl;
}
