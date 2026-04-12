#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<int> v;
    for (int x: a) {
        if (v.empty()) {v.push_back(x); continue;}
        auto it = lower_bound(v.begin(), v.end(), x) - 1;
        if (it >= v.begin()) *it = x;
        else v.insert(v.begin(), x);
    }
    cout << v.size() << endl;
    return 0;
}