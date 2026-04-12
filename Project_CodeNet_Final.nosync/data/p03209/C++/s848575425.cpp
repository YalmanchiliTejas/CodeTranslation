#include <iostream>
using namespace std;
#define REP(i,n) for (int i=0;i<(n);++i)
using ll = long long;

ll size[55];
ll patty[55];

int main() {
    ll n, x; cin >> n >> x;
    size[0] = 1, patty[0] = 1;
    REP(i,n+1) size[i+1] = size[i] * 2 + 3;
    REP(i,n+1) patty[i+1] = patty[i] * 2 + 1;

    ll ans = 0;
    while(n>=0) {
        if(x==0) {break;} // left end
        else if(n==0) { // P
            ++ans;
            break;
        }

        if(x < 1 + size[n-1] + 1) { 
            --n;
            --x;
        } else if(x > 1 + size[n-1] + 1) {
            ans += patty[n-1] + 1;
            x -= 1 + size[n-1] + 1;
            --n;
        } else {
            ans += patty[n-1] + 1;
            break;
        }
    }
    cout << ans << '\n';
    return 0;
}