#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define yorn(f) cout<<((f)?"Yes":"No")<<endl;
#define YORN(f) cout<<((f)?"YES":"NO")<<endl;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repi(i, n) for (ll i = 1; i < (ll)(n); i++)
#define all(x) (x).begin(), (x).end()
#define put(x) cout << x << endl;
#define println(x) cout << x << endl;
using namespace std;
void Main()
{
    int n;
    cin >> n;
    vector<string> S(n);
    rep(i, n) cin >> S[i];

    vector<int> Cnt('z' - 'a' + 1, 1e8);

    rep(i, n) {
        vector<int> c('z' - 'a' + 1);
        rep(j, S[i].size()) c[S[i][j] - 'a']++;

        rep(j, Cnt.size()) {
            Cnt[j] = min(Cnt[j], c[j]);
        }
    }

    rep(j, Cnt.size()) {
        rep(k, Cnt[j]) {
            cout << (char)('a' + j);
        }
    }

    cout << endl;
    
}
signed main(){ Main();return 0;}