#include <bits/stdc++.h>

#define int long long
#define gcd            __gcd
#define setbits(x)     __builtin_popcountll(x)
#define zrobits(x)     __builtin_ctzll(x)
#define mod            1000000007
#define mod2           998244353
#define maxe           *max_element
#define mine           *min_element
#define inf            1e18
#define deci(x, y)      fixed<<setprecision(y)<<x
#define w(t)           int t; cin>>t; while(t--)
#define nitin          ios_base::sync_with_stdio(false); cin.tie(NULL)
#define PI             3.141592653589793238
using namespace std;

int power(int x, int y, int p) {
    int res = 1;
    x = x % p;
    while (y > 0) {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}

int modi(int a, int m) {
    return power(a, m - 2, m);
}
int32_t main() {
    nitin;
    int n,m;
    cin>>n>>m;
    char a[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    int i=0;
    int j=0;
    a[0][0]='v';
    while(true)
    {
        if(i==n-1 && j==m-1)
        {
            a[i][j]='v';
            break;
        }
        if(i==n-1)
        {
            if(a[i][j+1]=='#')
            {
                a[i][j+1]='v';
                j++;
            }
            else{
                break;
            }
        }
        else if(j==m-1)
        {
            if(a[i+1][j]=='#')
            {
                a[i+1][j]='v';
                i++;
            }
            else{
                break;
            }
        }
        else
        {
            if(a[i][j+1]=='#')
            {
                a[i][j+1]='v';
                j++;
            }
            else if(a[i+1][j]=='#')
            {
                a[i+1][j]='v';
                i++;
            }
            else{
                break;
            }
        }
    }
    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
        {
            if(a[i][j]=='#')
                cnt++;
        }
    }
    if(cnt==0)
        cout<<"Possible";
    else
        cout<<"Impossible";
    return 0;
}