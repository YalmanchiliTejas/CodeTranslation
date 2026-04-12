#include <algorithm>
#include <iostream>
using namespace std;

bool exor(bool a, bool b) {
    return a != b;
}

int encode[128];
char decode[4] = "SW";
char ans[101010];

int N;
string S;

int main() {
    encode[(int)'S'] = 0; encode[(int)'W'] = 1;

    cin >> N >> S;

    for (int j = 0; j < 2; ++j) {
        for (int k = 0; k < 2; ++k) {
            ans[0] = (j == 0) ? 'S' : 'W';
            ans[1] = (k == 0) ? 'S' : 'W';

            for (int l = 2; l < N; ++l) {
                if (exor(S[l-1] == 'o', ans[l-1] != 'S')) {
                    ans[l] = ans[l-2];
                } else {
                    ans[l] = decode[1-encode[(int)ans[l-2]]];
                }
            }

            char a0 = exor(S[N-1] == 'o', ans[N-1] != 'S') ?
                        ans[N-2] : decode[1-encode[(int)ans[N-2]]];
            if (a0 != ans[0]) { continue; }

            char a1 = exor(S[0] == 'o', ans[0] != 'S') ?
                        ans[N-1] : decode[1-encode[(int)ans[N-1]]];
            if (a1 != ans[1]) { continue; }
            cout << ans << endl;
            return 0;
        }
    }
    cout << "-1" << endl;

    return 0;
}
