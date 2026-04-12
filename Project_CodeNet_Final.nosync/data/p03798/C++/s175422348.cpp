#include <bits/stdc++.h>
// #include <atcoder/all>
#define ll long long int
#define ld long double
#define yorn(f) std::cout<<((f)?"Yes":"No")<<endl;
#define YORN(f) std::cout<<((f)?"YES":"NO")<<endl;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repi(i, n) for (ll i = 1; i < (ll)(n); i++)
#define all(x) (x).begin(), (x).end()
#define put(x) std::cout << x << endl;
#define println(x) std::cout << x << endl;
using namespace std;
// using namespace atcoder;


void Main()
{
    ll n;
    cin >> n;
    string s;
    cin >> s;

    rep(pat, 1 << 2) {
        string res(n, ' ');
        res[0] = pat & 1 ? 'W' : 'S';
        res[1] = pat & 2 ? 'W' : 'S';

        char res0 = res[0];
        for (int i = 1; i <= n - 1; i++) {
            bool same = s[i] == 'o';
            if (res[i] == 'W') {
                same = !same;
            }
            if (same) {
                res[(i+1)%n] = res[(i-1+n)%n];
            }
            else {
                res[(i+1)%n] = res[(i-1+n)%n] == 'S' ? 'W' : 'S';
            }
        }

        // check
        bool ok = true;
        for (int i = 0; i < n; i++) {
            bool same = s[i] == 'o';
            if (res[i] == 'W') {
                same = !same;
            }
            if (same) {
                if (res[(i+1)%n] != res[(i-1+n)%n]) {
                    ok = false;
                    break;
                }
            }
            else {
                if (res[(i+1)%n] == res[(i-1+n)%n]) {
                    ok = false;
                    break;
                }
            }
        }

        if (ok) {
            put(res);
            return;
        }
    }

    put(-1)
}
signed main(){ Main();return 0;}