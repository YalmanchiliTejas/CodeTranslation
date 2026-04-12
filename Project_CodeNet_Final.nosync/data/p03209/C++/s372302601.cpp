#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define mk make_pair
typedef pair<int, int> pii;

int N, X;
int len[55];
int dp[55];

int dfs(int L, int l, int r)
{
    int R = l - 1 + len[L] / 2;
    if(L == 1){
        if(r - 1 <= X){
            //printf("L:%lld l:%lld r:%lld res:%lld\n", L, l, r, 3ll);
            return 3ll;
        }
        else{
            //printf("L:%lld l:%lld r:%lld res:%lld\n", L, l, r, ((X - l >= 0) ? (X - l) : 0ll));
            return ((X - l >= 0) ? (X - l) : 0ll);
        }
    }
    int res = 0ll;
    if(r <= X){
        if(~dp[L]){
            //printf("L:%lld l:%lld r:%lld res:%lld\n", L, l, r, dp[L]);
            return dp[L];
        }
        res = 1ll;
        res += dfs(L - 1, l + 1ll, R);
        res += dfs(L - 1, R + 2ll, r - 1ll);
        //printf("L:%lld l:%lld r:%lld res:%lld\n", L, l, r, res);
        return dp[L] = res;
    }
    if(l + 1 <= X){
        res += dfs(L - 1, l + 1ll, R);
    }
    if(R + 2ll <= X){
        res += dfs(L - 1, R + 2ll, r - 1ll);
    }
    if(R + 1ll <= X){
        res += 1ll;
    }
    //printf("L:%lld l:%lld r:%lld res:%lld\n", L, l, r, res);
    return res;
}

signed main()
{
    cin >> N >> X;
    len[0] = 1ll;
    for(int i = 1; i <= N; i++){
        len[i] = len[i - 1] * 2ll + 3ll;
    }
    /*for(int i = 0; i <= N; i++){
        printf("len[%lld] = %lld\n", i, len[i]);
    }*/
    memset(dp, -1, sizeof(dp));
    cout << dfs(N, 1ll, len[N]) << endl;

    return 0;
}
/*


*/
