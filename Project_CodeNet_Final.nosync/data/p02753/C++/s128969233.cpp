#include <bits/stdc++.h>
typedef long long ll;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

using namespace std;

#define rep(i, a, b) for (int i = a; i < b; i++)
#define rrep(i, a, b) for (int i = a; i <= b; i++)
#define all(a)  begin((a)),end((a))
#define uniq(c) (c).erase(unique(all((c))), end((c)))

int main()
{
    string S; cin >> S;
    bool flg_A = false, flg_B = false;
    for (auto s : S) {
        if (s == 'A') flg_A = true;
        else if (s == 'B') flg_B = true;
    }

    if (flg_A and flg_B) cout << "Yes" << endl;
    else cout << "No" << endl;
}