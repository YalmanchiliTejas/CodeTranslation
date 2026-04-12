#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
 
using namespace __gnu_pbds;
using namespace std;
 
typedef   long long int ll;
typedef unsigned long long int sll;
typedef  double ld;
#define A 1000000007ll
#define B 998244353ll
#define C 1000000000000000000ll
#define FAST ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pb push_back
#define mxe(v) *max_element(v.begin(),v.end())
#define mne(v) *min_element(v.begin(),v.end())
#define bs binary_search
#define lb lower_bound
#define ub upper_bound
#define ve vector
#define br break
#define PI 3.1415926535

ll dp[10005][10][105],pre[10005][105],ans[10005][105];

int main() 
{
    FAST;
    string k;
    cin>>k;
    ll n,d;
    n=k.length();
    cin>>d;
    for(int i=0;i<10;i++)
    {
        dp[0][i][i%d]++;
        pre[0][i%d]++;
    }
    for(int i=1;i<10005;i++)
        for(int j=0;j<10;j++)
            for(int w=0;w<d;w++)
            {
                dp[i][j][(w+j)%d]=(dp[i][j][(w+j)%d]+pre[i-1][w])%A;
                pre[i][(w+j)%d]=(pre[i][(w+j)%d]+pre[i-1][w])%A;
            }
    reverse(k.begin(),k.end());
    for(int i=0;i<=k[0]-'0';i++)
        for(int j=0;j<d;j++)
            ans[0][j]=(ans[0][j]+dp[0][i][j])%A;
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<k[i]-'0';j++)
            for(int w=0;w<d;w++)
                ans[i][(w+j)%d]=(ans[i][(w+j)%d]+pre[i-1][w])%A;
        for(int w=0;w<d;w++)
            ans[i][(w+(k[i]-'0'))%d]=(ans[i][(w+(k[i]-'0'))%d]+ans[i-1][w])%A;
    }
    cout<<(ans[n-1][0]+A-1)%A;
    return 0;
}