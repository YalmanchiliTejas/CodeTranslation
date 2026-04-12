
#include <bits/stdc++.h>
#define lli long long int
#define vec2 vector<vector<lli>>
#define fio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define FRE freopen("input.txt","r",stdin);freopen("ans.txt","w",stdout)
#define mp make_pair
#define pll pair <lli,lli>
#define vll vector <lli>
#define pq2 priority_queue<pair<lli,lli>>
#define f first
#define s second
#define pb push_back
#define pf push_front
#define minii LLONG_MAX
#define all(x) x.begin(), x.end()
#define mem(a,b) memset(a,b,sizeof(a))
#define ld long double
const long double pi = 3.1415926535898;
#define dec greater<lli>()
const lli mod=1000000007;
//const lli mod=100000000;
using namespace std;
lli lcm (lli a, lli b) {return ((a*b)/__gcd(a,b));}
lli modpower (lli a,lli b)
{
    if(b==0) return 1;
    lli c=modpower(a,b/2)%mod;
    if (b%2) return (((a*c)%mod)*c)%mod;
    else return (c*c)%mod;
}
lli power (lli a,lli b)
{
    if(b==0) return 1;
    lli c=power(a,b/2);
    if (b%2) return (a*c*c);
    else return c*c;
}
bool prime (lli k)
{
    if (k==1||k==0) return 0;
    bool flag=1;
    lli a=sqrt(k);
    for (int i=2;i<=a;i++)
    {
        if (k%i==0)
        {flag=0;break;}
    }
    return flag;
}
lli sieve (int n)
{
    bool qrr[n+1];
    for (int i=0;i<=n;i++)
    qrr[i]=1;qrr[0]=0;qrr[1]=0;
    for (int i=2;i<=n;i++)
    {
        if (qrr[i]==1)
        {
            for (int j=i;j<=n;j+=i)
            {qrr[j]=0;}
        }
    }
    return 0;
}
int main()
{
    lli n;
    cin>>n;
    if (n>=30)
    cout<<"Yes";
    else
    cout<<"No";
    return 0;
}