#include <bits/stdc++.h>
#define ll long long

using namespace std;
ll n,S,dp[3030][3030],a[3030];
const ll Mod = 998244353;

void Add_Self(ll &x , ll y){
    x = (x + y)%Mod;
}

ll Rec(int i , int Have){

    if(i == n)   return (Have == S ? 1 : 0);
    if(Have == S)   return n - (i - 1);

    if(dp[i][Have] != -1)  return dp[i][Have];

    ll Res = 0;
    Add_Self(Res , Rec(i + 1 , min((ll)3001 , Have + a[i])));
    Add_Self(Res , Rec(i + 1 , Have));

    return dp[i][Have] = Res;
}

int main()
{

    memset(dp , -1 , sizeof(dp));
    cin >> n >> S;
    for(int i = 0;i<n;i++)  cin >> a[i];
    ll Ans = 0;
    for(int i = 0;i<n;i++)  Add_Self(Ans , Rec(i , 0));
    cout << Ans;
    return 0;
}
