#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repr(i, a, b) for(int i = a; i < b; i++)
#define  all(x) (x).begin(),(x).end()     // 昇順ソート
#define  rall(v) (v).rbegin(), (v).rend() // 降順ソート
#define  FastIO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
typedef long long ll;
typedef long long int lli;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return true; } return false; }

int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

const int INF = 100001010;

int main(){
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    int ans = 0;
    if (a + b < 2*c){
        ans = a * x + b * y;
    }else{
        int t = min(x, y);
        ans += 2 * t * c;
        x -= t;
        y -= t;
        if (x){
            if (a < 2*c) ans += x * a;
            else ans += 2 * c * x;
        }else{
            if (b < 2*c) ans += y * b;
            else ans += 2 * c * y;
        }
    }
    cout << ans << endl;
}