#include<bits/stdc++.h>
#define INFTY 10000000000
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
const int MOD=1000000007;
const int di[4] = {-1,0,1,0};
const int dj[4] = {0,-1,0,1};

int main(){
    string n;cin>>n;
    int k;cin>>k;

    int l = n.size();
    int dp0[105][4],dp1[105][4];
    dp0[1][1] = max(0,(n[0]-'0')-1);
    dp0[1][0] = 1;
    dp1[1][0] = 0;
    dp1[1][1] = 1;
    rep(i,2){dp1[1][i+2] = 0;dp0[1][i+2]=0;}
    for (int i = 2; i <= l; i++)
    {
        dp0[i][0] = 1;dp1[i][0] = 0;
        for (int j = 1; j < 4; j++)
        {
            dp0[i][j] = dp0[i-1][j-1]*9+dp0[i-1][j]+dp1[i-1][j-1]*max(0,((n[i-1]-'0')-1))+dp1[i-1][j];
            if(n[i-1]=='0'){dp1[i][j] = dp1[i-1][j];dp0[i][j] -=dp1[i-1][j];}
            else dp1[i][j] = dp1[i-1][j-1];    
        }
    }
    
    cout<<dp0[l][k]+dp1[l][k]<<endl;
    return 0;
}