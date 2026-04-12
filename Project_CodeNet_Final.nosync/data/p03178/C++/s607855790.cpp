#include<bits/stdc++.h>
using namespace std;
#define fr first
#define sc second
typedef long long ll ;
typedef double ld;
typedef pair<int,int> p2;
typedef pair<ll,p2> p3;
typedef vector<int> vi;
const ll  Mod = 7 + 1e9;
const ll  INF32 = 5 + 2e9;
const ll  INF64 = 5 + 1e18;
const ll  MAX = 5+ 1e4;

ll N,D,dp[MAX][105][2];
string K;

ll Try(int i,int sum,bool eq)
{
    if(i==N)
        return !sum;
    ll &r = dp[i][sum][eq];
    if( r != -1 )
        return r;
    r = 0;
    int cur = K[i] - '0';
    for(int j =(eq ? cur : 9); j>=0; j--)
        r = (r + Try(i+1,(sum + j)%D, eq && j == cur ))%Mod;
    return r;
}

int main()
{
    cin >> K >> D;
    N = K.size();
    memset(dp,-1,sizeof(dp));
    cout << (Try(0,0,1)-1 + Mod)%Mod << endl;
    return 0;
}
