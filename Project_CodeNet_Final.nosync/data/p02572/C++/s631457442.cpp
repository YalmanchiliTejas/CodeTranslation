#include<bits/stdc++.h>
#include<string.h>
#include<vector>
#include<set>
#include<map>
#include<stack>
#include<queue>
#define endl  "\n"
#define ll long long
#define int long long
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cin.exceptions(cin.failbit);cout.tie(NULL);
using namespace std;
bool isPrime(int n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (int i = 5; i * i <= n; i += 6)
    {
        if ((n % i == 0) || (n % (i + 2) == 0))
            return false;
    }
    return true;
}
int mod=1e9+7;
int32_t main()
{
	int t=1;
	while(t--)
	{
		int n;
		cin >> n;
		int a[n];
		int pref[n]={0};
		int suf[n]={0};
		for(int i=0;i<n;i++)
		{
			cin >> a[i];
			pref[i]=a[i];
			
			suf[i]=a[i];
		}
		
		for(int i=0;i<n;i++)
		{
			pref[i]+=pref[i-1];
			pref[i]%=mod;
			
		}
		for(int i=n-2;i>=0;i--)
		{
			suf[i]+=suf[i+1];
			suf[i]%=mod;
		}
		int ans=0;
		for(int i=0;i<n-1;i++)
		{
			ans+=(a[i]*suf[i+1]);
			ans%=mod;
		}
		cout << ans;
	}
}


