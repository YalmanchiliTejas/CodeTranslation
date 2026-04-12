#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    multiset<int> s;
    while(n--) {
        int a;
        cin >> a;
        auto it = s.lower_bound(a);
        if(it == s.begin()) {
            s.insert(a);
        } else {
            --it;
            s.erase(it);
            s.insert(a);
        }
    }
    cout << s.size() << '\n';
}