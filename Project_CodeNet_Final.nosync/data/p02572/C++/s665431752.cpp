#include<iostream>

const int MOD = 1000000007;

typedef long long ULL;

using namespace std;

int main(){
    int N;
    int i;
    ULL ans;
    ULL *A;
    ULL sum;

    cin >> N;
    A = new ULL[N];

    sum = 0;
    for(i=0;i<N;i++){
        cin >> A[i];
        sum += A[i];
    }
    ans = 0;
    for(i=0;i<N-1;i++){
        sum -= A[i];
        ans += ( A[i] * (sum % MOD) ) % MOD; 
        ans %= MOD;
    }
    
    cout << ans << endl;
}