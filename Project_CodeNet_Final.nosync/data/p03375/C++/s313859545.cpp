#include <bits/stdc++.h>

using namespace std;

const int MAX_N=3005;
long long comb[MAX_N][MAX_N];

int n;
long long modd;

void add(long long &a, long long b)
{
    a=(a+b)%modd;
}

void mult(long long &a, long long b)
{
    a=(a*b)%modd;
}

void subtr(long long &a, long long b)
{
    a=(a-b+modd)%modd;
}

long long f(int x) // pow(2,pow(2,n))
{
    long long ans=2;
    for(int i=0; i<x; i++)
    {
        mult(ans,ans);
        //cerr << i << " " << x << " " << ans << endl;
    }
    return ans;
}

long long dp2[MAX_N][MAX_N];

long long ways2(int nb_groups, int nb_objects)
{
    if(dp2[nb_groups][nb_objects]!=-1) return dp2[nb_groups][nb_objects];
    if(nb_groups==0) return dp2[nb_groups][nb_objects]=1;
    if(nb_groups>nb_objects) return dp2[nb_groups][nb_objects]=0;
    long long ans=ways2(nb_groups, nb_objects-1);
    add(ans,ways2(nb_groups-1, nb_objects-1));
    add(ans,nb_groups*ways2(nb_groups,nb_objects-1));
    return dp2[nb_groups][nb_objects]=ans;
}

long long dp[MAX_N];
long long macht2[MAX_N][MAX_N];
long long ways(int aantal)
{
    if(dp[aantal]!=-1) return dp[aantal];
    long long ans=0;
    for(int i=0; i<=aantal; i++) {
            add(ans,(macht2[n-aantal][i]*ways2(i,aantal))%modd);
            //cerr << i << " " << aantal << " " << ways2(i,aantal) << " " << macht2[n-aantal][i] << endl;
    }
    //cerr << "ans: " << ans << endl;
    mult(ans,f(n-aantal));
    return dp[aantal]=ans;
}

int main()
{
    //freopen("inp.in", "r", stdin);
    scanf("%d %lld", &n, &modd);
    //cerr << "11" << endl;
    for(int i=0; i<MAX_N; i++)
    {
        dp[i]=-1;
        for(int j=0; j<MAX_N; j++){
            comb[i][j]=1;
            macht2[i][j]=1;
            dp2[i][j]=-1;
        }
    }
    //cerr << "22" << endl;
    for(int i=1; i<MAX_N; i++)
    {
        //cerr << i << endl;
        mult(macht2[i][1],2*macht2[i-1][1]);
        //cerr << i << endl;
        if(i != 1) mult(macht2[1][i],2*macht2[1][i-1]);
    }
    //cerr << "33" << endl;
    for(int i=2; i<MAX_N; i++)
    {
        for(int j=2; j<MAX_N; j++)
        {
            mult(macht2[i][j],macht2[i][j-1]*macht2[i][1]);
        }
    }
    //cerr << "44" << endl;
    for(int i=2; i<MAX_N; i++)
    {
        for(int j=1; j<i; j++)
        {
            add(comb[i][j],comb[i-1][j-1]+comb[i-1][j]-1);
        }
    }
    //cerr << "55" << endl;
    long long ans=f(n);
    //cerr << "n: " << n << endl;
    //cerr << ans << endl;
    for(int i=1; i<=n; i++)
    {
        if(i&1)
        {
            //cerr << i << " " << comb[n][i] << endl;
            //cerr << "ways(" << i << "):" << ways(i) << endl;
            subtr(ans,(comb[n][i]*ways(i))%modd);
        }
        else
        {
            add(ans,(comb[n][i]*ways(i))%modd);
        }
    }
    printf("%lld\n",ans);
    return 0;
}
