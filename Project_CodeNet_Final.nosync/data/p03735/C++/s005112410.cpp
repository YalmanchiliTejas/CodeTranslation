#include<iostream>
#include<algorithm>
#include<set>
#define x first
#define y second
using namespace std;
typedef long long LL;
const int N = 2e5;
pair<LL,LL> a[N];
LL AABB(set<pair<LL,int>>& xs, set<pair<LL,int>>& ys)
{
	return ((*(--xs.end())).first-(*xs.begin()).first)*((*(--ys.end())).first-(*ys.begin()).first);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n; cin >> n;
	set<pair<LL,int>> xs, ys;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i].x >> a[i].y;
		if(!(a[i].x >= a[i].y))
			swap(a[i].x,a[i].y);
	}
	sort(a,a+n);
	for(int i = 0; i < n; i++)
	{
		xs.insert({a[i].x,i});
		ys.insert({a[i].y,i});
	}
	
	LL ans = AABB(xs,ys);
	for(int i = n-1; i >= 0; i--)
	{
		xs.erase({a[i].x,i});
		ys.erase({a[i].y,i});
		xs.insert({a[i].y,i});
		ys.insert({a[i].x,i});
		ans = min(ans,AABB(xs,ys));
	}
	cout<<ans<<endl;

	cout<<flush;
	return 0;
}