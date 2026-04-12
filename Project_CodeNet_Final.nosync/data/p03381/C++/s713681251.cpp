#include <bits/stdc++.h>
#define MOD 1000000007
#define endl "\n"
typedef long long ll;
using namespace std;

const int N = 222222;
pair<int, int> a[N];
int ans[N];
int n;

int main() {
    ios::sync_with_stdio(false);
    cout.precision(10);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i++) {
        if(i <= n / 2) {
            ans[a[i].second] = a[n / 2 + 1].first;
        } else {
            ans[a[i].second] = a[n / 2].first;
        }
    }
    for(int i = 1; i <= n; i++) {
        cout << ans[i] << endl;
    }
    return 0;
}
