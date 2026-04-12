#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < (int)n; i++)

int main() {
    int N;
    cin >> N;
    vector<long> a(N);
    long P = (long)1e9+7;
    long right = 0;
    REP(i, N){
        cin >> a[i];
        right = (right + a[i]) % P;
    }
    long result = 0;
    long left = 0;
    REP(i, N){
        left += a[i];
        left %= P;
        result += (right - left) * a[i];
        result %= P;
    }
    if(result < 0) result += P;
    cout << result << "\n";

    return 0;
}