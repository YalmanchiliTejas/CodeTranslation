#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)
#define VL vector<ll>
#define VS vector<string>
#define VB vector<bool>
#define VP vector<pair<ll,ll>>
#define VVL vector<vector<ll>>
#define VVP vector<vector<pair<ll,ll>>>
#define PL pair<ll,ll>
#define ALL(v) (v).begin(), (v).end()
ll d1[4] = {1, -1, 0, 0};
ll d2[4] = {0, 0, 1, -1};

int main(){
    ll N;
    cin >> N;

    VL a(N);
    rep(i, 0, N) cin >> a[i];

    ll L = -1, R = 1e18;
    while(R - L > 1){
        VL tmp(a);
        ll M = L + (R - L)/2;
        ll c = 0;
        auto itr = max_element(ALL(tmp));
        while(*itr >= N){
            ll d = (ll)(*itr/N);
            c += d;
            *itr -= d * (N + 1);
            rep(t, 0, tmp.size()) tmp[t] += d;
            itr = max_element(ALL(tmp));
        }
        if(c <= M) R = M;
        else L = M; 
    }
    cout << R << endl;
    return 0;
}