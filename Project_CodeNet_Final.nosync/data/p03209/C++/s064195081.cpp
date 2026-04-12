#include <bits/stdc++.h>
using namespace std;

#define watch(x) cerr << (#x) << ": " << (x) << endl
#define int long long

const int N = 51;
int layers[N];
int patties[N];

int solve(int n, int x) {
    if(n == 0) return x;
    if(x == 0) return 0;
    
    x--;
    int ret = 0;
    if(x >= layers[n-1]) {
        ret += patties[n-1];
        x -= layers[n-1];

        if(x > 0) {
            ret += 1;
            x--;
        }
    }
    ret += solve(n-1, min(x, layers[n-1]));
    return ret;
}

int32_t main() {

    int n, x; cin >> n >> x;

    layers[0] = 1;
    patties[0] = 1;
    for(int i = 1; i <= 50; ++i) {
        layers[i] = layers[i-1]*2 + 3;
        patties[i] = patties[i-1]*2 + 1;
    }
    
    int ans = solve(n, x);

    cout << ans << endl;
    
    return 0;
}
