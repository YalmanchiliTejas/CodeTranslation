#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;

int main() {
    int r, g, b; cin >> r >> g >> b;
    int sum = r * 100 + g * 10 + b;
    if(sum % 4 == 0) cout << "YES" << endl;
    else cout << "NO" << endl;

}
