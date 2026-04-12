#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int64_t> A(N);
    for(int i=0; i<N; i++) cin >> A[i];

    int64_t ans = 0;
    for(int d=1; d<N; d++){
        int p1 = 0, p2 = N-1;
        int64_t res = 0;
        while(true){
            p1 += d;
            if(p1 == p2) break;
            p2 -= d;
            if(p1 == p2) break;
            if(p1+d > N-1 || p2-d < 0) break;
            res += A[p1] + A[p2];
            ans = max(ans, res);
        }
    }
    cout << ans << endl;
    return 0;
}
