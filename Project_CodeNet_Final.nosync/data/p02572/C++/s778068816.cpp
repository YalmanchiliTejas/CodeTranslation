#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
#define all(x) (x).begin(),(x).end()
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const int INF = 1000000000;
const int mod = 1000000007;


ll solve2(ll N, vector<ll>A){

    ll ret = 0;
    for(int i=0; i<N-1; i++){
        for (int j=i+1; j<N; j++){
            ret += A[i]*A[j];
            ret %= mod;
        }
    }
    return ret%mod;
}


ll solve1(ll N, vector<ll>A){
    ll N_f = 1;
    ll sum_a = 0;
    vector<ll>cumsum(N+1);
    cumsum[0] = 0;

    for (ll i=0; i<N; i++){
        cumsum[i+1] = cumsum[i]+A[i];
        cumsum[i+1] %= mod;

        sum_a += A[i];
        sum_a %= mod;
    }

    ll ans = 0;

    for (ll i=0; i<N-1; i++){
        ans += (sum_a - cumsum[i+1])* A[i];
        ans %= mod;
        if (ans < 0)ans = mod +ans;
    }
    return ans;

}


int main() {
    ll N;
    cin >> N;
    vector<ll>A(N);
    for (ll i=0; i<N; i++)cin >> A[i];
    
    ll effective = solve1(N,A);
    cout << effective << endl;
    return 0;
    
    ll greedy = solve2(N,A);


    if (effective != greedy)cout << "WRONG !! Effective: "   << effective << ", Greedy: " << greedy << endl;
    else cout << "Good ! effective: " << effective << ", greedy: " << greedy << endl;
}