#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define dbg(x) cerr << #x << " = " << x << endl
#define _ << ' ' <<
using namespace std;
using ll = long long;
using vi = vector<int>;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    sort(all(s));
    s.resize(unique(all(s)) - s.begin());
    if (s.size() == 2)
        cout << "Yes";
    else
        cout << "No";
}
