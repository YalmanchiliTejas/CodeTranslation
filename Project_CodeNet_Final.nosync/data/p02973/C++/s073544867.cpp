#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define rep(i,n) for (int i = 0; i < (n); i++)
const ll mod = 1000000007;

int main() {
    int n;
    cin >> n;
    int a[n];
    rep(i,n) cin >> a[i];
    multiset<int> Set;
    Set.insert(-1);
    int ai;
    rep(i,n) {
        ai = a[i];
        auto itr1 = Set.lower_bound(ai);
        if (itr1 == Set.begin()) Set.insert(ai);
        else {
            itr1--;
            Set.erase(itr1);
            Set.insert(ai);
        }
    }
    cout << Set.size() << endl;
    return 0;
}