#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int, int> ii;
#define DEBUG freopen("in.txt", "r", stdin);

struct fastio {
    fastio() {
        ios::sync_with_stdio(false);
        cout << setprecision(10) << fixed;
        cin.tie(0);
    }
};

fastio _fast_io;

int a, b, c;
int main() {
    cin >> a >> b >> c;
    int d = a * 100 + b * 10 + c;
    if (d % 4 == 0)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}
