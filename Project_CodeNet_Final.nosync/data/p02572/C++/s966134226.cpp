#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=200005;
ll n,a[N];
ll sum[N],ans;
ll INF=1e9+7;
int main()
{
	cin>>n;
	for (int i=0;i<n;++i) cin>>a[i];
    for (int i=n-1;i>=0;--i) sum[i]=(sum[i+1]+a[i])%INF;
    //for (int i=0;i<n;++i) cout<<sum[i]<<" ";
    for (int i=0;i<n-1;++i)
    {
        ans%=INF;
        ans+=a[i]*sum[i+1]%INF;
        ans%=INF;
    }
    cout<<ans;
	return 0;
}