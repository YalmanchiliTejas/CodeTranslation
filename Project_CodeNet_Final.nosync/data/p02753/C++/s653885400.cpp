#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long int ull;
typedef long long int ll;
typedef vector<ll> vi;

#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define nl cout<<'\n'
#define pb push_back
#define all(s) s.begin(),s.end()
#define bs binary_search

#define gcd(a,b) __gcd((a),(b))
#define lcm(a,b) (a)*(b)/(__gcd((a),(b)))

const int Mod=1e9+7;
#define sum(a,b) (((a)%Mod)+((b)%Mod))%Mod
#define sub(a,b) (((a)%Mod)-((b)%Mod))%Mod
#define mul(a,b) (((a)%Mod)*((b)%Mod))%Mod

#define count1(x) __built_popcount(x)


#define loop(i,s,e) for(i=s;i<e;i++)
#define rloop(i,s,e) for(i=e;i>=s;i--)

#define dbg(x) cout << #x <<":"<<x<<endl;

bool isPowerOfTwo (int x)  
{  
    /* First x in the below expression is for the case when x is 0 */
    return x && (!(x&(x-1)));  
} 

ll pow(ll x, ll y, ll mod)
{
	int ans=1;
	while(y)
	{
		if(y&1)
			ans=(ans*x)%mod;
		y/=2;
		x=(x*x)%mod;
	}
	return ans;
}

int main()
{
	
	fast;
	int i,a=0,b=0;
	string s;
	cin >> s;
	for(i=0;i<3;i++)
	{
		if(s[i]=='A')
			a=1;
		else
			b=1;
	}
	if(a&b)
	{
		cout << "Yes" << endl;
	}
	else
	{
		cout << "No" << endl; 
	}
}