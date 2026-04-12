#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#define rc(x) return cout<<x<<endl,0
#define pb push_back
#define in insert
#define er erase
#define fd find
#define fr first
#define sc second
typedef long long ll;
const ll INF=0x3f3f3f3f3f3f3f3f;
const ll llinf=-(1LL<<61);
const int inf=(1<<30);
const int nmax=2e5+50;
const int mod=1e9+7;
using namespace std;
int n,i,b[nmax];
pair<ll,int>a[nmax];
int main()
{
    //freopen("sol.in","r",stdin);
	//freopen("sol.out","w",stdout);
	ios_base::sync_with_stdio(false);cin.tie(0);cerr.tie(0);cout.tie(0);
    cin>>n;
    for(i=1;i<=n;i++)cin>>a[i].fr,a[i].sc=i;
    sort(a+1,a+n+1);
    for(i=1;i<=n;i++)b[a[i].sc]=i;
	for(i=1;i<=n;i++)
	{
		if(b[i]>n/2)cout<<a[n/2].fr<<endl;
		else cout<<a[n/2+1].fr<<endl;
	}
	return 0;
}