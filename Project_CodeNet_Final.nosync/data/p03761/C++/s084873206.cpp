#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;
int main() {
    int n;
    string S, ans;
    cin >> n;
    vector<map<char, int>> vm(n);
    for (int i = 0; i < n; i++) {
        cin >> S;
        for (char c : S) {
            if (vm[i].find(c) != vm[i].end()) vm[i][c]++;
            else vm[i][c] = 1;
        }
    }
    for (char c = 'a'; c <= 'z'; c++) {
        int m = 51;
        bool f = true;
        for (int i = 0; i < n; i++) {
            int t = vm[i][c];
            if (t == 0) {
                f = false;
                break;
            }
            if (t < m) m = t;
        }
        if (f && m != 51) for (int i = 0; i < m; i++) ans += c;
    }
    cout << ans << endl;
}