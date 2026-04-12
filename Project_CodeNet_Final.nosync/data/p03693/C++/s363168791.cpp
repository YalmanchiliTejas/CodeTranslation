#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;
// Welcome to my source code!

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    cout << ((b * 10 + c) % 4 ? "NO" : "YES") << endl;
}