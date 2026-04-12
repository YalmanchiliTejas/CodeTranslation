#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
# define mod 1000000007
# define INF (1 << 29)
# define MAX_N 1000010
/* ちゃんと考えてわかって実装 */

bool flag[3001][3001];
ll dp[3001][3001];
vector<ll> a;

// rec(l, r) は a_l ~ a_r でターンが回ってきた人の、(自分の点数)-(相手の点数)の最大値
ll rec(int l, int r){
    if(flag[l][r]) return dp[l][r];
    if(l==r){
        flag[l][r] = true;
        return dp[l][r] = a[l];
    }
    else{
        flag[l][r] = true;
        return dp[l][r] = max(a[l]-rec(l+1, r), a[r]-rec(l, r-1));
    }
}

int main(void){
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        ll tmp_a;
        cin >> tmp_a;
        a.push_back(tmp_a);
    }
    cout << rec(0, n-1) << endl;
    return 0;
}