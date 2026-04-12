#include <bits/stdc++.h>
using namespace std;
long long A[200][2][4] = {};

int main() {
    string N; cin >> N;
    int K; cin >> K;

    A[0][0][0] = 1;
    for(int i=0; i<N.size(); ++i) {
        for(int j=0; j<2; ++j) {
            for(int k=0; k<4; ++k) {
                int n = (int)(N[i] - '0');
                A[i + 1][j | (n > 0)][k] += A[i][j][k];
                if(k == 3) continue;
                for(int c=1; c<=(j?9:n); ++c) {
                    A[i + 1][j | (n > c)][k + 1] += A[i][j][k];
                }
            }
        }
    }
    cout << A[N.size()][0][K] + A[N.size()][1][K] << endl;
}