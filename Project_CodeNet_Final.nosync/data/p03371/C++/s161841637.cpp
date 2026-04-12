#include <algorithm>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;

#define rep(i, n) for(ll i = 0; i < n; i++)
#define REP(i, n) for(ll i = 1; i < n + 1; i++)
#define PI 3.14159265359
#define EPS 0.0000000001
#define MOD 1000000007
//cout << std::fixed << std::setprecision(15) << y << endl;


int main(){
    ll A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;

    ll addA = min(A, 2 * C);
    ll addB = min(B, 2 * C);
    ll addAB = min(A + B, 2 * C);
    ll ans = 0;
    if(X >= Y){
        ans += Y * addAB + (X - Y) * addA;
    }else{
        ans += X * addAB + (Y - X) * addB;
    }

    cout << ans << endl;

    return 0;
}