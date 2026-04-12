#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1000000007;

int main(){
    int N;
    cin >> N;
    double A[N];
    for(int i = 0; i < N; i++) cin >> A[i];
    sort(A, A+N);
    ll ans = 0;

    double median;
    if(N%2 == 0){
        ans += (A[N/2] - A[N/2 - 1]);
        median = (A[N/2] + A[N/2 - 1])/2;
        for(int i = 0; i < N; i++){
            if(i == N/2 || i == N/2 - 1)
                continue;
            ans += abs(A[i] - median)*2;
        }
        cout << ans << "\n";
        return 0;
    }
    else{
        median = A[N/2];
        for(int i = 0; i < N; i++){
            if(i == N/2 - 1 || i == N/2 +1)
                continue;
            ans += abs(A[i] - median)*2;
        }
        ans += max(abs(A[N/2 - 1] - median)*2 + abs(A[N/2 + 1] - median),
                    abs(A[N/2 - 1] - median) + abs(A[N/2 + 1] - median)*2 );
        cout << ans << "\n";
        return 0;
    }
}