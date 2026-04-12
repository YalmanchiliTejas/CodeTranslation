#include<bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define all(x) (x).begin(),(x).end()
#define rep(i, n) for(ll i = 0; i < n; i++)
const ll INF = 1LL << 60;
const int mod = 1000000007;

int main(){
    int N; cin >> N;
    vector<int> A(N);
    rep(i, N) cin >> A[i];
    ll ans = 0;
    ll sum = 0;
    for(int i = 0; i < N - 1; i++){
        sum += A[i];
        sum %= mod;
        ans += sum * A[i + 1];
        ans %= mod;
    }
    cout << ans << endl;
}