#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

#define vi vector<int>
#define vl vector<long long>
#define vvi vector< vector<int> >
#define vvl vector< vector<ll> >
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define REPD(i, n) for (int i = (int)(n-1); i >= 0; i--)
#define FOR(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define FORD(i, a, b) for (int i = (int)(a); i >= (int)(b); i--)
#define INF 1e18
#define MOD 1e9+7

template<class T> bool chmax(T &a, const T & b) {
    if (a<b) {
        a = b;
        return true;
    }
    return false;
}

template<class T> bool chmin(T &a, const T & b) {
    if (a>b) {
        a = b;
        return true;
    }
    return false;
}

int main() {
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    int ans = a*x+b*y; //AとBだけ
    chmin(ans, 2*c*max(x, y)); //Cだけ
    if (x > y) {
        chmin(ans, 2*c*y+a*(x-y));
    } else {
        chmin(ans, 2*c*x+b*(y-x));
    }
    cout << ans << endl;
    return 0;
}