#include<bits/stdc++.h>
using namespace std;
typedef long long lint;

lint A[55];

int main(){
    int N; cin >> N;
    for(int i=0;i<N;i++) cin >> A[i];

    lint ans = 0, cnt = 1;
    while(cnt){
        cnt = 0;
        for(int i=0;i<N;i++) cnt += A[i] / N;
        for(int i=0;i<N;i++) A[i] -= A[i] / N * N - (cnt-A[i]/N);
        ans += cnt;
    }

    cout << ans << endl;
    return 0;
}