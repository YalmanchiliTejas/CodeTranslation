#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 3e5 + 10;
int n;
int main() {
    cin >> n;
    multiset<int> s;
    for(int i = 0, x; i < n; i++) {
        cin >> x;
        auto it = s.lower_bound(x);
        if(it != s.begin()) {
            it--;
            s.erase(it);
            s.insert(x);
        } else {
            s.insert(x);
        }
    }
    cout << s.size() << '\n';
    return 0;
}