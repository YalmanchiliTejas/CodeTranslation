#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void) {
    ll N,K;
    cin >> N >> K;
    if(K==0) {
        cout << N*N << endl;
        return 0;
    }
    ll res = 0;
    for(int i=K; i<N; i++) {
        res += N-i;
        int elm = 0;
        while(true) {
            elm++;
            int diff = ((N-i)/elm) - i;
            if(diff <= 0) break;
            res += diff;
        }
    }
    cout << res << endl;
    return 0;
}
