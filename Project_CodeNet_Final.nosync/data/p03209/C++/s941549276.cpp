#include <iostream>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <tuple>
#include <cstring>
#include <functional>
using namespace std;
typedef long long ll;
typedef pair<long long, long long> P;
#define rep(i, n) for(long long i=0; i<n; i++)
#define reps(i, s, e) for(long long i=s; i<e; i++)
#define repr(i, n) for(long long i=n-1; i>=0; i--)
#define reprs(i, s, e) for(long long i=e-1; i>=s; i--)

ll pattylayer(ll n){
    return pow(2, n+1) - 1;
}

ll totallayer(ll n){
    return pow(2, n) + 3*(pow(2, n) - 1);
}

ll rec(ll n, ll x){
    // cout << n << " " << x << endl;
    // cout << " " << totallayer(n) << " " << pattylayer(n) << endl;

    if(x == 0){
        return 0;
    }
    if(n == 0){
        return 1;
    }

    if(2*x - 1 == totallayer(n)){
        // cout << "cond1 " << endl;
        return pattylayer(n-1) + 1;
    }
    else if(2*x - 1 > totallayer(n)){
        // cout << "cond2 " << endl;
        return 1 + pattylayer(n-1) + rec(n-1, x - totallayer(n-1) - 2);
    }
    else{
        // cout << "cond3 " << endl;
        return rec(n-1, x-1);
    }
}

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    ll n, x; cin >> n >> x;

    cout << rec(n, x);

    return 0;
}