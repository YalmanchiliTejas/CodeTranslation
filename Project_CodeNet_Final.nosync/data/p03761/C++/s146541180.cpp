#include <iostream>
#include <algorithm>

using namespace std;

#define LEN 'z'-'a'+1
int chs[LEN], chs2[LEN];

void solve() {
    int n;
    char c;
    cin >> n;
    for (int j = 0; j < LEN; ++j)
        chs[j] = 1000000;
    c  = getchar();
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < LEN; ++j) {
            chs2[j] = 0;
        }
        while ((c = getchar()) != '\n') {
            ++chs2[c - 'a'];
        }
        for (int j = 0; j < LEN; ++j) {
            chs[j] = min(chs[j], chs2[j]);
        }
    }
    for (int i = 0; i < LEN; ++i) {
        for (int j=0; j < chs[i]; ++j)
            cout << char('a'+i);
    }
    //cout << endl;


}

int main() {

    solve();
    return 0;
}
