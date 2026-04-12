#include <iostream>

using namespace std;

int main() {
    int N;
    char str[100001];
    cin >> N >> str;
    for (int i = 0; i < 4; i++) {
        char ans[100001];
        int s = i;
        for (int j = 0; j < N; j++) {
            int f0 = s / 2;
            int f1 = s % 2;
            int f2 = f0 ^ (str[j] == 'o' ? 0 : 1);
            ans[(j+1) % N] = f2 == 0 ? 'S' : 'W';
            s = ((f1 ^ f2) << 1) | f2;
        }
        if (i == s) {
            ans[N] = '\0';
            cout << ans << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}
