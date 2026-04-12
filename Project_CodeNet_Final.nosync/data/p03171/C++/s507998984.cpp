#include <bits/stdc++.h>
#include<string.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define Max(x,y,z) max(x,max(y,z))
#define Min(x,y,z) min(x,min(y,z))
#define fr(i,s,e) for(i=s;i<e;i++)
#define rf(i,s,e) for(i=s-1;i>=e;i--)
#define pb push_back
#define eb emblace_back
#define mp make_pair
#define ff first
#define ss second
#define int   long long
#define ll   long long
#define trace1(x)                cerr<<#x<<": "<<x<<endl
#define trace2(x, y)             cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define trace3(x, y, z)          cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define trace4(a, b, c, d)       cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl
#define trace5(a, b, c, d, e)    cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<endl
#define trace6(a, b, c, d, e, f) cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<" | "<<#f<<": "<<f<<endl
#define vl vector<long long>
#define inf (1LL<<51)
#define vi vector<int> 
#define vii vector< vector<int> >
#define vll vector< vector<long long> >
#define vpi vector< pair<int,int> >   
#define vpl vector< pair<ll,ll> >   
#define viii vector< vector<vector<int> > >
typedef pair<pair<int, int>,int> P;
#define cd complex<double>
#define PI 4*atan(1)
#define mod 1000000007
#define pi 3.14159265358979323846//20 decimals
#define ld long double
#define all(c) (c).begin(),(c).end()
#define N 3000
int n,k;
int a[N];
int dp[3001][3001][2];
bool vis[3001][3001][2];
int rec(int be,int en,int ch)
{
    if(be > en)
        return 0;
  
    if(vis[be][en][ch] == 0)
    {
        vis[be][en][ch] = 1;
        int ans = 0;
        if(ch)
        {
            ans =  - a[be] + rec(be+1,en,!ch);
            ans = min(ans,-a[en] + rec(be,en-1,!ch));
        }
        else
        {
            ans = a[be] + rec(be+1,en,!ch);
            ans = max(ans,a[en] + rec(be,en-1,!ch));

        }
        dp[be][en][ch] = ans;
        return ans;
    }
    else
        return dp[be][en][ch];
}

int32_t main()
{                
    IOS;
    
   
    memset(dp,-1,sizeof(dp));
    memset(vis,0,sizeof(vis));
    cin>>n;
    for(int i = 0;i < n;i++)
        cin>>a[i];
    cout<<rec(0,n-1,0);
    return 0;

}