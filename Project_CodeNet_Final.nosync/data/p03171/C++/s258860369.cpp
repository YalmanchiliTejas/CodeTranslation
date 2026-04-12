#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll N;
ll dp[3010][3010];
bool ch[3010][3010];
ll A[3010];
ll rec(ll i, ll j)
{   
    if(ch[i][j]) return dp[i][j];
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
    ch[i][j] = true;
    return dp[i][j] = res;
}

int main()
{
    cin >> N;
    for(int i = 0; i < N; i++) cin >> A[i];
    memset(dp, 0, sizeof(dp));
    //for(int i = 0; i < 3010; i++)
    //for(int j = 0; j < 3010; j++) ch[i][j] = false;
    memset(ch, 0, sizeof(ch));

    cout << rec(0, N) << endl;
}