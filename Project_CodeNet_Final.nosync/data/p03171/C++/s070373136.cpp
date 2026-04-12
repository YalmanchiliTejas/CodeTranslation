#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define REP(i, n) for(int i=0; i<n; i++)

ll A[4000];
ll DP[4000][4000][2];
int main(){
    int N;
    cin >> N;
    REP(i,N){
        ll a;
        cin >> a;
        A[i] = a;
    }

    for(int i = N-1; i >= 0; i--){
        for(int j = 0; j < N; j++){
            if(i > j) DP[i][j][0] = DP[i][j][1] = 0;
            else{
                DP[i][j][0] = max(DP[i+1][j][1]+A[i], DP[i][j-1][1]+A[j]);
                DP[i][j][1] = min(DP[i+1][j][0]-A[i], DP[i][j-1][0]-A[j]);
            }
        }
    }

    //for(int i = 0; i < N; i++){
    //    for(int j = 0; j < N; j++){
    //        printf("%3lld ", DP[i][j][0]);
    //    }
    //    printf("\n");
    //}
    //for(int i = 0; i < N; i++){
    //    for(int j = 0; j < N; j++){
    //        printf("%3lld ", DP[i][j][1]);
    //    }
    //    printf("\n");
    //}
    //

    cout << DP[0][N-1][0] << endl;

    return 0;
}
