//1.read question_2.read I/O_3.read test cases_4.read constraints(to decide TC of solution)_5.decide method_6.dry run_
//7.code_8.test_9.submit
#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define mod 1000000007
#define F first
#define S second
#define _READ freopen("input.txt","r", stdin);
#define pb push_back
#define MP make_pair
#define _FAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
int main()
{
   
    _FAST
    lli n,t,i,j,k,ans=0,flag=0,a,b,m;
    cin>>n;vector<lli> ar(n);
    for(auto &i:ar)
        cin>>i;
    vector<vector<lli>> dp(n,vector<lli>(n,0));
    for(i=n-1;i>=0;i--)
        for(j=i;j<n;j++)
        if(i==j)
            dp[i][j]=ar[i];
        else
        dp[i][j]=max(ar[i]-dp[i+1][j],
                     ar[j]-dp[i][j-1]);
    cout<<dp[0][n-1];
    return 0;
}
