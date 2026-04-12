/*Whose woods these are I think I know.
His house is in the village though;
He will not see me stopping here
To watch his woods fill up with snow.

My little horse must think it queer
To stop without a farmhouse near
Between the woods and frozen lake
The darkest evening of the year.

He gives his harness bells a shake
To ask if there is some mistake.
The only other sound’s the sweep
Of easy wind and downy flake.

The woods are lovely, dark and deep,
But I have promises to keep,
And miles to go before I sleep,
And miles to go before I sleep.*/

#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define pb push_back
#define fi first
#define se second
#define MOD 1000000007
const int maxn= 100010;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n=0;
    cin>>n;
    lli a[n+1];
    for(int i=1;i<=n;++i)
        cin>>a[i];
    lli pre[n+1];
    pre[1]=a[1];
    for(int i=3;i<=n;i+=2)
        pre[i]=pre[i-2]+a[i];
    lli dp[n+1]={0};
    for(int i=2;i<=n;++i)
    {
        if(i%2==0)
            dp[i]=max(dp[i-2]+a[i],pre[i-1]);
        else
            dp[i]=max(dp[i-1],dp[i-2]+a[i]);
    }
    cout<<dp[n]<<endl;
}
