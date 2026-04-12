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

int main()
{
    int n;
    cin >> n;
    vs s(n);
    rep(i, n) cin >> s[i];

    vvi cnt(n, vi(26));
    rep(i, n) {
        rep(j, s[i].size()) {
            int c = s[i][j] - 'a';
            cnt[i][c]++;
        }
    }

    string ans = "";
    rep(i, 26) {
        int t = 114514;
        rep(j, n) {
            t = min(t, cnt[j][i]);
        }
        if(t == 0) continue;
        rep(k, t) {
            ans += char(i + 'a');
        }
    }

    cout << ans << endl;


    return 0;
}
