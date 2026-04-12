#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int N;
    cin >> N;
    vector <int> H(N);
    for (int i = 0; i < N; i++) {
        cin >> H[i];
    }
    int MaxH = 0;
    int Ans = 0;
    for (int i = 0; i < N; i++) {
        if (H[i] >= MaxH) {
            Ans++;
        }
        MaxH = max(MaxH, H[i]);
    }
    cout << Ans;
    return 0;
}

