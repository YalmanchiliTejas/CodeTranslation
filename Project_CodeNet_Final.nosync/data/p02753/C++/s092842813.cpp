#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 1e5 + 10;
const int MAX = 1e5 + 10;

inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a > b ? b : a; }

int main() {
    string str;
    cin >> str;
    if (str.find('A') != str.npos && str.find('B') != str.npos) {
        cout << "Yes";
    } else {
        cout << "No";
    }
}