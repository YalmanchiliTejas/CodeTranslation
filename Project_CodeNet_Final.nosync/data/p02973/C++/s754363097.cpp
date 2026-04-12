#include<bits/stdc++.h>
using namespace std;
int n, a, ans = 0;
multiset<int> s;
int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        scanf("%d", &a);
        if(s.upper_bound(-a) == s.end()) {
            s.insert(-a);
            ans++;
        }
        else {
            s.erase(s.upper_bound(-a));
            s.insert(-a);
        }
    }
    cout << ans;
}