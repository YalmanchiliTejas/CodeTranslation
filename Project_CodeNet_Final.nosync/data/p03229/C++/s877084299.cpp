/**
 * @author torith
 * @date 2018-10-27
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);
    int N; cin >> N;
    vector<int> A;
    for (int i = 0; i < N; ++i) {
        int t; cin >> t;
        A.push_back(t);
    }

    sort(A.begin(),A.end());

    ll ans = 0;
    if(N % 2 == 0){
        for (int i = 0; i < N/2 - 1; ++i) {
            ans += 2 * (A[A.size()-1-i] - A[i]);
        }
        ans += A[A.size()-N/2] - A[N/2-1];
    }else{

        // 奇数の方を大きい方
        for (int i = 0; i < N/2 - 1; ++i) {
            ans += 2 * A[A.size()-1-i];
        }

        ans += A[A.size()-1-N/2] + A[A.size()-N/2];
        for (int i = 0; i < N/2; ++i) {
            ans -= 2 * A[i];
        }

        ll tmp = 0;
        for (int i = 0; i < N/2 - 1; ++i) {
            tmp -= 2 * A[i];
        }
        tmp -= A[N/2] + A[N/2-1];
        for (int i = 0; i < N/2; ++i) {
            tmp += 2 * A[A.size()-1-i];
        }
        ans = max(ans,tmp);
    }

    cout << ans << "\n";

    return 0;
}

