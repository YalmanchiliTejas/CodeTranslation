#include <bits/stdc++.h>
using namespace std;
#define idfc ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr)
#define ll long long
#define pb push_back
#define mp make_pair
#define nt _int128
#define ld long double
long double PI =3.14159265358979323846;


const ll modo=1e9+7;
const ll inf=2e14;
const ll ms=(2e5) +5;

int ar[ms];
int n,k;

ll dp[ms][4][2]={0};

ll callme()
{
    int i,j,m,p;
    int xx;
    dp[0][0][0]=1;
    for(i=1;i<=n;i++)
    {
        for(j=0;j<=k;j++)
        {
           for(m=0;m<=9;m++)
           {
               xx=j;
               if(m)xx++;
               if(xx>k)continue;
               dp[i][xx][1]+=dp[i-1][j][1];
               if(ar[i]>m)
               {
                   dp[i][xx][1]+=dp[i-1][j][0];
               }
               else if(ar[i]==m)
               {
                   dp[i][xx][0]+=dp[i-1][j][0];
               }
           }
        }
    }
    return dp[n][k][0]+dp[n][k][1];
}

int main()
{
    idfc;
    string s;
    cin>>s;
    n=s.length();
    int i;
    for(i=1;i<=n;i++)
    {
        ar[i]=s[i-1]-48;
    }
    //int k;
    cin>>k;
    cout<<callme();
    return 0;
}