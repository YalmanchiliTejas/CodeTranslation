#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll N;
ll dp[3010][3010];
constexpr ll INF = 1e15;
ll A[3010];
ll rec(ll i, ll j)
{   
    if(dp[i][j] != INF) return dp[i][j];
    int turn = N - (j - i);
    ll res;
    if(turn == N)
    {
        res = 0;
    }
    else if(turn % 2 == 0) // first
    {
        res = max(A[i] + rec(i + 1, j), A[j - 1] + rec(i, j - 1));
    }
    else // second
    {
        res = min(rec(i + 1, j) - A[i], rec(i, j - 1) - A[j - 1]);
    }
    return dp[i][j] = res;
}

int main()
{
    cin >> N;
    for(int i = 0; i < N; i++) cin >> A[i];
    for(int i = 0; i < 3010; i++)
    for(int j = 0; j < 3010; j++) dp[i][j] = INF;

    cout << rec(0, N) << endl;
}