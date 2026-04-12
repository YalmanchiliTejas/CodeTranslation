#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// string r = "4";
// string g = "3";
// string b = "2";
string r, g, b;

int main() {
    cin >> r >> g >> b;

    string num = "";
    num += r;
    num += g;
    num += b;

    // cout << stoi(num) << endl;
    if (stoi(num) % 4 == 0) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
}