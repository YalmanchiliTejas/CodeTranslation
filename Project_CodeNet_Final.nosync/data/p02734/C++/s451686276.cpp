#include <iostream>
#define MOD 998244353

using namespace std;
long long table[3001][3001];
int main() {
    int N, S;
    int A[3000];
    cin >> N >> S;
    for (int i=0; i<N; i++) {
        cin >> A[i];
    }
    
    for (int i=0; i<3001; i++) {
        table[i][0] = i+1;
    }
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=3000; j++) {
            table[i][j] = table[i-1][j];
            if (j-A[i-1] >= 0) table[i][j] += table[i-1][j-A[i-1]];
            table[i][j] %= MOD;
        }
    }

    long long answer = 0;
    for (int i=1; i<=N; i++) {
        answer = (answer + table[i][S]) % MOD;
    }
    cout << answer <<endl;
    return 0;
}

