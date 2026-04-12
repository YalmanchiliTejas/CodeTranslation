#include <bits/stdc++.h>
using namespace std;

//#define int long long
typedef long long ll;
//const int INF = 2e9;
//const ll INF = 9e18;


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i=0;i<N;i++) cin >> A[i];
    sort(A.rbegin(),A.rend());
    ll ans = 0;
    if (N%2==1){
        ll sum = 0;
        for (int i=0;i<(N-3)/2;i++){
            sum += 2*A[i];
        }
        for (int i=(N-3)/2;i<(N+1)/2;i++){
            sum += A[i];
        }
        for (int i=(N+1)/2;i<N;i++){
            sum -= 2*A[i];
        }
        ans = max(ans, sum);
        sum = 0;
        for (int i=0;i<(N-1)/2;i++){
            sum += 2*A[i];
        }
        for (int i=(N-1)/2;i<(N+3)/2;i++){
            sum -= A[i];
        }
        for (int i=(N+3)/2;i<N;i++){
            sum -= 2*A[i];
        }
        ans = max(ans, sum);
    } else {
        ll sum = 0;
        for (int i=0;i<(N-2)/2;i++){
            sum += 2*A[i];
        }
        for (int i=(N-2)/2;i<N/2;i++){
            sum += A[i];
        }
        for (int i=N/2;i<(N+2)/2;i++){
            sum -= A[i];
        }
        for (int i=(N+2)/2;i<N;i++){
            sum -= 2*A[i];
        }
        ans = max(ans , sum);
        sum = 0;
        for (int i=0;i<(N-2)/2;i++){
            sum += 2*A[i];
        }
        for (int i=(N-2)/2;i<N/2;i++){
            sum += A[i];
        }
        for (int i=N/2;i<(N+2)/2;i++){
            sum -= A[i];
        }
        for (int i=(N+2)/2;i<N;i++){
            sum -= 2*A[i];
        }
        ans = max(ans, sum);
    }
    cout << ans << "\n";
}