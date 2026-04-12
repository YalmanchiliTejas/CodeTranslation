#include<iostream>
#include<string>
#define NO 0
#define S 1
#define W 2
using namespace std;

const int MAX_N = 1e+5 + 5;

int animals[MAX_N];

int main() {
    int N;
    string s;
    cin >> N >> s;
    // 1番目と2番目の動物を固定して全探索
    for (int i = 1; i < 3; i++) {
        for (int j = 1; j < 3; j++) {
            // 0とN+1にはそれぞれN番目と1番目の動物が入る
            for (int k = 0; k <= N + 1; k++) animals[k] = NO;
            animals[1] = animals[N + 1] = i, animals[2] = j;
            if (animals[1] == S) {
                if (s[0] == 'o') animals[0] = j;
                else {
                    if (animals[2] == S) animals[0] = W;
                    else animals[0] = S;
                }
            }
            else {
                if (s[0] == 'x') animals[0] = j;
                else {
                    if (animals[2] == S) animals[0] = W;
                    else animals[0] = S;
                }
            }
            for (int k = 2; k <= N; k++) {
                if (animals[k] == S) {
                    if (s[k - 1] == 'o') animals[k + 1] = animals[k - 1];
                    else {
                        if (animals[k - 1] == S) animals[k + 1] = W;
                        else animals[k + 1] = S;
                    }
                }
                else {
                    if (s[k - 1] == 'x') animals[k + 1] = animals[k - 1];
                    else {
                        if (animals[k - 1] == S) animals[k + 1] = W;
                        else animals[k + 1] = S;
                    }
                }
                if (k == N) {
                    if (animals[0] == animals[N] && animals[N + 1] == animals[1]) {
                        for (int l = 1; l <= N; l++) {
                            cout << (animals[l] == S ? 'S' : 'W');
                        }
                        cout << endl;
                        return 0;
                    }
                }
            }
        }
    }
    cout << -1 << endl;
    return 0;
}