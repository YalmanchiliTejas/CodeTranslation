#include <iostream>
#include <algorithm>
#include <vector>
using namespace  std;
const long long INF = 1<<30;

int LIS(vector<int> &A){
    int N = A.size();
    vector<int> dp(N+2, INF);
    for(int i=0; i<N; i++){
        *upper_bound(dp.begin(), dp.end(), A[i]) = A[i];
    }
    int res = 0;
    for(int i=0; i<N; i++) if(dp[i]!=INF) res++;
    return res;
}
signed main(){
    int N;
    cin>>N;
    vector<int> A(N);
    for(int i=0; i<N; i++) cin>>A[i];
    reverse(A.begin(), A.end());
    cout << LIS(A) << endl;
    return 0;
}