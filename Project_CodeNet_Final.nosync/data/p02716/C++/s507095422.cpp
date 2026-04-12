#include<bits/stdc++.h>

#define stdi stdin
#define stdo stdout

#define dbl double 
#define llo long long 

#define sz size
#define pb push_back
#define mp make_pair

#define st first 
#define nd second 
#define mid ((l+r)>>1)

#define ft(i,a,b) for (int i=(int)a;i<=(int)b;i++)
#define fd(i,a,b) for (int i=(int)a;i>=(int)b;i--)

using namespace std;
const llo oo=1e13;
const int nmax=4e5+100;
int n;
llo dp[nmax][2],a[nmax];
int main()
{
    ios_base::sync_with_stdio(false);
    //freopen("SelectHalf.inp","r",stdi);
    //freopen("SelectHalf.out","w",stdo);
    cin>>n;
    ft(i,1,n) 
    {
        cin>>a[i];
        //dp[i]=-oo;
    }
    dp[2][0]=a[1],dp[2][1]=a[2];
    ft(i,3,n)
    {
        if (i%2)
        {
            dp[i][0]=max(dp[i-1][0],dp[i-1][1]);
            dp[i][1]=max(dp[i-2][1],dp[i-2][0])+a[i];
        }
        else 
        {
            dp[i][0]=a[i-1]+dp[i-2][0];
            dp[i][1]=max(dp[i-2][0],dp[i-2][1])+a[i];

        }
        //cout<<i<<": "<<dp[i][0]<<" "<<dp[i][1]<<endl;
    }
    cout<<max(dp[n][0],dp[n][1]);
}