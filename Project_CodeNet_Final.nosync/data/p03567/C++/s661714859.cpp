#include <bits/stdc++.h>
#define MOD 1000000007
#define endl "\n"
typedef long long ll;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cout.precision(10);
    string s;
    cin >> s;
    bool ac = s.find("AC") != string::npos;
    cout << (ac ? "Yes" : "No") << endl;
    return 0;
}