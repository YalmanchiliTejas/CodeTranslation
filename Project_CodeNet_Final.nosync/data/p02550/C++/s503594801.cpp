#include <bits/stdc++.h>
using namespace std;

int nth_bit(int64_t num, int n){
    return (num >> n) & 1;
}

int main(){
    int64_t N, X, M;
    cin >> N >> X >> M;
    static int64_t sum[40][100000], nxt[40][100000];
    for(int64_t i=0; i<M; i++){
        sum[0][i] = i;
        nxt[0][i] = i*i%M;
    }
    for(int k=0; k<39; k++) for(int i=0; i<M; i++){
        sum[k+1][i] = sum[k][i] + sum[k][nxt[k][i]];
        nxt[k+1][i] = nxt[k][nxt[k][i]];
    }

    int64_t ans = 0;
    for(int k=39; k>=0; k--) if(nth_bit(N, k)){
        ans += sum[k][X];
        X = nxt[k][X];
    }
    cout << ans << endl;
    return 0;
}
