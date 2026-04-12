#include <bits/stdc++.h>
#define inf (1ll << 62)
using namespace std;
const int maxn = 3005;
typedef long long ll;
int A[maxn];
ll memo[maxn][maxn][2];
ll solve(int i,int j,bool flag){
    if(i == j){
        if (flag)
            return -A[i];
        else
            return A[i];
    }
    ll &ans = memo[i][j][flag];
    if(ans != -inf)return ans;
    ll x = solve(i+1,j,!flag)+((flag)? -A[i] : A[i]);
    ll y = solve(i,j-1,!flag)+((flag)? -A[j] : A[j]);
    if (!flag)
        return (ans =max(x,y));
    else
        return (ans =min(x,y));

}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    for (int i = 1; i <= N;i++){
        cin >> A[i];
    }
    for (int i = 1; i <= N;i++){
        for (int j = 1; j <= N;j++){
            memo[i][j][0] = memo[i][j][1] = -inf;
        }
    }
    cout << solve(1,N,0);
    return 0;
}
