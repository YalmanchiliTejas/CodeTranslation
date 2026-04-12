#include <bits/stdc++.h>

using namespace std;

int N;
long long X, H[51], P[51];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    H[0] = 1;
    P[0] = 1;
    for (int i = 1; i <= 50; i++) {
        H[i] = 3 + 2 * H[i - 1];
        P[i] = 1 + 2 * P[i - 1];
    }
    
    cin >> N >> X;
    long long res = 0;
    
    while(N > 0 && X > 0) {
        if (X >= 2 + 2 * H[N - 1]) {
            res += 1 + 2 * P[N - 1];
            X = 0;
            break;
        }
        if (X >= 2 + H[N - 1]) {
            res += 1 + P[N - 1];
            X -= 2 + H[N - 1];
        } else if (X == 1 + H[N - 1]) {
            res += P[N - 1];
            X -= 1 + H[N - 1];
        } else {
            X--;
        }
        N--;
    }
    
    if (X) {
        res++;
    }
    
    cout << res << endl;

}

