#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    string S;
    cin >> S;
    int X = 1<<N;
    vector<int> A(2*X);
    for(int i=0; i<X; i++){
        cin >> A[i];
        A[i+X] = A[i];
    }
    
    auto winner = [&](int x, int y){
        if(x > y) swap(x, y);
        return S[y-x-1] == '0' ? x : y;
    };
    static int dp[19][1<<19];
    for(int i=0; i<2*X; i++) dp[0][i] = A[i];
    for(int k=0; k<N; k++) for(int i=0; i+(1<<k)<2*X; i++) dp[k+1][i] = winner(dp[k][i], dp[k][i+(1<<k)]);
    for(int i=0; i<X; i++) printf("%d\n", dp[N][i]);
    return 0;
}

