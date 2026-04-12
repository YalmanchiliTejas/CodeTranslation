#include <iostream>
#include <string>
using namespace std;

const int INF = 10000000;
const int MX_N = 100000;
int n;
string s;
char sw[MX_N + 1];

char pat_0[4] = {'S', 'S', 'W', 'W'}, pat_1[4] = {'S', 'W', 'S', 'W'};

bool check() {
    bool last_match = false;
    for (int i = 2; i <= n; i++) {
        if ((sw[i - 1] == 'S' && s[i - 1] == 'o') ||
            (sw[i - 1] == 'W' && s[i - 1] == 'x')) {
            sw[i] = sw[i - 2];
        } else {
            if (sw[i - 2] == 'S') sw[i] = 'W';
            else
                sw[i] = 'S';
        }
    }

    last_match = (sw[0] == sw[n]);

    int f_count = 0;
    if (sw[0] != 'S') f_count++;
    if (s[0] != 'o') f_count++;
    if (sw[1] != sw[n - 1]) f_count++;

    if (last_match * (f_count % 2 == 0)) return true;
    else
        return false;
}

int main() {
    cin >> n >> s;
    bool have_comb = false;

    for (int i = 0; i < 4; i++) {
        sw[0] = pat_0[i];
        sw[1] = pat_1[i];
        have_comb = check();
        if (have_comb) break;
    }

    if (have_comb) {
        for (int i = 0; i < n; i++) cout << sw[i];
        cout << endl;
    } else
        cout << "-1" << endl;

    return 0;
}