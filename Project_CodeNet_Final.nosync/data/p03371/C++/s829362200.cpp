#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <bitset>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <utility>
#include <set>
#include <map>
#include <tuple> 
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <list>
using namespace  std;
typedef pair<long long , long long> P;
typedef long long ll;
typedef long long lint;
#define REP(i, n) for(long long (i)=0; (i)<(n); ++i)
#define FOR(i, a, b) for(long long (i)=(a); (i)<(b); ++i)
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
const long long MOD = static_cast<long long>(1e9) + 7LL;
const long long INF = 1234567891234567890LL;
signed main(){
    ll a, b, c, x, y;
    cin>>a>>b>>c>>x>>y;
    ll res = 0;
    if(a+b > 2*c){
        ll z = min(x, y);
        res += z*c*2;
        y -= z;
        x -= z;
    }
    if(x>0 and a>2*c){
        res += 2*c*x;
        x = 0;
        if(x<y) y-=x;
        else y=0;
    }
    if(y>0 and b>2*c){
        res += 2*c*y;
        y = 0;
        if(y<x) x-=y;
        else x=0;
    }
    if(x) res += a*x;
    if(y) res += b*y;
    cout << res << endl;
    return 0;
}