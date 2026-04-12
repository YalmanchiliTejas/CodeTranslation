#include <bits/stdc++.h>

#define int long long
#define counter(m)     for(int i=0;i<m;i++)
#define gcd            __gcd
#define endl           "\n"
#define pb             emplace_back
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
    int n;
    cin>>n;
    int sum=0;
    int ssum=0;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        sum=(sum+a)%mod;
        ssum=(ssum+a*a)%mod;
    }
    sum=(sum*sum)%mod;
    sum=(sum-ssum+mod)%mod;
    cout<<(sum*modi(2,mod))%mod<<endl;
    return 0;
}