#include <bits/stdc++.h>
using namespace std;

long long DP[3001][3001][2]; // (pocz, kon), czyja tura


int main(){
    ios_base::sync_with_stdio(0);
    int N;
    cin >> N;
    vector <long long> V;
    for (int i = 0; i < N; i++){
        long long x;
        cin >> x;
        V.push_back(x);
    }   

    for (int pocz = 0; pocz < N; pocz++){
        DP[pocz][pocz][0] = -V[pocz];
        DP[pocz][pocz][1] = V[pocz];
    }

    for (int dlug = 2; dlug <= N; dlug++){
        for (int pocz = 0; pocz <= N - dlug; pocz++){
            int kon = pocz + dlug - 1;
            DP[pocz][kon][0] = min(DP[pocz][kon-1][1] - V[kon], DP[pocz+1][kon][1] - V[pocz]);
            DP[pocz][kon][1] = max(DP[pocz][kon-1][0] + V[kon], DP[pocz+1][kon][0] + V[pocz]);     
        }
    }
    cout << DP[0][N-1][1];




     
}