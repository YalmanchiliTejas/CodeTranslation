#include <bits/stdc++.h>
using namespace std;
#define si(a) scanf("%d",&a)
#define sll(a) scanf("%lld",&a)
#define sl(a) scanf("%ld",&a)
#define pi(a) printf("%d\n",a)
#define pl(a) printf("%ld\n",a)
#define pll(a) printf("%lld\n",a) 
#define sc(a) scanf("%c",&a)a
#define pc(a) printf("%c",a)
#define ll long long
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define INF INT_MAX
#define fr(i,a,b) for(int i=a;i<=b;i++)
#define VI vector<int>
#define VL vector<ll>
#define PI pair<int,int>
#define PL pair<ll,ll>
long double PIE=acos(-1);
//////////////////////////////////////////////////////////////
const ll N=1e5+5;
ll Ans=1;
bool done[1000009];
vector < ll > primes;

void FindPrime(ll N)
{
    done[1] = 1;
    for(int i=2;i<=N;i++)
	{
        if(done[i]) continue;
        for(int j=i*2;j<=N;j+=i)
		{
            done[j] = 1;
        }
        primes.push_back(i);
    }
}

ll solve(ll Num)
{
    for(int i=0;i<primes.size();i++)
	{
    	int p=primes[i];
        if(p*p*p > Num) break;
        ll Count = 1;
        while(Num%p == 0)
		{
            Num /= p,Count++;
        }
        Ans *= Count;
    }
    ll sq = (ll)sqrt(Num);
    if(!done[Num]) 
	Ans *= 2;
    else if(sq*sq == Num && !done[sq]) 
	Ans *= 3;
    else if(Num != 1) 
	Ans *= 4;
    return Ans;
}


ll fact[N], invfact[N];



ll pow(ll a, ll b, ll m)
{
	ll ans=1;
	while(b)
	{
		if(b&1)
			ans=(ans*a)%m;
		b/=2;
		a=(a*a)%m;
	}
	return ans;
}

ll modinv(ll k)
{
	return pow(k, mod-2, mod);
}


ll nCr(ll x, ll y)
{
	if(y>x)
		return 0;
	ll num=fact[x];
	num*=invfact[y];
	num%=mod;
	num*=invfact[x-y];
	num%=mod;
	return num;
}

void initinv()
{
	fact[0]=1;
	fr(i,1,N)
	{
		fact[i]=(i*fact[i-1])%mod;
	}
	invfact[N]=modinv(fact[N]);
	for(int i=N-1;i>=1;i--)
	{
		invfact[i]=((i+1)*invfact[i+1])%mod;
	}
}
///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////

int main()
{
	double x;
	cin>>x;
	if(x>=30)
	cout<<"Yes\n";
	else
	cout<<"No\n";
	return 0;
}



//eVTWvt22KTVSm@v