#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rep1(i,n) for(int i = 1; i <= (n); ++i)
#define MOD 998244353
using namespace std;
typedef long long ll;

int main(){
    ll N;
    ll X, M;
    cin >> N >> X >> M;

    ll ans = 0;

    // vector<int> when(M, -1);
    ll when[M];
    rep(i, M) when[i] = -1;
    ll pos = X;
    ll num = 1;

    while(when[pos] == -1){
        when[pos] = num;
        ans += pos;

        // cout << pos << endl;

        if(num == N){
            cout << ans << endl;
            return 0;
        }

        pos = (pos * pos) % M;
        num++;
    }

    ll st = when[pos];
    // cout << "st: "<< st << endl;
    ll period = num - when[pos];
    // cout << "period: "<< period << endl;

    ll beforeans = 0;
    // vector<ll> periodans(period, 0);
    ll periodans[period];
    rep(i, period) periodans[i] = 0;


    rep(i, M){
        if (when[i] != -1){
            if (when[i] < st){
                beforeans += i;
            }else{
                for(ll j = when[i]; j < st + period; j++){
                    periodans[j-st] += i;
                }
            }
        }
    }
    // cout << "beforeans: "<< beforeans << endl;
    // cout << "periodans[0]: "<< periodans[0] << endl;

    ll cnt = N - (st-1);
    ans = beforeans + (cnt / period) * periodans[period - 1];

    if (cnt % period != 0){
        ans += periodans[cnt % period - 1];
    }
    
    cout << ans << endl;

    return 0;
}