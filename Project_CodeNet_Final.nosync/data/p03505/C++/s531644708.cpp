#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
#include <string>

using namespace std;


int main() {
    long long int k,a,b;
    cin >> k >> a >> b;
    long long int ans = 1;
    long long int now = a;
    long long int kk = a - b;
    if(now >= k) {
        cout << ans << endl;
        return 0;
    }
    if(kk <= 0) {
        cout << -1 << endl;
        return 0;
    }
    ans +=  ((k - now) / kk + ((k - now) % kk != 0 ? 1: 0)) * 2;

    cout << ans << endl;
}