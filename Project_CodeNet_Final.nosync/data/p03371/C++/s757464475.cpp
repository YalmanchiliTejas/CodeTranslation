#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <map>
#include <functional>
#include <queue>
#include <stack>
#include <string.h>
#include <list>
using namespace std;
typedef long long ll;
#define all(a)  (a).begin(), (a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define rep(i,n) for(int i = 0; i < n; i++)
#define repR(i,n) for(int i = n-1; i >= 0; i--)
#define FOR(i,m,n) for(int i = m; i < n; i++)
#define PB push_back
#define MP make_pair
#define EPS (1e-7)
#define INF (1e12)
#define PI (acos(-1))

int main(){
    int a, b, c, x, y;
    ll ans = INF;
    cin >> a >> b >> c >> x >> y;
    int C = 2*c;
    rep(i,max(x,y)+1){
        ll res = 0;
        res += C * i;
        res += a * max(0,x-i);
        res += b * max(0,y-i);
        ans = min(ans,res);
    }
    cout << ans << endl;
    return 0;
}