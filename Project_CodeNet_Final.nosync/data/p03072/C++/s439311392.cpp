#include <bits/stdc++.h>
#define For(i,a,b) for(int i=a;i<=b;i++)
#define F first
#define S second
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
using namespace std;
using ll=long long;
using pii=pair<int,int>;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n; cin>>n;
	int cnt=1;
	int mx; cin>>mx;
	int t;
	For(i,1,n-1)
	{
		cin>>t;
		if(t>=mx) cnt++;
		mx=max(mx,t);
	}
	cout<<cnt<<"\n";
	return 0;
}