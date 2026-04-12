#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <cmath>
#include <set>
#include <algorithm>
#include <iomanip>

typedef long long ll;
const ll MOD = 1e9 + 7;
const long long INF = 1LL<<60;
const double PI=3.14159265358979323846;
const int NMAX=100005;
using namespace std;


int main(){
    int n;
    cin >> n;
    vector<ll> a(n);

    ll sm = 0;

    for(int i = 0; i < n; i++){
        cin >> a[i];
        sm += a[i];
        sm %= MOD;
    }
    ll ans = 0;
    for(int i = 0; i < n-1; i++){
        sm -= a[i];
        if(sm < 0) sm += MOD;
        ans += sm * a[i];
        ans %= MOD;
    }

    cout << ans << endl;

    return 0;
}