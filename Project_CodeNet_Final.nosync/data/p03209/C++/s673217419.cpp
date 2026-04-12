#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <utility>
#include <algorithm>
#include <bitset>
#include <numeric>
#include <cmath>
#include <tuple>
#include <queue>
#include <set>

using namespace std;

typedef long long ll;
const ll INF = 1LL<<60;

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }


ll a[51] = {0};
ll p[51] = {0};

ll get_ans(int N, ll X){
    if(N == 0 && X == 1) return 1;
    if(X == 1) return 0;
    if(1 < X && X <= (1 + a[N-1])) return get_ans(N-1, X-1);
    if(X == (2 + a[N-1])) return p[N-1] + 1;
    if(X > (2 + a[N-1]) && X <= (2 + 2 * a[N-1])){
        return p[N-1] + 1 + get_ans(N-1, X-2-a[N-1]);
    }
    else{
        return 2 * p[N-1] + 1;
    }
}

int main(){
    cin.tie(0);
   	ios::sync_with_stdio(false);
    
    int N;
    ll X;

    cin >> N >> X;

    a[0] = 1;
    p[0] = 1;
    for(int i = 1; i < 51; i++){
        a[i] = 2 * a[i-1] + 3;
        p[i] = 2 * p[i-1] + 1;
    }

    cout << get_ans(N, X) << endl;

    return 0;
}
