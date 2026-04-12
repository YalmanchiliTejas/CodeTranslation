#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

//Do not get frustrated over WA. Check for edge cases and runtime errors :)
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    cin >> s;
    ll a = count(s.begin(), s.end(), 'A');
    ll b = count(s.begin(), s.end(), 'B');
    if (a == 0 || b == 0) cout << "No";
    else cout << "Yes";
    return 0;
}
