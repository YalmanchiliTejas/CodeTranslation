#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define pb push_back
#define pii pair<int , int>
#define fast ios_base::sync_with_stdio(0)
#define mx 10004
#define mod 1000000007
ll dp[mx][102][2][2];
string str;
int d, sz;
ll fun(int pos, int rem, bool isSmall, bool isStart)
{
    if(pos==sz) return (rem==0 && isStart);
    ll& ret = dp[pos][rem][isSmall][isStart];
    if(ret==-1){
        ret = 0;
        int lim = (isSmall) ? 9 : str[pos] - '0';
        for(int i=0; i<=lim; i++){
            ret+=fun(pos+1,(rem+i)%d, isSmall | i<(str[pos]-'0'), isStart | i>0);
            ret%=mod;
        }
    }
    return ret;
}
int main()
{
    fast;
    cin>>str;
    sz = str.size();
    cin>>d;
    memset(dp, -1, sizeof dp);
    cout<<fun(0,0,0,0)<<endl;
}

