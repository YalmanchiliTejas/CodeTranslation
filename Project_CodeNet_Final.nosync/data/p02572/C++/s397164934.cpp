#include <bits/stdc++.h>
#include <numeric>
using namespace std;
#define ll long long
#define mod107 1000000007
#define rep(i, n) for (int i = 0; i < n; ++i)
#define Graph vector<vector<int>>
#define grepq priority_queue<double, std::vector<double>, std::greater<double>>
#define all(v) v.begin(), v.end()
#define PI acos(-1)
#define inf 1000000321
#pragma GCC optimize("Ofast")
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i = 0;i < N;i++){
        cin >> A[i];
    }
    ll ans = 0;
    vector<ll> csum(N);
    csum[0] = 0;
    ll sum = 0;
    for(int i = 0;i < N;i++){
        //csum[i+1] = csum[i] + A[i];
        sum += A[i];
    }
    for(int i = 0;i < N;i++){
        ans %= mod107;
        sum -= A[i];
        //cout << sum << endl;
        ans += (sum%mod107)*A[i];
        ans %= mod107;
    }
    ans %= mod107;
	cout << ans << endl;
}   