

#include <bits/stdc++.h>
using namespace std;
 
#define fill(a,val) memset(a, (val), sizeof a)
#define pb push_back
#define lli long long int
#define scantype int
#define endl "\n"
#define unique(x) x.erase(unique(x.begin(),x.end()), x.end())
#define debug(x) cerr << #x " = " << (x) << '\n'
#define what_is(x) cerr << #x << " is " << x << endl;
 
lli MOD  = 1000000007;
lli inf = 1e15;
 
void scan(scantype &x);

lli powermod(lli _a,lli _b,lli _m){lli _r=1;while(_b){if(_b%2==1)_r=(_r*_a)%_m;_b/=2;_a=(_a*_a)%_m;}return _r;}
lli string_to_number(string s){lli x=0; stringstream convert(s); convert>>x; return x;}
lli add(lli a,lli b){lli x = (a+b)%MOD; return x; }
lli mul(lli a,lli b){lli x = (a*b)%MOD; return x; }
lli sub(lli a,lli b){lli x = (a-b+MOD)%MOD; return x; }
lli div(lli a,lli b){lli x = a;lli y = powermod(b,MOD-2,MOD);lli res = (x*y)%MOD;return res;}

bool isprime(long long int n)
{
    if(n ==1 )
        return false;
    if(n == 2)
        return true;
    for(long long int i =2;i<=n/i;i++)
    {
        if(n%i == 0)
            return false;
    }
    return true;
}
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);   
    int t;
    t = 1;
    while(t--)
    {

        int n;
        cin>>n;
        int a[n];
        for(int i = 0;i<n;i++)
            cin>>a[i];
        for(int i = n-1;i>=0;i-=2)
        {
            cout<<a[i]<<" ";
        }
        if(n%2)
        {
            for(int i = 1;i<n;i+=2)
                cout<<a[i]<<" ";
        }
        else
            for(int i = 0;i<n;i+=2)
                cout<<a[i]<<" ";
    }    


    
    return 0;    
}
 

void scan(scantype &x)
{
    register int c = getchar(); //for negative/positive
    x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = getchar());
    if(c=='-') {neg=1;c=getchar();}
    for(;c>47 && c<58;c = getchar()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}
