#include <bits/stdc++.h>
using namespace std;
#define rep(i, N)  for (int i = 0; i < (N); i++)

int main(){

    const long long int md = 1000000007;
    int N;
    cin >> N;
    vector<long long int> A(N);
    vector<long long int> A_cumu(N);
    rep (i, N){
        cin >> A[i];
        if (i == 0) A_cumu[0] = A[0];
        else A_cumu[i] = (A_cumu[i-1] + A[i])%md;
    }

    long long int ans = 0;
    for (int i = 1; i < N; i++){
        ans += (A[i]*A_cumu[i-1])%md;
        ans %= md;
    }

    cout << ans << endl;

    return 0;
}