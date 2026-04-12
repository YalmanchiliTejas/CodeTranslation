#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N; cin >> N;
    vector<ll> A(N);
    for (int i=0;i<N;++i) cin >> A[i];
    sort(A.begin(),A.end());
    ll ans=0,cnt=0;
    for (int i=0;i<N/2;++i) ans-=A[i]*2;
    for (int i=N/2;i<N;++i) ans+=A[i]*2;
    ans-=A[N/2];
    if (N&1){
        ans-=A[N/2+1];
        for (int i=0;i<=N/2;++i) cnt-=A[i]*2;
        for (int i=N/2+1;i<N;++i) cnt+=A[i]*2;
        cnt+=A[N/2]+A[N/2-1];
        ans=max(ans,cnt);
    } else ans+=A[N/2-1];
    cout << ans << '\n';
}