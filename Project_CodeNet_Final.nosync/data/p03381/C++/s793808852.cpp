#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define INF 120000000

using namespace std;

typedef pair<int, int> P;
typedef long long int LL;

int main() {
    int n;
    cin >> n;
    vector<LL> a(n), x(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        x[i] = a[i];
    }
    sort(a.begin(), a.end());
    LL m1 = a[(n - 1) / 2], m2 = a[n / 2];

    for (int i = 0; i < n; i++) {
        if (x[i] <= m1) {
            cout << m2 << endl;
        } else {
            cout << m1 << endl;
        }
    }

    return 0;
}
