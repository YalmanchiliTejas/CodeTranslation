#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long int lli;
const lli N=1e5+5;
lli fact[N], M, a[N], pre[N];

lli binpow(lli a,lli b) 
{
    if (b == 0) return 1;
    lli res = binpow(a,b/2);
    res= (res*res)%M;
    
    if(b%2) return (res*a)%M;
    return res;
}
 
lli inv(lli a)
{
    return binpow(a,M-2);
}

lli add(lli a, lli b)
{
	lli res = a + b;
	if(res >= M)
		return res - M;
	return res;
}
 
lli mul(lli a, lli b)
{
	lli  res = a * b;
	if(res >= M)
		return res % M;
	return res;
}
 
lli sub(lli a, lli b)
{
	return (a%M -b%M +M) %M;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    lli n, x;
    cin>>n>>x>>M;
    lli i, tot = 1, cur = x, ans = 0;
    map<lli ,lli> mp;
    
    while(1)
    {
        if(mp.find(cur) != mp.end())
        {
            lli rem = n - tot + 1;
            lli sz = tot - mp[cur];
            
            lli round = rem / sz;
            ans += (round * (pre[tot-1] - pre[mp[cur] - 1]));
            
            rem -= (round * sz);
            
            for(int i=mp[cur];;i++)
            {
                if(rem == 0)
                    return cout<<ans, 0;
                
                ans += a[i];
                rem--;
            }
        }
        
        mp[cur] = tot;
        a[tot] = cur;
        ans += cur;
        pre[tot] += pre[tot-1] + a[tot];
        
        if(tot == n) 
            return cout<<ans, 0;
            
        tot++;
        cur = mul(cur, cur);
    }
    return 0;
}