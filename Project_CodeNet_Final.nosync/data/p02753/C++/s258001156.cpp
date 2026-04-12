#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define watch(x) cout << #x << " is " << x << endl;
#define print(a, l, r) \
    for (int i = l; i < r; i++) cout << a[i] << (i == (r - 1) ? endl : " ");
const long long M = 1000000007;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    cin >> s;

    int a = 0, b = 0;
    for (auto c : s) {
        if ((c - 'A') == 0) {
            a++;
        } else if ((c - 'A') == 1) {
            b++;
        }
    }
    /*  watch(a);
    watch(b); */
    if (a == 0 || b == 0) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
    }
}
