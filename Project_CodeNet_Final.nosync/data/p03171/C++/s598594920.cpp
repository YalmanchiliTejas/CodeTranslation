//#include <bits/stdc++.h>
#include<iostream>
#include <iosfwd>
#include<limits.h>
#include <sstream>
#include <iomanip>
#include <iterator>
#include <algorithm>
#include <limits>
#include<stdio.h>
#include <queue>
#include <stack>
#include <math.h>
#include<string.h>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
#include<vector>
#include <chrono>
#include <random>
#include <bitset>
using namespace std;
#define fr(i,j,n)   for(lli i=j;i<(n);++i)
#define bk(i,j,n)   for(lli i=j;i>=n&&j>=n;--i)
#define pb push_back
#define m_p make_pair
#define F first
#define S second
#define endl "\n"
#define MOD 100000000
#define mem(p,v) memset(p,v,sizeof(p))
#define present(c,x)    ((c).find(x) != (c).end())
#define run ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ordered_set tree<lli, null_type,less<lli>, rb_tree_tag,tree_order_statistics_node_update>
#define debug1(x) cout<<#x<<" "<<x<<endl;
#define debug2(x,y) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<endl;
#define debug3(x,y,z) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<endl;
#define debug4(x,y,z,a) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<#a<<" "<<a<<endl;
#define ub upper_bound
#define lb lower_bound
typedef long long int lli;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<lli> vl;
typedef pair<lli,lli> pl;
inline lli max(lli a,lli b){ return a>b?a:b;}
inline lli min(lli a,lli b){ return a<b?a:b;}
const long long inf = 9e18;
double pie = 2*acos(0.0);
void show(vector<lli> v){fr(i,0,v.size())cout<<v[i]<<" ";cout<<endl;}
void show(vector<int> v){fr(i,0,v.size())cout<<v[i]<<" ";cout<<endl;}
void show(int a[], int arraysize){for (int i = 0; i < arraysize; ++i)cout << a[i] << " ";cout<<endl;}
void show(lli a[], lli arraysize){for (lli i = 0; i < arraysize; ++i)cout << a[i] << " ";cout<<endl;}
void show(bool a[], lli arraysize){for (lli i = 0; i < arraysize; ++i)cout << a[i] << " ";cout<<endl;}
void show(set<int> s){for (auto it = s.begin(); it != s.end(); it++){cout << *it << " ";}cout<<endl;}
void show(map<lli,lli> mp){for (auto it = mp.begin(); it != mp.end(); it++){cout << it->first << " "<<it->second<<endl;}cout<<endl;}

lli modpow(lli x,lli n){lli res=1;while(n>0){if(n&1) res=((res%MOD)*(x%MOD))%MOD;x=((x%MOD)*(x%MOD))%MOD;n>>=1;}return res;}
lli power(lli x, lli n){lli res=1;while(n>0){if(n&1) res=res*x;x=x*x;n>>=1;}return res;}

/////// ------ Main code starts here ------ /////
#define N 3001
lli dp[N][N];
lli a[N];
void solve()
{
    lli n,k;
    cin>>n;
    fr(i,0,n)
    {
        cin>>a[i];
    }
    for(int i=n-1;i>=0;--i)
    {
        for(int j=i;j<n;++j)
        {
            if(j==i)
            {
                dp[i][j]=a[i];
            }
            else
            {
                dp[i][j]=max(a[i]-dp[i+1][j],a[j]-dp[i][j-1]);
            }
        }
    }
    cout<<dp[0][n-1]<<endl;
}
int main()
{
    run;cout<<fixed<<setprecision(12);
    int t;
    t=1;
    while(t){solve();t--;}
    return 0;
}
