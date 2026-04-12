#include <bits/stdc++.h>
using namespace std;
int n;
long long num[55];
bool cmp(long long x, long long y) {
    return x > y;
}
long long work() {
    long long ans = 0;
    bool done = false;
    long long sigma = 0;
    long long cnt[55];
    sort(num + 1 ,num + n + 1, cmp);
    for(int i = 1;i <= n;i++) cnt[i] = 0;
    while(true) {
        for(int i = 1;i <= n;i++) {
            num[i] += sigma - cnt[i];
            sigma -= cnt[i];
            cnt[i] = num[i] / n;
            ans += cnt[i];
            sigma += cnt[i];
            num[i] %= n;
            if(!sigma) break;
        }
        if(!sigma) break;
    }
    return ans;
}
int main () {
    while(cin >> n) {
        for(int i = 1;i <= n;i++) cin >> num[i];
        long long cnt = 0;
        for(int i = 1;i <= n;i++) cnt += num[i];
        cnt -= (n-1)*n;
        if(true) {
            cout << work() << endl;
        } else {
            cout << cnt + (n-1)*n/2 << endl;
        }
    }
    return 0;
}