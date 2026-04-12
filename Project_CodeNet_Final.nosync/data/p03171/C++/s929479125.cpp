#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include <map>
#define pb push_back
#define ll long long
#define pii pair <int,int>
#define eb emplace_back
#define pll pair <long, long>
using namespace std;
using namespace std;
int N;
ll a[3010],X,Y;
ll dp[3010][3010];
int main()
{
    int i,j;
    cin>>N;
    for(i=1;i<=N;i++)
    {
        cin>>a[i];
    }
    for(i=N;i>=1;i--)
        for(j=i;j<=N;j++)
    {
        if(i==j)
        {
            dp[i][j]=a[i];
        }
        else
        {
            dp[i][j]=max(a[i]-dp[i+1][j],a[j]-dp[i][j-1]);
        }
    }
//    for(i=N;i>=1;i--)
//      {
//        for(j=i;j<=N;j++)
//        {
//        cout<<dp[i][j]<<" ";
//        }
//        cout<<endl;
//    }
    cout<<dp[1][N];
    //cout<<X<<" "<<Y<<" "<<X-Y<<"\n";
    return 0;
}
