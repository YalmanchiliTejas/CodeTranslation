#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


int main() {
    char r, g, b;
    cin >> r >> g >> b;
    int num = (r - '0') * 100 + (g - '0') * 10 + (b - '0');
    if (num % 4 == 0) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
