#include <bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;

const ll MAXN = 200000;

ll N, K, ans=0, tmp=0;
vector<ll> A(MAXN, 0);

signed main(){
    cin >> N >> K;
    for(int i=K+1;i<=N;i++) {
        ans += N/i*(i-K)+max(0LL, N%i-max(0LL, (K-1)));
        //cout << i << " " << (i-K)*N/i+max(0LL, N%i-max(0LL, (K-1))) << endl;
    }
    cout << ans << endl;
    return 0;
}