/*  chuckie   */
#include <bits/stdc++.h>
//#define CHUCKIE
 
#define cint(d) scanf("%d", &d)
#define cint2(a, b) scanf("%d %d", &a, &b)
#define cint3(a, b, c) scanf("%d %d %d", &a, &b, &c)
#define cint4(a, b, c, d) scanf("%d %d %d %d", &a, &b, &c, &d)
 
#define clong(d) scanf("%lld", &d)
#define clong2(a, b) scanf("%lld %lld", &a, &b)
#define clong3(a, b, c) scanf("%lld %lld %lld", &a, &b, &c)
#define clong4(a, b, c, d) scanf("%lld %lld %lld %lld", &a, &b, &c, &d)
 
const long long MOD = 10e9 + 7;
#define MODSET(d) if ((d) >= MOD) d %= MOD;
#define MODR(d) ((d)>=MOD?(d)%MOD:(d))
#define MODNEGSET(d) if ((d) < 0) d = ((d % MOD) + MOD) % MOD;
#define MODADDSET(d) if ((d) >= MOD) d -= MOD;
#define MODADDWHILESET(d) while ((d) >= MOD) d -= MOD;
 
#define foreach(it,c) for(__typeof((c).begin()) it = (c).begin(); it!=(c).end(); it++) 
#define MAX 1000000
#define ll long long
#define mp make_pair
#define pb push_back
 
using namespace std;

ll negmod(ll number, ll mod)
{
    if(number >= 0) return number % mod;
    return (mod + (number % mod)) % mod;
}



// To compute (a * b) % mod
ll mulmod(ll a, ll b, ll mod)
{
    ll res = 0; // Initialize result
    a = a % mod;
    while (b > 0)
    {
        // If b is odd, add 'a' to result
        if (b % 2 == 1)
            res = (res + a) % mod;
 
        // Multiply 'a' with 2
        a = (a * 2) % mod;
 
        // Divide b by 2
        b /= 2;
    }
 
    // Return result
    return res % mod;
}
 
 
int main()
{
	#ifdef CHUCKIE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin>>n;
	
	int cnt[27],cnttemp[27];
	memset(cnt,0,sizeof(cnt));
	memset(cnttemp,0,sizeof(cnttemp));
	
	
	string temp;
	cin>>temp;
	
	for(int i=0;i<temp.length();i++)
	cnt[temp[i]-'a']++;
	
	for(int i=1;i<n;i++)
	{
		cin>>temp;
		memset(cnttemp,0,sizeof(cnttemp));
		for(int j=0;j<temp.length();j++)
		{
			cnttemp[temp[j]-'a']++;
		}
		
		for(int j=0;j<26;j++)
		{
			cnt[j]=min(cnt[j],cnttemp[j]);
		}
		
		
	}
	
	for(int i=0;i<26;i++)
	{
		if(cnt[i]>0)
		{
			for(int j=0;j<cnt[i];j++)cout<<(char)('a'+i);
		}
	}
	
	cout<<endl;
	
	cout<<endl;
	return 0;
}
