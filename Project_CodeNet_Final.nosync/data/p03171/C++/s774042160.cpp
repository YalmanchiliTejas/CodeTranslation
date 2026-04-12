/*===================*\
|ID : harryPotter_421  |
|      LANG: C++       |
\*====================*/
#include <iostream>
#include<bits/stdc++.h>
#define lli long long int
#define ld long double
#define pb push_back
#define M 10000000000081
#define ld long double
#define f(j,m,n) for(lli j=m;j<n;j++)
#define harry ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
ld arr[3005];
ld dp[3][3005][3005];
lli rec(lli start,lli l,lli r)
        {if(dp[start][l][r]!=-M)
             return dp[start][l][r];
        if(l==r)
             {if(start==1)
                return arr[l];
              else
                return -arr[l];
              }
            ld a;
          if(start==1)
            {
            a=max(rec(2,l+1,r)+arr[l],rec(2,l,r-1)+arr[r]);
            dp[start][l][r]=a;
            return a;
            }
          if(start==2)
           {
             a=min(rec(1,l+1,r)-arr[l],rec(1,l,r-1)-arr[r]);
             dp[start][l][r]=a;
              return a;
           }


        }
int main()
   {harry
    lli n;
    cin>>n;
    for(lli i=1;i<=n;i++)
        cin>>arr[i];
    for(lli i=1;i<=n;i++)
    {for(lli j=1;j<=n;j++)
       {dp[1][i][j]=-M;
        dp[2][i][j]=-M;

       }

    }
    for(int i=1;i<=n;i++)
       {dp[1][i][i]=arr[i];
        dp[2][i][i]=-arr[i];
        }
    cout<<rec(1,1,n);




    }















