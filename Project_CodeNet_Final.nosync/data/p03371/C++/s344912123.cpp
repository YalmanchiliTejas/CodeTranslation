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
#define INF (1e9)
#define PI (acos(-1))

int main(){
    ll a, b, c, x, y, res = 0;
    cin >> a >> b >> c >> x >> y;
    ll C = 2*c;
    if(a+b < C) res = a*x + b*y;
    else{
        res += C * min(x,y);
        if(x>=y) res += min(C,a) * (x-y);
        else res += min(C,b) * (y-x);
    }
    cout << res << endl;
    return 0;
}
