#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

#define trace1(x)                cerr<<#x<<": "<<x<<endl
#define trace2(x, y)             cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define trace3(x, y, z)          cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl

template<typename T> T gcd(T a,T b) { if(a==0) return b; return gcd(b%a,a); }
template<typename T> T pow(T a,T b, long long m){T ans=1; while(b>0){ if(b%2==1) ans=(ans*a)%m; b/=2; a=(a*a)%m; } return ans%m; }

const int N=1e6+5;

int n, k, b;

int check(int m)
{
	int val=b*m + k;
	return (val<=n);
}

int binsearch(int lo, int hi)
{
	while(lo<hi)
	{
		int mid=(lo+hi+1)/2;
		if(check(mid))
			lo=mid;
		else
			hi=mid-1;
	}
	return lo;
}

int32_t main()
{
    IOS;
    cin>>n>>k;
    int ans=0;
    for(b=k+1;b<=n;b++)
    {
    	int range=(b-k);
    	range*=(n/(b));
    	ans+=range;
    	int extra=n%(b);
    	extra-=max(0LL, (k-1));
    	ans+=max(0LL, extra);
    }
    cout<<ans;
    return 0;
} 