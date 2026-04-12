#include <iostream>
#include <vector>
using ll = long long;
using namespace std;

int main() {
    ll n, a, b, c, x;
    while(cin >> n >> a >> b >> c >> x, n) {
        vector<ll> v(n);
        for(int i=0; i<n; ++i) {
            cin >> v[i];
        }
        int i = 0;
        int ret = 0;
        while(i < n && ret <= 10000) {
            for(int cnt=0; cnt<10000; ++cnt) {
                if(x == v[i]) {
                    ret += cnt;
                    if(i != n-1) {
                        ++ret;
                        x = (a*x + b) % c;
                    }
                    ++i;
                    break;
                } else if(cnt == 9999) {
                    ret += 10001;
                }
                x = (a*x + b) % c;
            }
        }
        if(ret > 10000) {
            cout << -1 << endl;
        } else {
            cout << ret << endl;
        }
    }
}
