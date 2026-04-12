#include <bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;

const ll MAX = 200000;
const ll INF = 1001001001;
const ll MOD = 1000000007;
const double PI=3.1415926535897932;

ll N, ans=0, tmp=0;
vector<ll> A;
string S;

signed main(){
    cin >> N;
    for(int i=0;i<N;i++) {
        ll a;
        cin >> a;
        A.push_back(a);
        tmp += a;
    }
    for(int i=0;i<N;i++) {
        tmp -= A[i];
        ll num = tmp%MOD;
        if(num<0) num += MOD; 
        ans += A[i]*num;
        ans %= MOD;
        if(ans<0) ans += MOD; 
    }
    cout << ans << endl;
    return 0;
}