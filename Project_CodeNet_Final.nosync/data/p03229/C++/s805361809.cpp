#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

int main(){
    int N;  cin >> N;
    vector<ll> A(N);
    for(int i=0; i<N; i++)
        cin >> A[i];
    sort(A.begin(), A.end(), greater<ll>());
    
    int n = N/2;
    if(N%2==0){
        ll ans = 0;
        for(int i=0; i<n; i++) ans += 2*A[i];
        for(int i=n; i<N; i++) ans -= 2*A[i];
        ans -= A[n-1];
        ans += A[n];
        cout << ans << endl;
    }else{
        int n = N/2;
        ll sum1 = 0;
        for(int i=0; i<n-1; i++) sum1 += 2*A[i];
        for(int i=n+1; i<N; i++) sum1 -= 2*A[i];
        sum1 += A[n] + A[n-1];

        ll sum2 = 0;
        for(int i=0; i<n; i++) sum2 += 2*A[i];
        for(int i=n+2; i<N; i++) sum2 -= 2*A[i];
        sum2 -= A[n] + A[n+1];
        cout << max(sum1, sum2) << endl;
    }
}