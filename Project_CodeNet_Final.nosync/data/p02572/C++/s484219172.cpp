#include <bits/stdc++.h>

using namespace std;

int main(void){
    int N;
    long mod = 1000000007;
    cin >> N;
    int A[N];
    for(int i = 0; i < N; i++)
    {
    cin >> A[i];
    }
    long long S[N-1];
    long long ans = 0;
    S[0] = A[0];
    for(int i = 1; i < N-1; i++)
    {
        S[i] = S[i-1] + A[i];
    }
    for(int i = 0; i < N-1; i++)
    {
        A[i+1] = A[i+1] % mod;
        S[i] = S[i] % mod;
        ans = ans + S[i]*A[i+1];
        ans = ans % mod;
    }
    cout << ans << endl;
    
}