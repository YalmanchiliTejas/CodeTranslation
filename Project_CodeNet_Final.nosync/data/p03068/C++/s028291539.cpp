#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define _ << ' ' <<
using namespace std;
using ll = long long;


int main()
{
    int n;
    string s;
    int k;
    cin >> n >> s >> k;
    k--;
    for (int i = 0; i < n; ++i)
        cout << (s[i] == s[k] ? s[i] : '*');
}
