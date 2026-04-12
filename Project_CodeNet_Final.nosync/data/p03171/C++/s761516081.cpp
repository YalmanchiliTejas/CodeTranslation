#include<bits/stdc++.h>
#define sf1(n) scanf("%d",&n)
#define sf2(n,q) scanf("%d %d",&n,&q)
#define f first
#define ss second
#define pb push_back
#define lli long long
#define mem(ar,false) memset(ar,false,sizeof(ar))
#define mpr make_pair
#define endl "\n"
#define mod 1000000007
#define inf 9000000000000000000LL

using namespace std;
lli dp[3002][3002];
lli ar[3002];

int n;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for(int i=0; i<n; i++)
    {
        cin >> ar[i];
    }

    for(int i=n-1;i>=0;i--)
    {
        for(int j=i;j<n;j++)
        {
            if(i==j)
                dp[i][j] = ar[i];
            else
                dp[i][j] = max(ar[i]-dp[i+1][j],ar[j]-dp[i][j-1]);
        }
    }


    cout << dp[0][n-1] << endl;

    return 0;

}
