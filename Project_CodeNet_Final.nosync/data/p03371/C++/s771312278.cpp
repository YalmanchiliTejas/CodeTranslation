#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<string> vs;
typedef pair<int, int> P;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()

void YN(bool flg){if(flg) cout << "YES" << endl; else cout << "NO" << endl;}
void Yn(bool flg){if(flg) cout << "Yes" << endl; else cout << "No" << endl;}
void yn(bool flg){if(flg) cout << "yes" << endl; else cout << "no" << endl;}

const ll INF = 1LL<<60;

int main() {
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;

    ll ans = INF;
    for(int i = 0; i <= max(x, y); i++) {
        int j, k;
        if(x - i < 0) j = 0; else j = x - i;
        if(y - i < 0) k = 0; else k = y - i;
        ll tmp = a * j + b * k + c * i * 2;
        ans = min(ans, tmp);
    }

    cout << ans << endl;

    return 0;
}
