#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
using namespace std;
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long ll;
typedef pair<ll, ll> P;
const int MOD = 1000000007;
const int MOD2 = 998244353;

string s[10];
bool seen[10][10];
int dx[2] = {1,0};
int dy[2] = {0,1};

int main(){
    int h, w;
    cin >> h >> w;
    int cnt = 0;
    rep(i, h) rep(j, w){
        char c;
        cin >> c;
        if (c == '#') cnt++;
    }

    if (cnt == h + w - 1) cout << "Possible" << endl;
    else cout << "Impossible" << endl;

    return 0;
}
