#include <bits/stdc++.h>
using namespace std;
const long long INF = 1LL << 60;
int main() {
    int N;
    cin >> N;
    vector<long long> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    vector<long long> dpfl(200010, -INF), dpc(200010, -INF);
    dpfl[N-1] = 0LL; dpc[N-1] = A[N-1];
    if(N >= 2){
        dpfl[N-2] = max(A[N-2], A[N-1]);
        dpc[N-2] = max(A[N-2], A[N-1]);
    }
    if(N >= 3) {
        dpfl[N-3] = max({A[N-3], A[N-2], A[N-1]});
        dpc[N-3] = A[N-3] + A[N-1];
    }

    for (int i = N - 4; i >= 0; i--)
    {
        if((N-i) % 2 == 0) {
            dpfl[i] = dpc[i] = max(A[i] + dpfl[i+2], A[i+1] + dpc[i+3]);
        }
        else {
            dpfl[i] = max({A[i] + dpfl[i+2], A[i+1] + dpfl[i+3], dpc[i+2]});
            dpc[i] = A[i] + dpc[i+2];
        }
    }

    cout << dpfl[0] << endl;
    return 0;
}
