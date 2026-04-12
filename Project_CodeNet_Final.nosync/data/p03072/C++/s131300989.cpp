#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<int> H(N);
    for(int &e : H) cin >> e;
    int ans = 0;
    for(int i = 0; i < N; i++) {
        bool ok = true;
        for(int j = 0; j < i; j++) if(H[j] > H[i]) ok = false;
        ans += ok;
    }
    cout << ans << endl;
    return 0;
}
