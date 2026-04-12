#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <queue>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define REP(i, n) for(int i=0; i<n; i++)

ll X;
ll eat(int n){
    if(n == 0) {
        X--;
        return 1;
    }

    ll ret = 0;
    X--;
    if(X == 0) return ret;
    else if(X >= (1LL << n+1) - 3){
        X -= (1LL << n+1) - 3;
        ret += (1LL << n) - 1;
    }
    else ret += eat(n-1);

    if(X == 0) return ret;
    X--, ret++;

    if(X == 0) return ret;
    else if(X >= (1LL << n+1) - 3){
        X -= (1LL << n+1) - 3;
        ret += (1LL << n) - 1;
    }
    else ret += eat(n-1);

    if(X == 0) return ret;
    X--;

    return ret;
}

int main(){
    int N;
    cin >> N >> X;

    ll ans;
    ans = eat(N);
    cout << ans << endl;
    return 0;
}
