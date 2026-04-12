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
    string w = "aeiou";
    char c;
    cin >> c;
    if (w.find(c) != w.npos)
        cout << "vowel";
    else
        cout << "consonant";
}
