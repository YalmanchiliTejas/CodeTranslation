#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long ll;
#define watch(x) cout << #x << " is " << x << endl;
#define print(a, l, r) \
    for (int i = l; i < r; i++) cout << a[i] << (i == (r - 1) ? endl : " ");
const long long M = 1000000007;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int x;
    cin >> x;

    cout << ((x >= 30) ? "Yes" : "No") << endl;
    return 0;
}