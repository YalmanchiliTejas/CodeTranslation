#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> A(n);
    for (auto &a: A) cin >> a;

    multiset<int> B;
    B.insert(-1);

    for (auto &a: A) {
        auto p = B.lower_bound(a);
        p--;
        if (*p >= 0)
            B.erase(p);
        B.insert(a);
    }

    cout << B.size() - 1 << endl;
}