#include <bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;

const ll MAXN = 200000;
const ll INF = 1001001001;
const ll MOD = 1000000007;

ll N, ans=0, tmp=0, state=0;
vector<ll> A;
vector<vector<ll>> B;

signed main(){
    cin >> N;
    for(int i=0;i<N;i++) {
        ll a;
        cin >> a;
        A.push_back(a);
        if(a>=N) state = 1;
    }
    while(state) {
        state = 0;
        tmp = 0;
        vector<ll> tmps;
        for(int i=0;i<N;i++) {
            ll tmp1 = A[i]-A[i]%N;
            tmp1 /= N;
            tmp += tmp1;
            tmps.push_back(tmp1);
            A[i] %= N;
        }
        ans += tmp;
        for(int i=0;i<N;i++) {
            A[i] += tmp-tmps[i];
            if(A[i]>=N) state = 1;
        }
    }
    cout << ans << endl;
    return 0;
}