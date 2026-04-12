#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<(b);++i)
#define erep(i,a,b) for(int i=a;i<=(int)(b);++i)
#define per(i,a,b) for(int i=(b);i>(a);--i)
#define eper(i,a,b) for(int i=((int)(a));i>=b;--i)
#define pb push_back
#define mp make_pair
#define INF (1<<28)-1
#define MOD 1000000007
#define all(x) (x).begin(),(x).end()
using namespace std;
typedef long long ll;
typedef pair<int,int> Pii;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a = b; return 1; } return 0; }
int dy[]={0, 0, 1, -1};
int dx[]={1, -1, 0, 0};
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int lcm(int a,int b){return a/gcd(a, b)*b;}

int h, w;
char c[110][110];
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
    cin >> h >> w;
    rep(i, 0, h) rep(j, 0, w) cin >> c[i][j];
    vector<int> a, b;
    rep(i, 0, h) {
        bool flag = false;
        rep(j, 0, w) {
            if (c[i][j] == '#') flag = true;
        }
        if (!flag) a.pb(i);
    }
    rep(i, 0, w) {
        bool flag = false;
        rep(j, 0, h) {
            if (c[j][i] == '#') flag = true;
        }
        if (!flag) b.pb(i);
    }
    rep(i, 0, h) {
        if (find(all(a), i) != a.end()) continue;
        rep(j, 0, w) {
            if (find(all(b), j) != b.end()) continue;
            cout << c[i][j];
        }
        cout << "\n";
    }
    return 0;
}
