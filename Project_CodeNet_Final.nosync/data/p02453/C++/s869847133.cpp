#include <bits/stdc++.h>
using namespace std;
int main(void) {
    vector<int> set;
    int n,a,q,k;
    cin >> n;
    for (int i=0;i<n;i++) {
        cin >> a;
        set.emplace_back(a);
    }
    auto begin = set.begin();
    auto end = set.end();
    cin >> q;
    for (int j=0;j<q;j++) {
        cin >> k;
        auto itr = lower_bound(begin,end,k);
        cout << itr-begin << endl;
    }
}

