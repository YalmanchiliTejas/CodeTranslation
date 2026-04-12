#include <bits/stdc++.h>
#define FAST_IO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)

using namespace std;
typedef long long ll;

int main()
{
    FAST_IO;
    int n;
    cin >> n;
    int gr = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x >= gr) {
            gr = x;
            ans++;
        }
    }
    cout << ans << endl;

    return 0;
}