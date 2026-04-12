#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
inline long long add(long long a,long long b) 
{
    long long ADD = (a % mod + b % mod) % mod;
    return ADD;
}
inline long long mul(long long a,long long b) 
{
    long long MUL = (a % mod * b % mod) % mod;
    return MUL;
}
long long fastpow(long long x,long long y)
{
    long long res = 1;
    x = x % mod;
    while (y > 0)
    {
        if(y & 1)
            res = (res * x) % mod;
        y = y >> 1;
        x = (x * x) % mod;
    }
    return res;
}
long long inv(long long x)
{
    return fastpow(x,mod - 2);
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int testCases = 1;
   // cin >> testCases;
    
    while(testCases--)
    {
        
        int n,i,j;
        cin >> n;
        int a[n];
        int sum = 0;
        int pro = 0;
        for(i = 0;i < n;++i)
			{
				cin >> a[i];
				sum = add(sum,a[i]);
				int res = mul(a[i],a[i]);
				pro = add(pro,res);
				//pro = pro % mod + ((a[i] % mod * a[i] % mod) % mod) % mod;
			}
			
		int ans = mul(sum,sum);
		
		ans = (ans - pro + mod) % mod;
		
		ans = mul(ans,inv(2LL));
		//ans = (ans % mod * fastpow(2,mod - 2) % mod) % mod;
		
		cout << ans;
			
        cout << '\n';
    }
    
}
