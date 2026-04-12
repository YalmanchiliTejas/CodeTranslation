#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int64_t> A(N);
    for(int i=0; i<N; i++) cin >> A[i];
    int64_t ans = 0;
    while(true){
        bool updated = false;
        for(int i=0; i<N; i++){
            int64_t d = A[i]/N;
            ans += d;
            if(d > 0) updated = true;
            A[i] %= N;
            for(int j=0; j<N; j++) if(j!=i) A[j] += d;
        }
        if(!updated) break;
    }
    cout << ans << endl;
}
