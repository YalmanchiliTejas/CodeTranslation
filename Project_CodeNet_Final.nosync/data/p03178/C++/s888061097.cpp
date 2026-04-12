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
const int Mod = 1e9+7;
string k;
int d;
ll dp[10011][111][2];


ll Solve(int i=0,int m=0,int l=0)
{
    if(i == k.sz)
        R (m==0);

    ll &Res = dp[i][m][l];
    if(Res != -1)
        R Res;
    Res = 0;

    if(l)
    {
        for(int j = 0 ; j <= 9 ; j++)
        {
            Res += Solve(i+1,(m+j)%d,1);
            Res = ((Res%Mod)+Mod)%Mod;
        }
    }
    else
    {
        for(int j = 0 ; j <= k[i]-'0' ; j++)
        {
            Res += Solve(i+1,(m+j)%d,j<(k[i]-'0'));
            Res = ((Res%Mod)+Mod)%Mod;
        }
    }
    R Res;
}


int main()
{

    SPEED;
    cin >> k >> d;
    Mdp;
    ll Res = Solve()-1;
    Res = ((Res%Mod)+Mod)%Mod;
    cout << Res << endl;

    R 0;
}
