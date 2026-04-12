#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[3009][3009][3], a[3009], n;

ll solve(ll st, ll en, ll ch)
{
    if(st == en)
        return a[st];
    long long& res = dp[st][en][ch];
    if(res != 1e17)
        return res;
    if(ch == 1){
        res = max(a[st] - solve(st + 1, en, 2), a[en] - solve(st, en - 1, 2));
    }
    else{
        res = max(a[st] - solve(st + 1, en, 1) , a[en] - solve(st, en - 1, 1));
    }
    //cout<<"st = "<<st<<" en = "<<en<<" ch = "<<ch<<" dp = "<<res<<"\n";
    return (res);
}
main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    cin>>n;
    for(int i = 1; i <= n; i++)
    {
        cin>>a[i];
    }
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            for(int k = 0; k <= 3; k++)
                dp[i][j][k] = 1e17;
    cout<<solve(1, n, 1)<<"\n";
    //cout<<dp[1][n][1];
}
