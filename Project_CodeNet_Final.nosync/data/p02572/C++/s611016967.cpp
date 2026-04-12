#include <bits/stdc++.h>
  
using namespace std;
 
#define endl "\n"
#define JAM(x) cout<< #x <<" = "<<x<<"\n"
#define II() ( { int a ; read(a) ; a; } )
#define LL() ( { ll a ; read(a) ; a; } )
#define DD() ({double a; scanf("%lf", &a); a;})
 
 
//Fast Reader
template<class T>inline bool read(T &x){
    int c=getchar();int sgn=1;
    while(~c&&c<'0'||c>'9'){if(c=='-')sgn=-1;c=getchar();}
    for(x=0;~c&&'0'<=c&&c<='9';c=getchar())x=x*10+c-'0'; 
    x*=sgn; return ~c;
}
 
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int,int> PII;
typedef vector<PII> VPI;
 
const int INF=2e9;
const int MX=100005;
const int MOD=1000000007;
const double PI=acos(-1.0);




long long int power(long long int a,long long int b)
{
    a %= MOD;
    long long int res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}
bool isprime(int n)
{
    if(n==1)
    return 0;
    int i;
    for(i=2;i*i<=n;i++)
    {
        if(n%i==0)
        return false;
    }
    return true;
}



/*_______________________________________________*/





int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    long int m=(1000000007);
    long int a[n];
    long int sm=0,i;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    long long int ans=0;
    for(i=n-1;i>=0;i--)
    {
        ans=(ans+(sm*a[i]+m)%m+m)%m;
        sm=((sm+a[i])%m)%m;
    }
    cout<<ans;
}
