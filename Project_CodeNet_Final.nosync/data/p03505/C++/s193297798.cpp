#include <bits/stdc++.h>
using namespace std;

int main(){
    long long k, a, b;
    cin >> k >> a >> b;
    if(k <= a) cout << 1 << endl;
    else if(a <= b) cout << -1 << endl;
    else{
        k -= a;
        long long ans = (k + a - b - 1) / (a - b) * 2 + 1;
        cout << ans << endl;
    }

    return 0;
}