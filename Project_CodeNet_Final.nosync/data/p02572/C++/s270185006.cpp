#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using pint = pair<int, int>;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
const int MOD = 1000000007;
const long long INF = 1LL << 60;

 
int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    int mod = 1000000007;
    long long sum = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
        sum += A[i];
        sum %= mod;
    }
 
    long ans = 0;
 
    //i について全探索する
    for (int i = 0; i < N; i++)
    {
        //A[i+1] ... A[N] の値を更新する
        sum -= A[i];
        if (sum < 0) sum += mod;
 
        ans += A[i] * sum;
        ans %= mod;
    }
 
    cout << ans << endl;
}