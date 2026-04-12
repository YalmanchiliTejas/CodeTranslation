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

using namespace std;

typedef long long ll;
typedef pair<int, int> P;

ll a[60];

int main(){
    int N;  cin >> N;
    for(int i = 0; i < N; i++){
        cin >> a[i];
    }

    ll l = 0, r = LONG_LONG_MAX;
    while(r - l > 1){
        ll m = (l + r) / 2;
        ll x = 0;
        for(int i = 0; i < N; i++){
            x += (a[i] + m + 1) / (N + 1);
        }
        if(x < m){
            r = m;
        }
        else{
            l = m;
        }
    }

    ll res = 0;
    for(ll x = max(0LL, l-N*N); x <= l; x++){
        ll y = 0;
        for(int i = 0; i < N; i++){
            y += (a[i] + x + 1) / (N + 1);
        }
        if(y <= x){
            res = x;
            break;
        }
    }

    cout << res << endl;


    return 0;
}

