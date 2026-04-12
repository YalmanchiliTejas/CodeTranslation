#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <set>
#include <algorithm>
#include <string>
#include <math.h>
#include <limits.h>
#include <stack>
#include <complex>
#include <stdlib.h>
#include <stdio.h>
#include <functional>
#include <cfloat>
#include <math.h>


#define fs first
#define sc second

using namespace std;

typedef long long ll;
typedef pair<int, int> P;

typedef long long ll;
typedef pair<int, int> P;


int main(){
    ll N, K;
    cin >> N >> K;

    ll res = 0;
    if(K == 0){
        cout << N * N << endl;
        return 0;
    }
    for(ll b = K+1; b <= N; b++){
        ll x = N / b;
        ll y = N - b * x;
        res += (b - K) * x + max(y - K + 1, 0LL);
    }

    cout << res << endl;

    return 0;
}
