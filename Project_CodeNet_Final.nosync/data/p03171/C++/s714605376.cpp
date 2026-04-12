#include<bits/stdc++.h>

#define ll long long
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define pii pair<int,int>
#define pll pair<ll,ll>
#define SPEED ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define sz size()
#define all(x) x.begin(),x.end()
#define OO 1e18
#define iOO INT_MAX
#define Mdp memset(dp,-1,sizeof dp)
#define R return
#define Test int TT;cin>>TT;for(int T=1;T<=TT;T++)
using namespace std;
int n,a[3001];
ll dp[3001][3001][3];


ll Solve(int i=0,int j=n-1,int Turn = 1)
{
    if(i > j)
        R 0;
    ll &Res = dp[i][j][Turn];
    if(Res != -1)
        R Res;

    Res = 0;
    if(Turn)
    {
        Res = Solve(i+1,j,1-Turn)+a[i];
        Res = max(Res,Solve(i,j-1,1-Turn)+a[j]);
    }
    else
    {
        Res = Solve(i+1,j,1-Turn)-a[i];
        Res = min(Res,Solve(i,j-1,1-Turn)-a[j]);
    }

    R Res;
}

int main()
{

    SPEED;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }

    Mdp;

    cout << Solve()  << endl;

    R 0;
}
