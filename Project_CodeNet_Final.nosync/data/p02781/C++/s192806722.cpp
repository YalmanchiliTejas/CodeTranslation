#include<bits/stdc++.h>
#define ll long long
#define mod (ll)1000000007
using namespace std;
ll dp[102][5][2];
int n;
vector<int> a;

ll rec(int pos, int remk, int f){
    if(pos == n){
        if(remk == 0)
            return 1;
        return 0;
    }

    if(dp[pos][remk][f]!=-1)    return dp[pos][remk][f];

    ll ans = 0;

    int LMT;
    if(f == 0)
        LMT = a[pos];
    else
        LMT = 9;

    for(int d = 0; d <= LMT; d++){
        int nf = f;
        if(f == 0 && d < LMT) nf = 1;
        if(d && remk>0){
            ans = ans + rec(pos+1, remk-1, nf);
        }
        if(d == 0){
            ans = ans + rec(pos+1, remk, nf);
        }
    }

    dp[pos][remk][f] = ans;

    return ans;
}
void solve(string s, int k){
    n = s.size();

    for(int i = 0; i < n; i++){
        a.push_back(s[i]-'0');
    }
    ll ans = 0;
    for(int i = 0; i <= 9; i++){
        if(i <= a[0]){
            if(i)
                ans = ans + rec(1, k-1, (i!=a[0]));
            else
                ans = ans + rec(1, k, (i!=a[0]));
        }
    }

    cout<<ans<<"\n";
}
int main()
{
    string s;
    int k;
    memset(dp,-1,sizeof(dp));
    cin>>s>>k;
    solve(s, k);

    return 0;
}
