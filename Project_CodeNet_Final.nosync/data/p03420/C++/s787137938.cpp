#include "bits/stdc++.h"
using namespace std;
const int maxn = 300300;
int main(){
    long long n, k, ans = 0;
    cin >> n >> k;
    for(long long b = 1; b <= n; b++){
        long long cy = n / b;
        long long have = (b - 1 - k + 1);
        if(have <= 0) continue;
        ans += have * cy;
        long long last = n % b;
        if(last){
            long long now = last - k + 1;
            if(k == 0) now--;
            if(now > 0) ans += now;
        }
    }
    cout << ans << endl;
    return 0;
}
