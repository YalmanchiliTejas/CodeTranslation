#include <bits/stdc++.h>
using namespace std;

#define int 		long long
#define vi 			vector <int>
#define si 			set <int>
#define pii 		pair<int,int>
#define fr(n) 		for(__typeof(n) i=0;i<n;i++)
#define rep(i,a,b) 	for(__typeof(b) i=a;i<b;i++)
#define repi(i,b,a) for(__typeof(a) i=b;i>=a;i--)
#define tr(a) 		for(auto it=a.begin();it!=a.end();it++)
#define pb 			push_back
#define mp 			make_pair
#define F 			first
#define S 			second
#define FAST 		ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define time_passed	1.0 * clock() / CLOCKS_PER_SEC

void solve()
{
	int n;
	cin>>n;
	if(n>=30)
		cout<<"Yes";
	else
		cout<<"No";
}

signed main()
{
	FAST
	int test=1;
	//cin>>test;
	while(test--)
	{
		solve();
	}
	cerr<<endl<<"Time elapsed : "<<time_passed<<endl;
	return 0;
}