#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define mp make_pair
#define pb push_back
#define CL(x) ((x) * (x))
#define CR(x) (((x) * (x)) + 1)
typedef long long cc;
typedef pair <int, int> pii;

int main() {
    //freopen("input.inp", "r", stdin);
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string s;
    cin >> s;
    for (int i = 1; i < s.size(); i++)
    if (s[i] == 'C' && s[i - 1] == 'A') {
        cout << "Yes\n";
        return 0;
    }
    cout << "No";
    return 0;
}
