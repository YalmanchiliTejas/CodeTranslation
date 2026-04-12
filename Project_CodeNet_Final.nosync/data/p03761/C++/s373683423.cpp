#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int INF = 1 << 29;

const int N = 51;
const int A = 26;
int main() {
    int n;
    int a[N][A]{};
    int b[A];
    cin >> n;
    vector<string> vs;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        vs.push_back(s);
    }
    for (int i = 0; i < vs.size(); i++) {
        for (int j = 0; j < vs[i].size(); j++) {
            a[i][vs[i][j] - 'a']++;
        }
    }
    for (int i = 0; i < A; i++) {
        int m = INF;
        for (int j = 0; j < vs.size(); j++) {
            m = min(m, a[j][i]);
        }
        b[i] = m;
    }
    for (int i = 0; i < A; i++) {
        for (int j = 0; j < b[i]; j++) {
            printf("%c", i + 'a');
        }
    }
    printf("\n");
    return 0;
}
