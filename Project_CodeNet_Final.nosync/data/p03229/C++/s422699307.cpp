#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; ++i)
#define ALL(v) v.begin(), v.end()
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1000000007;

int main()
{
	ll n;
	cin >> n;
	deque<ll> a(n);
	rep(i,n)cin >> a[i];
	sort(ALL(a));
	deque<ll> b=a,c=a;
	
	//minから
	ll minans = 0;
	ll r=b.front(),l=b.front();
	b.pop_front();
	while(!b.empty())
	{
		minans+=abs(r-b.back());
		r=b.back();
		b.pop_back();
		if(b.empty())break;
		minans+=abs(l-b.back());
		l=b.back();
		b.pop_back();
		if(b.empty())break;
		minans+=abs(r-b.front());
		r = b.front();
		b.pop_front();
		if(b.empty())break;
		minans+=abs(l-b.front());
		l = b.front();
		b.pop_front();
		if(b.empty())break;
	}
	ll maxans = 0;
	r = c.back();
	l = c.back();
	c.pop_back();
	while(!c.empty())
	{
		maxans+=abs(r-c.front());
		r = c.front();
		c.pop_front();
		if(c.empty())break;
		maxans+=abs(l-c.front());
		l = c.front();
		c.pop_front();
		if(c.empty())break;
		maxans+=abs(r-c.back());
		r=c.back();
		c.pop_back();
		if(c.empty())break;
		maxans+=abs(l-c.back());
		l=c.back();
		c.pop_back();
		if(c.empty())break;
	}
	cout<<max(maxans,minans)<<endl;


	return 0;
}