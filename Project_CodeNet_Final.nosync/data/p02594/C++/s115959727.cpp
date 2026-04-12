//syntaxerorr
#include<bits/stdc++.h>
using namespace std;
#define i_am_speed ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define lli long long int
#define f(i,a,b) for(i=a;i<b;i++)
#define r(i,a) for(i=a;i>=0;i--)
#define fr(i,a,b) for(i=a;i>=b;i--)
#define ff first
#define sc second
#define mp make_pair
#define pb push_back
#define nl cout<<endl
#define full(v) v.begin(),v.end()
#define ms(a) memset(a,0,sizeof(a))
#define sz(a) a.size()
#define llu unsigned long long int
#define pi pair<int,int>
#define plli pair<lli,lli>
#define ppl pair<lli,pair<lli,lli> >
#define ppi pair<int,pair<int,int> >
#define vlli vector<lli> v;
#define vii vector<int> v;
#define vl(n) vector<lli> v[n];
#define fu fflush(stdout)
#define in(a,n) lli a[n]; for(lli i=0;i<n;i++)  cin>>a[i];
#define pv(v) for(auto it=v.begin(),v.end(),it++) cout<<*it<<" ";
#define ps(s) for(auto it=s.begin();it!=s.end();it++) cout<<*it<<" ";
#define mod 1000000007
#define mod2 998244353
#define msb(b) memset(b,true,sizeof(b))
#define msf(b) memset(b,false,sizeof(b))
#define MAXN 100005
// bool prime[1000000]; // 10**6
// lli pri[100000],x=0;
/*void sieve()
{
  msb(prime);
  prime[0]=prime[1]=false;
  for(int p=2;p*p<=1000000;p++)
  {
    if(prime[p])
    {
      for(int i=p*2;i<=1000000;i+=p)
        prime[i]=false;
      // a[x++]=p;
    }
  }
} */
/*lli gcd(lli a,lli b)
{
  if(b==0)
    return a;
  return gcd(b,a%b);
} */
/*lli minv(lli a,lli m) // modulo multiplicatve inverse
{
    lli m0 = m;
    lli y = 0, x = 1;
    if (m == 1)
      return 0;
    while (a > 1)
    {
        lli q = a / m;
        lli t = m;
        m = a % m, a = t;
        t = y;
        y = x - q * y;
        x = t;
    }
    if (x < 0)
       x += m0;
    return x;
} */
int main()
{
    i_am_speed;
    int t,n,i;
    cin >> n;
    if(n >= 30)
        cout << "Yes" <<endl;
    else    
        cout << "No" <<endl;
}
