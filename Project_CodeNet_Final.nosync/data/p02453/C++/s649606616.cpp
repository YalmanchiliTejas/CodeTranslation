#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define r(i, n) for(int i=0;i<n;i++)

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    r(i, n) cin >> v[i];
    int q, x, p;
    cin >> q;
    while (q--) {
        cin >> x;
        p = lower_bound(v.begin(), v.end(), x) - v.begin();
        cout << p << endl;
    }
    return 0;
}
