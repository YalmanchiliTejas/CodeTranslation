#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
    ll N; cin >> N;
    vector<ll> A(N); for(ll i = 0; i < N; i++) cin >> A[i];
    sort(A.begin(), A.end());
    ll ans;
    if(N % 2 == 0){
        ll temp=0;
        for(int i = 0; i < N/2-1; i++) temp-=2*A[i];
        temp-=A[N/2-1];
        temp+=A[N/2];
        for(int i = N/2+1; i < N; i++)  temp += 2 * A[i];
        ans = temp;
    }
    else {
        ll temp = 0;
        for(int i = 0; i < N/2-1; i++) temp -= 2*A[i];
        for(int i = N/2+2; i < N; i++) temp += 2*A[i];
        ans = max( temp - 2*A[N/2-1] + A[N/2] + A[N/2+1], temp - A[N/2-1] - A[N/2] + 2*A[N/2+1] );


    }
    cout << ans << endl;
}