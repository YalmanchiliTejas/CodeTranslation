#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using ld = long double;
using P = pair<int, int>;
using vi = vector<int>;
using vl = vector<ll>;
ld EPS = 1e-12;
int INF = numeric_limits<int>::max() / 2;
ll LINF = numeric_limits<ll>::max() / 2;
int MOD = 1e9 + 7;
#define rep(i,n) for(int i = 0; i < n; i++)
#define all(obj) (obj).begin(), (obj).end()
#define debug(x) cerr << #x << ": " << x << '\n'

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int a,b,c,x,y;
    cin >> a >> b >> c >> x >> y;
    int res = 0;
    if(2 * c < a + b){
        res = min(2 * c * min(x,y) + a * (x - min(x,y)) + b * (y - min(x,y)), 2 * c * max(x,y));
    }else{
        res = a * x + b * y;
    }
    cout << res << endl;
}