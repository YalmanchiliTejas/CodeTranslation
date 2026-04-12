//#pragma GCC optimize ('O3')
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef long double ld;
#define mp make_pair
#define f first
#define s second
#define pb push_back

const int N = 100 + 5;
const int M = 1e7 + 5;
const ll OO = 2e18;
const int mod = 998244353;

int n,m,r[N],c[N];
char a[N][N];

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
            if(a[i][j]=='#') {
                ++r[i], ++c[j];
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        bool ok = 0;
        for (int j = 0; j < m; ++j) {
            if(r[i] && c[j]) {
                ok = 1;
                cout << a[i][j];
            }
        }
        if(ok) cout << '\n';
    }

    return 0;

}