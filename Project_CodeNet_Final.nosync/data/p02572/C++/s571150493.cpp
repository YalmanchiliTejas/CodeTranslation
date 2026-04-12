#include <bits/stdc++.h>
using namespace std;

#define    int               long long int
 #define    sp(x)                 setprecision(x)
#define    bp(x)           __builtin_popcount(x)
 #define  ld         long double
 #define  f(i,j,n)            for(int i = j; i <= n; i++)
#define  r(i,n,j)       for(int i = n; i >= j; i--)
 #define  all(container)       container.begin() , container.end()
#define  sz(container)   (int)container.size()
 #define  ff             first
#define  ss             second
 #define  pii      pair <int , int>
#define  sp(x)       setprecision(x)
 #define  endl    "\n"
#define  mod  1000000007
 #define  pb    push_back
#define  mp    make_pair
 #define  T     int ttt; cin >> ttt; while(ttt--)
#define fast ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);

int power(int x, int y, int p)  
{  
    int res = 1;    
    x = x % p; 
    if (x == 0) return 0; 
    while (y > 0)  
    {     
        if (y & 1)  
            res = (res*x) % p;  
        y = y>>1; 
        x = (x*x) % p;  
    }  
    return res; 
}

int32_t main()
{
    fast
    int n,ans=0,c=0;
    cin>>n;
    int a[n+1];
    f(i,1,n)    cin>>a[i];
    r(i,n,1)
    {
        ans=(ans+ (c*a[i])%mod)%mod;
        c=(c+a[i])%mod;

    }
    cout<<ans;
}