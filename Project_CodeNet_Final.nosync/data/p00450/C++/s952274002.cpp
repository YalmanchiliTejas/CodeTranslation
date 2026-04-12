#include <bits/stdc++.h>
using namespace std;
#define int long long

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,int> plli;
typedef pair<int,pii> pipii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<pii> vpii;

#define rep(i,n) for (int i=0;i<(n);i++)
#define rep2(i,a,b) for (int i=(a);i<(b);i++)
#define rrep(i,n) for (int i=(n);i>0;i--)
#define rrep2(i,a,b) for (int i=(a);i>b;i--)
#define pb push_back
#define fi first
#define se second
#define all(a) (a).begin(),(a).end()

const ll mod = 1e9 + 7;
const ll INF = 1<<30;
const int dx4[4] = {1, 0, -1, 0};
const int dy4[4] = {0, 1, 0, -1};
const int dx8[8] = {1, 1, 1, 0, 0, -1, -1, -1};
const int dy8[8] = {0, 1, -1, 1, -1, 0, 1, -1};
const double pi = 3.141592653589793;

int n;

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    while (true) {
        cin >> n;
        if (n == 0) break;
        int group[n] = {};
        int color[n];
        fill(color, color + n, -1);
        int group_idx = -1;
        int pre = -1;
        rep(i, n) {
            int c;
            cin >> c;
            if (pre == c) group[group_idx]++;
            else {
                pre = c;
                if (i % 2 == 0) {
                    group_idx++;
                    group[group_idx]++;
                    color[group_idx] = c;
                }
                else {
                    if (group_idx == 0) {
                        group[0]++;
                        color[0] = c;
                    }
                    else {
                        group[group_idx - 1] += group[group_idx] + 1;
                        group[group_idx] = 0;
                        group_idx--;
                    }
                }
            }
        }
        int ans = 0;
        rep(i, n) if (color[i] == 0) ans += group[i];
        cout << ans << endl;
    }
}