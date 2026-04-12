#include <iostream>
#include <string>

using namespace std;

int main() {
    int N;
    cin >> N;

    string s;
    cin >> s;

    string ans;
    string cand[4] = {"SS", "SW", "WS", "WW"};
    for (int i = 0; i < 4; i++) {
        for (int j = 2; j <= N; j++) {
            if (cand[i][j - 1] == 'S' and s[j - 1] == 'o') {
                if (cand[i][j - 2] == 'S') {
                    cand[i] += 'S';
                } else {
                    cand[i] += 'W';
                }
            } else if (cand[i][j - 1] == 'S' and s[j - 1] == 'x') {
                if (cand[i][j - 2] == 'S') {
                    cand[i] += 'W';
                } else {
                    cand[i] += 'S';
                }
            } else if (cand[i][j - 1] == 'W' and s[j - 1] == 'o') {
                if (cand[i][j - 2] == 'S') {
                    cand[i] += 'W';
                } else {
                    cand[i] += 'S';
                }
            } else if (cand[i][j - 1] == 'W' and s[j - 1] == 'x') {
                if (cand[i][j - 2] == 'S') {
                    cand[i] += 'S';
                } else {
                    cand[i] += 'W';
                }
            }
        }

        if (cand[i][0] != cand[i][N]) {
            continue;
        }

        if ((cand[i][0] == 'S' and s[0]== 'o' and cand[i][N - 1] == cand[i][1])
            or (cand[i][0] == 'S' and s[0] == 'x' and cand[i][N - 1] != cand[i][1])
            or (cand[i][0] == 'W' and s[0] == 'o' and cand[i][N - 1] != cand[i][1])
            or (cand[i][0] == 'W' and s[0] == 'x' and cand[i][N - 1] == cand[i][1])) {
            ans = cand[i].substr(0, N);
            break;
        } 
    }

    if (ans.size() > 0) {
        cout << ans << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}