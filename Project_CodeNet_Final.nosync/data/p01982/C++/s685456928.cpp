#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < n; i++)

typedef long long ll;
using namespace std;
int mod = 1000000007;

int main(void){
    int N, L, R;
    vector<int> ans;
    while(true){
        int res = 0;
        cin >> N >> L >> R;
        if(N == 0) break;
        vector<int> A(N);
        rep(i, N) cin >> A[i];
        for(int i = L; i <= R; i++){
            int idx = 0;
            while(i % A[idx] > 0){
                idx++;
                if(idx == N) break;
            }
            if(idx == N){
                if(N % 2 == 0) res++;
            }
            else if(idx % 2 == 0) res++;
        }
        ans.push_back(res);
    }
    rep(i, ans.size()) cout << ans[i] << endl;
    return 0;
}
