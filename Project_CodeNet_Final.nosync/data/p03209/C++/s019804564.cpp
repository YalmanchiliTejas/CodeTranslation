#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <functional>
#include <map>
#include <queue>

#define REP(i,n) for(int (i)=0; (i)<(n); (i)++)

using namespace std;
using ll = long long;
using P = pair<int, int>;
using TP = tuple<ll, ll, ll>;
ll MOD = 1e9+7;
ll INF = 1LL<<40;

ll rec(ll N, ll X){
    if(N==0){
        return 1;
    }
    
    ll len = ((ll)1 << N+1) - 3;
    ll num = ((ll)1 << N) - 1;
    if(X==1) return 0;
    else if(X <= len + 1) return rec(N-1, X-1);
    else if(X == len + 2) return num + 1;
    else if(X <= (len + 1) * 2) return num + 1 + rec(N-1, X-len-2);
    else return num * 2 + 1;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    ll N, X;
    cin >> N >> X;
    cout << rec(N,X) << endl;
    return 0;
}
