#include <iostream>
#include <fstream>
#define nmax 3001

using namespace std;
ifstream fin("p.in");
ofstream fout("p.out");

long long v[nmax],dp[nmax][nmax];
int n;

int main()
{
    cin>>n;
    long long sum=0;
    for(int i=1; i<=n; i++)
        {
            cin>>v[i];
            sum+=v[i];
        }
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            if(i==j) dp[i][j]=v[i];
            else if(j==i+1) dp[i][j]=max(v[i],v[j]);

    int i=1;
    int val=3;
    while(i<=n-2)
        {
            int j=val;
            int it=1;
            while(j<=n)
                {
                    dp[it][j]=max(v[it]+min(dp[it+2][j],dp[it+1][j-1]),v[j]+min(dp[it+1][j-1],dp[it][j-2]));
                    j++;
                    it++;
                }
            val++;
            i++;
        }

    /*for(int i=1; i<=n;  i++)
        {
            for(int j=1; j<=n; j++)
                fout<<dp[i][j]<<" ";
            fout<<endl;
        }*/

    cout<<dp[1][n]-(sum-dp[1][n]);
    return 0;
}
