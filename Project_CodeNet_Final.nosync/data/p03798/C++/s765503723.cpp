#include <bits/stdc++.h>
using namespace std;

#define times(n, i)      uptil(0, n, i)
#define rtimes(n, i)     downto((n) - 1, 0, i)
#define upto(f, t, i)    for(int _##i = (t), i = (f); i <= _##i; i++)
#define uptil(f, t, i)   for(int _##i = (t), i = (f); i <  _##i; i++)
#define downto(f, t, i)  for(int _##i = (t), i = (f); i >= _##i; i--)
#define downtil(f, t, i) for(int _##i = (t), i = (f); i >  _##i; i--)

#define ln << endl

const int MOD = 1e9 + 7;

int main() {
    int N; cin >> N;
    string O; cin >> O;

    times(2, a) times(2, b) {
        vector<bool> S(N + 2);
        S[0] = a; S[1] = b;

        times(N, i) {
            S[i+2] = S[i] == S[i+1] == (O[i] == 'o');
        }
        if(S[0] == S[N] && S[1] == S[N+1]) {
            times(N, i) cout << (S[i+1] ? 'S' : 'W');
            cout ln;
            return 0;
        }
    }

    cout << -1 ln;

    return 0;
}
