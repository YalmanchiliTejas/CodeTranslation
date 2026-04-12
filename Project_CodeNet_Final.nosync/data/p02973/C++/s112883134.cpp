#include <bits/stdc++.h>
using namespace std;

vector<int> LIS(vector<int>& A){
    int N = A.size();
    const int INF = 1e9;
    vector<int> dp(N+1, INF), dp2(N+1), prev(N+1);
    int last = 0;
    for(int i=0; i<N; i++){
        int pos = upper_bound(dp.begin(), dp.end(), A[i]) - dp.begin();
        dp[pos] = A[i];
        dp2[pos] = i;
        prev[i] = pos>0 ? dp2[pos-1] : -1;
        last = max(last, pos);
    }

    vector<int> ret;
    int idx = dp2[last];

    while(idx >= 0){
        ret.push_back(A[idx]);
        idx = prev[idx];
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i=0; i<N; i++){
        cin >> A[i];
        A[i] *= -1;
    }
    cout << LIS(A).size() << endl;
    return 0;
}
