#include <bits/stdc++.h>
#define ll long long
#define MODV 1000000007
#define INFLL (1LL<<62) // 9223372036854775807
#define EPS 1e-9
#define rep(i, n) for(ll i=0, i##_len=(ll)(n); i<i##_len; i++)
#define repf(i, n) for(ll i=1, i##_len=(ll)(n+1); i<i##_len; i++)
#define all(v) v.begin(), v.end()
#define endl "\n"
#define vi vector<ll>
#define vvi vector<vector<ll>>
#define Yes() cout << "Yes" << endl
#define YES() cout << "YES" << endl
#define No() cout << "No" << endl
#define NO() cout << "NO" << endl
#define Init() std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout<<fixed<<setprecision(15);
template<class T>bool chmax(T &a, const T &b){ if(a<b){ a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b){ if(b<a){ a=b; return 1; } return 0; }
using namespace std;

int main(){
    Init();
    ll n, x, m;
    cin >> n >> x >> m;

    // 累積和と出現位置
    vi sum(1, 0), pos(m+1, -1);
    sum[0] = x, pos[x] = 0;

    for(ll i=1; i<n; i++){
        x = (x*x)%m;
        sum.push_back(sum[i-1] + x);
        // これまでに出現していない場合
        if(pos[x] == -1) pos[x] = i;
        // これまでに出現している場合はループ長を検出
        else{
            // 1ループ当たりの長さとその区間和
            ll loopSize = i-pos[x];
            ll loopSum = sum[i] - sum[pos[x]];

            // 最後までに何回ループが含まれるかと端数分の処理
            ll loopTotal = ((n-pos[x])/loopSize)*loopSum;
            ll fractionSize = (n-pos[x])%loopSize;
            ll fraction = (fractionSize == 0 ? 0 : (pos[x] == 0 ? sum[fractionSize-1] : sum[pos[x]+fractionSize-1] - sum[pos[x]-1]));
            cout << (pos[x] == 0 ? 0 : sum[pos[x]-1]) + loopTotal + fraction << endl;
            return 0;
        }
    }
    // ループがなかった場合
    cout << sum[sum.size()-1] << endl;
}