#include <bits/stdc++.h>
using namespace std;

int main(){

    int N;
    cin >> N;
    vector<int> A(N+1);
    for(int i=1;i<=N;i++)
        cin >> A[i];

    vector<long long> B(N+1);
    B[N] = A[N];
    for(int i=N-1;i>=2;i--)
        B[i] = (B[i+1] + A[i]) % 1000000007;

    long long res = 0;
    for(int i=1;i<=N-1;i++){
        res += A[i] * B[i+1];
        res %= 1000000007;
    }

    cout << res;
    return 0;
}