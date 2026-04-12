#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;
typedef long long int ld;
typedef unsigned long long int lu;
typedef vector< int > vi;
typedef vector < ld > vd;
typedef set <ld> sd;
typedef vector< vi > vvi;
typedef vector< vd > vvd;
typedef pair< int,int > ii;
typedef pair< ld,ld > id;
#define sz(a) ld((a).size())
#define test(t) ll t;cin>>t;while(t--)
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define Vi vector
#define pr pair
#define mpr make_pair
#define fi first
#define se second
#define isnum(a) (a>=48 && a<=57)
#define isS(a) (a>='a' && a<='z')
#define isU(a) (a>='A' && a<='Z')
#define toS(a) (isU(a)?a+32:a)
#define toU(a) (isS(a)?a-32:a)
#define toC(a) a&15

set <ld> s[100005];
ld d[100005];

vector<char> prime (100000+1, true);
void sieve(ld n)
{	
	//O(nloglogn) time
	prime[0] = prime[1] = false;
	for (ld i=2; i<=n; ++i)
	{
		if (prime[i])
		{
			s[i].insert(i);			
			for (ld j=2*i; j<=n; j+=i)
			{
				prime[j] = false;
				s[j].insert(i);
			}
		}
	}
}
#define forn(i,e) for(int i = 0; i < e; i++)
#define rep(i,a,b) for(i=a;i<b;i++)
#define REP(i,a,b) for(i=a;i<=b;i++)
#define reprev(i,a,b) for(i=a;i>=b;i--)

#define leadzero(a) __builtin_clz(a) //count leading zeros
#define trailzero(a) __builtin_ctz(a) //count trailing zeros
#define bitcount(a) __builtin_popcount(a) // count set bits (add ll)
#define ln cout<<"\n"
#define sp cout<<" "
#define maxe(a) *max_element(a.begin(),a.end())
#define maxi(a) max_element(a.begin(),a.end())-a.begin()
#define mine(a) *min_element(a.begin(),a.end())
#define mini(a) min_element(a.begin(),a.end())-a.begin()
ld gcd(ld a, ld b) { if(b == 0) return a; return gcd(b, a % b); }
ld fastpowMOD(ld a, ld p,ld MOD){ if(p==0) return 1; ld z = fastpowMOD(a,p/2,MOD); z = (z*z)%MOD; if(p%2) z = (z*a)%MOD; return z; }
ld fastpow(ld a, ld p){ if(p==0) return 1; ld z = fastpow(a,p/2); z = (z*z); if(p%2) z = (z*a); return z; }
ld a,b;

ld search1(ld a[], ld f,ld n)
{
	ld left=1;
	ld right=n+1;
	while(right-left>1)
	{
		ld mid = left + (right-left)/2;
		if(a[mid]<f)
		{
			left=mid;
		}
		else right=mid;
	}
	return a[left];
}
ld MOD = 1e9+7;
int main(){
	string k;
	cin >> k;
	ld n = k.length();
	ld d,i,j,t;
	cin >> d;
	ld dp[n][d];
	ld dp2[n][d];
	memset(dp,0,sizeof(dp));
	memset(dp2,0,sizeof(dp2));
	ld num = k[n-1]-'0';
	for(i=0;i<10;i++)
	{
		dp2[n-1][i%d]+=1;
	}
	for(i=0;i<=num;i++)
	{
		dp[n-1][i%d]+=1;
	}
	for(i=n-2;i>=0;i--)
	{
		for(j=0;j<10;j++)
		{
			for(t=0;t<d;t++)
			{
				dp2[i][t]+=dp2[i+1][((t-j)%d+d)%d]%MOD;
			}
		}
		num = k[i]-'0';
		for(j=0;j<num;j++)
		{
			for(t=0;t<d;t++)
			{
				dp[i][t]+=dp2[i+1][((t-j)%d+d)%d]%MOD;
			}
		}
		for(t=0;t<d;t++)
		{
			dp[i][t]+=dp[i+1][((t-num)%d+d)%d]%MOD;
		}
	}
	cout << (dp[0][0]-1+MOD)%MOD << endl;
	return 0;
}