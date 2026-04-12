#include <bits/stdc++.h>
#define rep(i , n) for (int i = 0; i < (int)(n); i++)
const int INF = 1<<29;
using namespace std;
using ll = long long;
int main(){
    int N;
    cin >> N;
    vector <int> A(N);
    ll total = 0;
    for(int i = 0; i < N; i++){
        cin >> A[i];
        total+=(A[i]%1000000007);
        total%=1000000007;
    }
    ll ans = 0;
    for(int i = 0; i < N; i++){
        ans += (total - A[i] % 1000000007 + 1000000007) % 1000000007 * A[i] % 1000000007;
        total = (total - (A[i] % 1000000007) + 1000000007) % 1000000007;
    }
    cout << ans % 1000000007 << endl;
}
