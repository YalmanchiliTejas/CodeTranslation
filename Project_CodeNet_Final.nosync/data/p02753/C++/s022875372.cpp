#include <bits/stdc++.h>
using ll = long long;
using namespace std;
 
void solve() {
    string s;
    cin>>s;
    if(s[1] != s[0] || s[1] != s[2]) cout<<"Yes";
    else cout<<"No";
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(10);
    cout<<fixed;
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
#endif
    solve();
    return 0;
}
