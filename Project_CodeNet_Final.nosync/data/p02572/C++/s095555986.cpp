#include <bits/stdc++.h>
using namespace std;

#define int long long
#define flash ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define pb push_back
#define all(x) begin(x),end(x)

int mod = 1e9+7;
int inf = 4e18;
const int N = 5e5+5;
		
signed main()
{
    flash
    int tt = 1;
    //cin>>tt;
    while(tt--)
    {
		int n;
		cin>>n;
		int arr[n],pre[n];
		for(int i=0;i<n;++i)
		{
			cin>>arr[i];
			if(i==0)
			pre[i] = arr[i];
			else
			pre[i] = pre[i-1]+arr[i];
			pre[i]%=mod;
		}
		int ans = 0;
		for(int i=n-1;i>0;--i)
		{
			(ans+=arr[i]*pre[i-1])%=mod;
		}
		cout<<ans;		
    }
    return 0;
}
