#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

int N;
ll A[200000];

ll inv = 500000004;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    ll sum = 0;
    ll sum_p = 0;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> A[i];
        sum += A[i];
        sum %= MOD;
        sum_p += (A[i]*A[i])%MOD;
        sum_p %= MOD;
    }
    ll ans = (sum*sum)%MOD;
    ans = (ans-sum_p)*inv;
    ans %= MOD;
    ans += MOD;
    ans %= MOD;
    cout << ans << endl;
}