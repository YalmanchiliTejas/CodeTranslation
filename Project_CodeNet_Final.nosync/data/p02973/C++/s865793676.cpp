#include <bits/stdc++.h>

using namespace std;

int main(){
    long long int N,ans=0;
    cin >> N;
    vector<long long int> A(N),dp(N,-1e9);
    for(int i=0;i<N;i++){
        cin >> A[i];
    }

    dp[0] = A[0];

    for(int i=1;i<N;i++){
        int lb = -1, ub = N+1;
        while(1<ub-lb){
            int mid = (ub+lb)/2;
            if(A[i]<=dp[mid]){
                lb = mid;
            }else{
                ub = mid;
            }
        }

        dp[ub] = A[i];
    }

    for(int i=0;i<N;i++){
        if(dp[i] == -1e9){
            cout << i << endl;
            return 0;
        }
    }

    cout << N << endl;
}