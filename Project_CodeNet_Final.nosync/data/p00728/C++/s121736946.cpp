#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < n; i++)

typedef long long ll;
using namespace std;
int mod = 1000000007;

int main(void){
    while(true){
        int N; cin >> N;
        int sum = 0;
        if(N == 0) break;
        vector<int> A(N);
        rep(i, N){
            cin >> A[i];
            sum += A[i];
        }
        sort(A.begin(), A.end());
        cout << (sum - A[0] - A[A.size()-1]) / (A.size()-2) << endl;
    }
    return 0;
}
