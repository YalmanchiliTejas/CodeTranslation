#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>

#define debug_value(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << #x << "=" << x << endl;
#define debug(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << x << endl;

using namespace std;
typedef long long ll;

ll N, X, M;

bool used[100005];
int idx[100005];

vector<ll> sum;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    cin >> N >> X >> M;
    ll cur = X;
    ll s = 0;
    int i = 0;
    if(X == 0){
        cout << 0 << endl;
        return 0;
    }
    if(X == 1){
        if(M != 1) cout << N << endl;
        if(M == 1) cout << 0 << endl;
        return 0;
    }
    // if(N == 1){
    //     cout << X << endl;
    //     return 0;
    // }
    while(!used[cur]){
        // cout << cur << endl;
        used[cur] = true;
        idx[cur] = i;
        s += cur;
        cur = (cur*cur)%M;
        i++;
        sum.push_back(s);
    }
    if(N < i){
        cout << sum[N-1] << endl;
        return 0;
    }
    // cout << cur << ' ' << idx[cur] << endl;
    ll loop = i-idx[cur];
    ll ans = 0;
    if(idx[cur] > 0) ans += sum[idx[cur]-1];
    ll before_loop = ans;
    // cout << before_loop << endl;
    ll m = N-(idx[cur]);
    ll sum_loop = (sum[i-1]-before_loop);
    ans += sum_loop*(m/loop);
    if(idx[cur] == 0 && loop == 1){
        cout << ans << endl;
        return 0;
    }
    // cout << sum_loop << ' ' << m << ' ' << loop << endl;
    ans += (sum[idx[cur]+(m%loop)-1]-before_loop);
    cout << ans << endl;
}