#include <bits/stdc++.h>
using namespace std;


void solve(long long N, std::vector<long long> H){
    int cnt = 1;
    for(long long i = 1; i < N; i++){
        bool flag = true;
        //cout << "i: " << i << endl;
        for(long long j = 0; j <= i-1; j ++){
            //cout << "j: " << j << endl;
            //cout << "H[j]: " << H[j] << endl;
            //cout << "H[i]: " << H[i] << endl;
            if(H[j] <= H[i]) continue;
            else{
                flag = false;
                break;
            };
        }
        if(flag) cnt++;
    }
    cout << cnt << endl;
}

int main(){
    long long N;
    scanf("%lld",&N);
    std::vector<long long> H(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&H[i]);
    }
    solve(N, std::move(H));
    return 0;
}
