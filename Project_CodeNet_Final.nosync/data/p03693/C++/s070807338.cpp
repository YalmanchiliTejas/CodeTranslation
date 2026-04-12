
#include<bits/stdc++.h>
#define lln long long int
#define llu unsigned lln
#define sc(n) scanf("%d",&n);
#define scl(n) scanf("%lld",&n);
#define scd(n) scanf("%lf",&n);
#define pf(res) printf("%d\n",res);
#define pfl(res) printf("%lld\n",res);
#define pfd(res) printf("%lf\n",res);
#define pb(n) push_back(n);
#define maxii 100005
using namespace std;
typedef pair<int,int> pii;
typedef pair<lln,lln> pll;
vector<int> vi;
vector<lln> vl;
vector<pii> vii;
vector<pll> vll;


char arr[105][105];
int arr2[maxii];
bool check[maxii];
bool check2[1000][1000];
int n,m;
int x[]={1,-1,0,0};
int y[]={0,0,-1,1};
int x2[]={1,-1,0,0,1,-1,1,-1};
int y2[]={0,0,-1,1,1,-1,-1,1};
int bx[]={0,0,1,-1,-1,1,1,-1};
int by[]={1,-1,0,0,-1,-1,1,1};
int kx[] = {1,1,2,2,-1,-1,-2,-2};
int ky[] = {2,-2,1,-1,2,-2,1,-1};

bool isvisited(int x,int y)
{
    if(x<1 || y<1 || x>n ||y>m)
    {
        return false;
    }
    else if(check2[x][y]==true)
    {
        return false;
    }
    else true;
}
int gcd(int a,int b)
{
    if(b==0){
      return a;
     }
    return gcd(b,a%b);
}
int lcm(int a,int b)
{
    int res=(a*b)/gcd(a,b);
    return res;
}
int po(int a,int b)
{
    int res=1;
    while(b)
    {
        if(b%2!=0)
        {
            res*=a;
            b--;
        }
        else
        {
            a*=a;
            b/=2;
        }
    }
    return res;
}

lln modMul(lln  a, lln b,lln mod){
    lln ans = 0;
    a = a % mod;
    while (b > 0){
        if ( b % 2 )ans = (ans%mod+ a%mod) % mod;
        a = (a%mod * 2%mod) % mod;
        b /= 2;
    }
    return ans % mod;
}
lln powerMod(lln a,lln b,lln mod){
	if(b==0)return 1LL%mod;
	lln x=powerMod( a,b/2,mod );
	x = ( x%mod * x%mod ) % mod;
	if( b%2==1 )x = ( x%mod * a%mod ) % mod;
	return x%mod;
}

int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    a*=100;
    b*=10;
    a=a+b+c;
    if(a%4==0)cout<<"YES";
    else cout<<"NO";
}



