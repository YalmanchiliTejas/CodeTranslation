#include <bits/stdc++.h>
using namespace std;
int main(){
    long long int N,i,a = 0;
    cin >> N;
    long long int A[N],P[N + 1];
    P[N] = 0;
    for(i = 0;i < N;i++){
        cin >> A[i];
    }
    for(i = N - 1;i >= 0;i--){
        P[i] = (P[i + 1] + A[i]) % 1000000007;
        A[i] = A[i] % 1000000007;
    }
    for(i = 0;i < N;i++){
        a = (a + ((A[i] * (P[i + 1]))) % 1000000007) % 1000000007;
    }
    cout << a % 1000000007 << endl;
}