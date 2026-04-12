#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define tc(t) int t;cin >> t; while(t--)
#define pb push_back
#define fi first
#define se second
#define debug1(x) cerr << #x << " = " << x << '\n';
#define debug2(x, y) cerr << #x << " = " << x << "   " << #y << " = " << y << "\n";
#define _ ios_base::sync_with_stdio(0);cin.tie(NULL);

void solve() {
    string s;
    cin >> s;
    int a = 0, b = 0;
    int n = int(s.size());
    for(int i = 0; i<n; i++) {
        if(s[i] == 'A') a++;
        else if(s[i] == 'B') b++;
    }
    if(a == n || b == n) {
        cout << "No";
    }
    else {
        cout << "Yes";
    }
}

int main() {_
    int t = 1;
    //cin >> t;
    // Please remember to uncomment for taking test cases
    for(int i = 1; i<=t; i++) {
        solve();
    }
    return 0;
}
