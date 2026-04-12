#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    while(cin >> n){
        if(n == 0) break;
        vector<int> A(n);
        REP(i, n) cin >> A[i];
        sort(A.begin(), A.end());
        if(n - 2 <= 0){
            cout << 0 << endl;
            continue;
        }
        int total = 0;
        REP(i, n - 1){
            if(i) total += A[i];
        }
        cout << total / (n - 2) << endl;
    }

    return 0;
}
