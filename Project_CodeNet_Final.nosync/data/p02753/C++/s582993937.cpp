#include <bits/stdc++.h>
typedef long long ll; 
const ll mod = 1e9+7;
#define fo(i, n) for (int i = 0; i < n; i++)
#define sc(n) scanf("%d", &n) 
using namespace std;

void solve() {
    string s;
    cin >>s;
    if (s[0] != s[1] || s[1] != s[2] || s[2] != s[0]) printf("Yes");
    else printf("No");
}

int main() {
    int t = 1;
    //scanf("%d", &t);
    while (t--) {
        solve();
    }
    return 0;
}