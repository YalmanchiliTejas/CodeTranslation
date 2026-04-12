#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; i++)
using namespace std;
typedef long long ll;

int main() {
    int N;
    cin >> N;
    vector<int> H(N+1);
    rep(i, N) cin >> H[i+1];
    H[0] = 0;

    int res=0;
    for(int i=1; i<=N; i++) {
        int f=1;
        for(int j=0; j<i; j++) {
            if(H[j] > H[i]) {
                f=0;
                break;
            }
        }
        if(f) res++;
    }

    cout << res << endl;
    return 0;
}