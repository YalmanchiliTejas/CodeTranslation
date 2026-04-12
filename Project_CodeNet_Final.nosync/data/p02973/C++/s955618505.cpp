#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
const int N = 1e5+9;

int n;
ll load[N];

int main() {
    fill_n(load, N, 1);
    cin >> n;
    for(int i = 0; i < n; i++) {
        int a; cin >> a;
        int index = upper_bound(load, load+N, -a) - load;
        load[index] = -a;
    }
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        if(load[i] != 1)  ans++;
    }
    cout << ans << endl;
}