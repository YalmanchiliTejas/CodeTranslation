#include<bits/stdc++.h>
using namespace std;

#define lint long long
#define P pair<int, int>
#define LLP pair<long long, long long>
#define REP(i, x, n) for(int i = (x), i##_len = (int)(n) ; i < i##_len ; ++i)
#define rep(i, n) for(int i = 0, i##_len = (int)(n) ; i < i##_len ; ++i)
#define repr(i, n) for(int i = (int)(n) - 1 ; i >= 0 ; --i)
#define SORT(x) sort((x).begin(), (x).end())
#define SORT_INV(x) sort((x).rbegin(), (x).rend())

const int IINF = 1e9 + 100;
const long long LLINF = 2e18 + 129;
const long long MOD = 1e9 + 7;
const int dx4[] = {1, 0, -1, 0}, dy4[] = {0, 1, 0, -1};
const int dx8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dy8[] = {0, -1, -1, -1, 0, 1, 1, 1};
const double EPS = 1e-8;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<int> t(n);
    rep(i, n){
        cin >> t[i];
    }
    SORT_INV(t);

    vector<int> v;
    for(int i = 1 ; i * i <= t[0] ; ++i){
        if(t[0] % i == 0){
            v.emplace_back(i);
            v.emplace_back(t[0] / i);
        }
    }
    SORT(v);

    int ans = 0;
    REP(i, 1, n){
        auto it = lower_bound(v.begin(), v.end(), t[i]);
        ans += *it - t[i];
    }

    cout << ans << endl;

    return 0;
}
