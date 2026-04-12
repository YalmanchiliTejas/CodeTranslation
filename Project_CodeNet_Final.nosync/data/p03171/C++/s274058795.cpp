#include <bits/stdc++.h>
#define ll long long int
#define mp make_pair
#define pb push_back
#define pa pair<int,int>
using namespace std;
const int MAX=3001;
ll dp[3005][3005];
// dp[i][j] - the highest difference i using j elements
//A B C D H F E I G K L M N P S O Q R J U Z Y X T V W
int main()
{
    int n;
    scanf("%d",&n);
    ll tab[n];
    for (int i=1;i<=n;i++)
    {
        scanf("%lld",&tab[i]);
    }

    for (int l=n;l>=1;l--)
    {
        for (int r=l;r<=n;r++)
        {
            dp[l][r]=max(tab[l]-dp[l+1][r],tab[r]-dp[l][r-1]);
        }
    }

    printf("%lld",dp[1][n]);
    return 0;
}

