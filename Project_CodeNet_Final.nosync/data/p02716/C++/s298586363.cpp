#include<bits/stdc++.h>

#define ll long long
#define pi pair<int,int>
#define ppi pair<pi,pi>
#define mp make_pair
#define fr first
#define sc second

using namespace std;

ll Mod = 1e9 + 7;
ll Power(int x , int y){
    if(!y)return 1;
    ll Tmp = Power(x , y / 2);
    Tmp = Tmp * Tmp % Mod;
    if(y & 1)Tmp = Tmp * x % Mod;
    return Tmp;
}
const int nax = 2e5 + 100;
ll Dp[nax][2][2];
ll n , arr[nax];
ll solve(int i,int c1 , int c2){
    if(i >= n)return 0;
    ll &ret = Dp[i][c1][c2];
    if(ret + 1)return ret;
    ret = -1e18;
    ret = max(ret , arr[i] + solve(i + 2 , c1 , c2));
    ret = max(ret , arr[i] + solve(i + 2 + c1, 0 , c2));
    ret = max(ret , arr[i] + solve(i + 2 + c2, c1 , 0));
    ret = max(ret , arr[i] + solve(i + 2 + c1 + c2, 0 , 0));
    return ret;
}
int main(){

    ios::sync_with_stdio(0);
    cin.tie(0) , cout.tie(0);
    memset(Dp,-1,sizeof Dp);
    cin >> n ;
    for(int i = 0;i < n;i++)
        cin >> arr[i];
    ll Ans = solve(0,1,n%2);
    Ans = max(Ans,solve(1,0,n%2));
    if(n%2)
        Ans = max(Ans,solve(1,1,0));
    if(n%2)
        Ans = max(Ans,solve(2,0,0));
    cout << Ans << '\n';

    return 0;
}
