#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
//二項係数の計算
int nCr(int A, int B) {
    ll ans = 1;
    for (int i = 0; i < B; i++) {
        ans *= A - i;
    }
    for (int i = 0; i < B; i++) {
        ans /= i + 1;
    }
    return ans;
}
int main() {
    ll N;
    cin>>N;
    vector<ll>A(N);
    ll c=0;
    rep(i,N){
        cin>>A.at(i);
        c+=A.at(i);
    }
    ll ans=0;
    for(int i=N-1; 0<i; i--){
        c-=A.at(i);
        ans+=(c%1000000007)*(A.at(i)%1000000007);
        ans%=1000000007;
        }
    cout<<ans<<endl;
}