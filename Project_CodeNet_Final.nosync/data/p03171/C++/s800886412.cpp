
//#include "stdc++.h"
#include<bits/stdc++.h>
#include<iostream>
#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:336777216")
using namespace std;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//typedef tuple<int, int, int> t3;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <db, db> pdd;
typedef vector<int> vi;
#define m1 make_pair
#define pb push_back
#define IOS std::ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
inline ll gcd(ll a,ll b){if(a==0) return b;return gcd(b%a,a);}
inline ll power(ll a,ll n,ll m){if(n==0) return 1;ll p=power(a,n/2,m);p=(p*p)%m;if(n%2) return (p*a)%m;else return p; }
#define flush fflush(stdout)
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;

int main()
{
    IOS;//ifstream fin("input.txt");ofstream fout("output.txt");
    int n;
    cin>>n;
    ll a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    ll dp[n][n][2];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        {
            dp[i][j][0]=0;
            dp[i][j][1]=LL_INF;
        }
    for(int i=0;i<n;i++)
    {
        dp[i][i][0]=a[i];
        dp[i][i][1]=-a[i];
    }
    int j;
    for(int l=2;l<=n;l++)
    {
        for(int i=0;i<=(n-l);i++)
        {
            j=i+l-1;
            dp[i][j][0]=max(a[i]+dp[i+1][j][1],a[j]+dp[i][j-1][1]);
            dp[i][j][1]=min(dp[i+1][j][0]-a[i],dp[i][j-1][0]-a[j]);
        }
    }
    cout<<dp[0][n-1][0]<<endl;
    return 0;
}
