#include <bits/stdc++.h>
using namespace std;
const int mx = 1e4+5;
const int md = 1e9+7;

string s; int d;
int dp[mx][2][105];

int fun(int idx, int f, int v){
    if(idx == s.size()) return v==0;

    int &ans = dp[idx][f][v];
    if(ans != -1) return ans; ans=0;

    int val = s[idx] - '0';
    int lim = f>0 ? 9 : val;
    for(int i=0; i<=lim; i++)
        ans += fun(idx+1, i!=val?1:f, (v+i)%d), ans %= md;
    return ans;
}

int main(){

    cin.tie( nullptr );
    ios_base::sync_with_stdio(0);

    cin >> s >> d;
    memset(dp, -1, sizeof dp);
    cout << (fun(0, 0, 0)-1+md)%md << "\n";

    return 0;
}
