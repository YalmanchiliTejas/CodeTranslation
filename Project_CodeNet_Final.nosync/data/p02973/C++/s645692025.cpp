#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, a;
    cin >> n;
    vector<int> vec(200000, 0);
    auto ibegin = vec.end();
    for (int i=0; i<n; i++) {
        cin >> a;
        auto itr = lower_bound(ibegin, vec.end(), a);

        // cout << " " << itr-ibegin << endl;

        if (itr == ibegin) {
            // cout << "begin" << endl;
            ibegin--;
            *ibegin = a;
        }
        else {
            itr--;
            *itr = a;
        }
    }

    // for (int i=l; i<=r; i++) cout << vec[i] << endl;

    cout << vec.end()-ibegin << endl;

    return 0;
}
