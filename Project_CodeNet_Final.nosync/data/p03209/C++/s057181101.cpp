#include<bits/stdc++.h>
using namespace std;

int_fast64_t ans(int_fast64_t N, int_fast64_t X){
    if(X == 0)return 0;
    if(N == 0)return 1;
    auto P = 1LL << N;
    if(X >= 2 * P - 1){
        return P + ans(N - 1, X + 1 - P * 2);
    }
    return ans(N - 1, X - 1);
}

int main(){
    int_fast64_t N, X;
    cin >> N >> X;
    cout << ans(N, X) << endl;
    return 0;
}
