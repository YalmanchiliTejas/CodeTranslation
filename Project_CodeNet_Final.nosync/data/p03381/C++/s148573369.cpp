#include <bits/stdc++.h>
using namespace std;
  
#define ll long long
#define all(aaa) aaa.begin(), aaa.end()

const int N = 2e5 + 5;
pair<int, int> a[N];
int ans[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }

    sort(a, a + n);

    for (int i = 0; i < n; i++) {
        if (i < n / 2)
            ans[a[i].second] = a[n / 2].first;
        else
            ans[a[i].second] = a[n / 2 - 1].first;
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << "\n";
    }

    return 0;
}