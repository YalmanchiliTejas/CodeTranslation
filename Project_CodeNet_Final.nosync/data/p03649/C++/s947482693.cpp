#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int N;
ll A[52], B[52];

int main() {
    scanf("%d", &N);

    ll sum = 0;
    for(int i = 0; i < N; i++) {
        scanf("%lld", &A[i]);
        sum += A[i];
    }

    ll ans = 9e18;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            ll tsum = j;
            B[i] = j;
            for(int k = 0; k < N; k++) {
                if(i == k) continue;

                B[k] = (A[k] - A[i] + N + 1) % (N + 1);
                B[k] += j;
                B[k] %= (N + 1);
                if(B[k] == N) {
                    tsum = 9e18;
                    break;
                }
                tsum += B[k];
            }
            if(sum < tsum) continue;
            ll cnt = sum - tsum;

            bool ok = true;
            for(int k = 0; k < N; k++) {
                if((A[k] + cnt - B[k]) % (N + 1)) {
                    ok = false;
                    break;
                }
            }
            if(ok) ans = min(ans, cnt);
        }
    }

    printf("%lld", ans);
}
