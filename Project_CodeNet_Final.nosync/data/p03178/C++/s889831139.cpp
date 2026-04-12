#include "bits/stdc++.h"
using namespace std;
#define F first
#define S second
#define show(x) cout<<#x<<" "<<x<<" ";
#define f(i,j,k) for(int i = j;i<=k;i++)
#define fr(i,j,k) for(int i = j;i>=k;i--)
#define ll long long
#define all(A)  A.begin(),A.end()  
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);  
const int MSIZE = 1e4+5;
const int MOD = 1e9+7;


string S;
int D;
ll dp[MSIZE][2][105];

ll solve(int i,int bd,int sum) {
    if(i==S.length())   return sum%D==0;
    if(dp[i][bd][sum]!=-1)  return dp[i][bd][sum];
    ll ans = 0;
    f(j,0,(bd?(S[i]-'0'):9)) {
        ans+=solve(i+1,bd and j==(S[i]-'0'),(sum+j)%D);
        ans%=MOD;
    }
    return dp[i][bd][sum] = ans;
}
int main(){

    FIO
    cin>>S>>D;
    memset(dp,-1,sizeof(dp));
    cout<<(solve(0,true,0)-1+MOD)%MOD<<endl;

    return 0;

}
    
