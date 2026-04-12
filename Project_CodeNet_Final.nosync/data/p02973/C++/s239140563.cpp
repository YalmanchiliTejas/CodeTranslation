#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;
const int mod=1e9+7;
int m,n,yy[100005],sy[100005],cnt,ans;
unordered_map<int,int> mp;
int main()
{
    std::ios::sync_with_stdio(0); std::cin.tie(0);
	cin>>m;
	for(int i=1;i<=m;++i) cin>>yy[i];
	sy[0]=2e9;
	for(int i=1;i<=m;++i)
	{
		if(yy[i]<=sy[cnt]) sy[++cnt]=yy[i];
		else
		{
			int l=0,r=cnt,mid,e;
			while(l<=r)
			{
				mid=(l+r)>>1;
				if(sy[mid]<yy[i]) r=mid-1;
				else { l=mid+1; e=mid; } 
			}
			sy[e+1]=yy[i];
		}
	}
	//for(int i=1;i<=cnt;++i) ans+=mp[sy[i]];
	cout<<cnt;
	return 0;
}
