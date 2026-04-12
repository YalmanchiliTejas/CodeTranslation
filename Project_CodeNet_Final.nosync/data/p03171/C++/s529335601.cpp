/*
                " اللهم صلي و سلم علي سيدنا محمد و علي اله وصحبه اجمعين "
*/

#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#define f for
#define ll long long
#define ull unsigned long long
#define endl "\n"
#define intial(s1,s2,x,dp) f(int i = 0; i < s1; i++)f(int j = 0; j < s2; j++)dp[i][j] = x;
using namespace std;
#define BI  acos(-1)
#define all(a) a.begin(), a.end()
#define loop1(n) f(int i=0;i<n;i++)
#define loop2(n) f(int j=0;j<n;j++)
#define oo 1e9;
void Open()
{
    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
}
ll gcd(ll a, ll b)
{
    return b == 0 ? a : gcd(b, a % b);
}
void madesetprobblem()
{
    //$ $
    //less than or equal => $ 1 \leq 100 $
    //  $(1 \le A,B \le 10^5 )$
    // a[i] => $a_i$
    // a[i][j] => $a_{i,j}$
    // double qoutes ''yext''
    /*
        image
        \begine{center}
        \includegraphics{image.jpg}
        \end{center}
    */
    /*
        list
        \begin{itemize}
            \item first one
            \item second one
        \end{itemize}
    */
}
ll n,k,*a;
ll dp[3001][3001][2];
ll ans(int i=0,int j=n-1,int p=0)
{
    //  cout<<x<<' ';
    if(i==j)
        return (p?-a[i]:a[i]);
    ll& ret=dp[i][j][p];
    if(~ret)
        return ret;
    if(!p)
    {
        return ret=max(ans(i+1,j,!p)+a[i],ans(i,j-1,!p)+a[j]);
    }
    else
    {
        return ret=min(ans(i+1,j,!p)-a[i],ans(i,j-1,!p)-a[j]);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    memset(dp,-1,sizeof(dp));
    cin>>n;
    a=new ll[n];
    loop1(n)cin>>a[i];
    cout<<ans();
}
