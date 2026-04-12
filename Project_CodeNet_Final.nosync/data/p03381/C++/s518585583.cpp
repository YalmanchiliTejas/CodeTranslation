#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n;
    vector<int> x, o;
    cin >> n;
    x.resize(n);
    o.resize(n);
    for (int  i = 0; i < n; i++) {
        cin >> x[i];
        o[i] = x[i];
    }
    sort(x.begin(), x.end());
    for (int i = 0; i < n; i++) {
        if (distance(x.begin(), lower_bound(x.begin(), x.end(), o[i])) < n / 2)
            cout << x[n / 2] << endl;
        else 
            cout << x[n / 2 - 1] << endl;
     }
}
