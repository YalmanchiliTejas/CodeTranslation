#include<bits/stdc++.h>
#define rc(x) return cout<<x<<endl,0
#define pb push_back
#define in insert
#define er erase
#define fr first
#define sc second
const int inf=INT_MAX;
const int nmax=2e5+5;
const int mod=1e9+7;
typedef long long ll;
using namespace std;
int n,i,lo,hi,cur;
ll a[nmax],ans[nmax];
int main() 
{
    ios_base::sync_with_stdio(false);cin.tie(0);cerr.tie(0);cout.tie(0);
    cin>>n;
    for(i=1;i<=n;i++)cin>>a[i];
    lo=0,hi=cur=n+1;
    for(i=1;i<=n;i++)
	{
		if(i%2!=0)ans[++lo]=a[--cur];
		else ans[--hi]=a[--cur];
	}
	for(i=1;i<=n;i++)cout<<ans[i]<<" ";cout<<endl;
	return 0;
}