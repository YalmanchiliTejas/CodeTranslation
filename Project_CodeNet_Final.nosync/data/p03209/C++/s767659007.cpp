#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <limits.h>
#include <float.h>
#include <numeric>
#include <queue>

using namespace std;

typedef long long ll;
typedef pair<int, int> P;

#define fs first
#define sc second

ll si[51];
ll pa[51];

ll calc(int n, ll x){
    if(n == 0){
        return 1LL;
    }
    else{
        ll total = si[n];
        if(x == 0){
            return 0LL;
        }
        else if(x < total / 2){
            return calc(n-1, x-1);
        }
        else if(x == total / 2){
            return pa[n-1] + 1LL;
        }
        else if(x < total - 1){
            return pa[n-1] + 1LL + calc(n-1, x-si[n-1]-2);
        }
        else{
            return pa[n-1] * 2 + 1;
        }
    }
}


int main(){
    ll N, X;
    cin >> N >> X;
    si[0] = 1;
    pa[0] = 1;
    for(int i = 1; i <= N; i++){
        si[i] = si[i-1] * 2 + 3;
        pa[i] = pa[i-1] * 2 + 1;
    }

    cout << calc(N, X-1) << endl;


    return 0;
}