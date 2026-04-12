#include <bits/stdc++.h>
using namespace std;
using Int = long long;
int PREP = (cin.tie(nullptr), ios::sync_with_stdio(false), cout << fixed << setprecision(9), 0);
//int SEGV = getenv("D") || (exit(system("D= SEGFAULT_SIGNALS=all catchsegv ./prog.exe") >> 8), 0);
int main() {
    int X; cin >> X;
    if (X >= 30) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
    return 0;
}