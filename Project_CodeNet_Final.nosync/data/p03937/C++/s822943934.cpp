#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<(b);++i)
#define erep(i,a,b) for(int i=a;i<=(int)(b);++i)
#define per(i,a,b) for(int i=(a);i>(b);--i)
#define eper(i,a,b) for(int i=(a);i>=b;--i)
#define pb push_back
#define mp make_pair
#define INF (1<<30)-1
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
char a[8][8];
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
    cin >> h >> w;
    rep(i, 0, h) rep(j, 0, w) cin >> a[i][j];
    int x = 0, y = 0;
    a[0][0] = '.';
    rep(i, 0, h+w) {
        a[x][y] = '.';
        if (a[x+1][y] == '#') {
            a[x+1][y] = '.';
            x++;
        }
        else if (a[x][y+1] == '#') {
            a[x][y+1] = '#';
            y++;
        }
    }
    rep(i, 0, h) rep(j, 0, w) 
        if (a[i][j] != '.') {
            cout << "Impossible" << endl;
            return 0;
        }
    cout << "Possible" << endl;
    return 0;
}
