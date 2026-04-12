#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef int64_t Int;
using namespace std;

vector<Int> H(50, 1), P(50, 1);

Int solve(Int N, Int X){
    if(N == 0){
        if(X <= 0) return 0;
        else return 1;
    } else if(X <= 1+H[N-1]){
        return solve(N-1, X-1);
    } else {
        return P[N-1]+1+solve(N-1, X-H[N-1]-2);
    }
    
}

int main(){
    Int N, X; 
    cin >> N >> X;
    
    rep(i, N-1){
        H[i+1] = 2*H[i] + 3;
        P[i+1] = 2*P[i] + 1;
    }

    cout << solve(N, X) << endl;
}