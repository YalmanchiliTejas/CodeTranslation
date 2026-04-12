#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower, islower
#include <math.h>

#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
using ll = long long; using ld = long double;
using P = pair<int, int>;
long long n, m, x, y, z;
const long long template_arry_size = 1000625;
long long a[template_arry_size];
long long b[template_arry_size];
long long c[template_arry_size];
string s, t;
long long ans = 0;
long long mod = 1'000'000'007;

void solve() {
    cin >> n ;
    rep(i,n) {
        cin >> a[i];
    }
    int x = 0;
    rep(i,n) {
        ans =(ans + (ll)a[i]*x)%mod;
        x =(x+a[i])%mod;
    }
    cout << ans << endl;
}

int main(){

    solve();
    
}