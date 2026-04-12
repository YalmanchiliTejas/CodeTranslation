#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
#include <algorithm>
#include <utility>
using namespace std;
typedef long long ll;

const int maxn = 200010;
const ll INF = 1000000000000000010LL;

int x[maxn], y[maxn];
int colorx[maxn], colory[maxn]; //0 : Red 1:Blue
int n;
ll ans = INF;
vector<int> minv, maxv;
multiset<int> s;
vector<int> red,blue;
vector<pair<int,int> > color;

void solve1()
{
	memset(colorx,-1,sizeof(colorx)); memset(colory,-1,sizeof(colory));
	colorx[minv[0]] = 0;
	colory[maxv[0]] = 1;
	for (int i=1;i<=n;i++)
	{
		if (colorx[i] != -1) colory[i] = 1-colorx[i];
		else if (colory[i] != -1) colorx[i] = 1-colory[i];
		else {colorx[i] = 0; colory[i] = 1;}
	}
	for (int i=1;i<=n;i++)
	{
		if (colorx[i]==0) red.push_back(x[i]);
		else blue.push_back(x[i]);
		if (colory[i]==0) red.push_back(y[i]);
		else blue.push_back(y[i]);
	}
	sort(red.begin(), red.end()); sort(blue.begin(), blue.end());
	ans = min(ans, ((ll)red[red.size()-1] - (ll)red[0]) * ((ll)blue[blue.size()-1] - (ll)blue[0]));
}

void solve2()
{
	memset(colorx,-1,sizeof(colorx)); memset(colory,-1,sizeof(colory));
	if (maxv.size() == 1)
	{
		if (minv.size() == 1) colorx[minv[0]] = 0;
		else colorx[minv[1]] = 0;
		colory[maxv[0]] = 0;
	}
	else
	{
		colorx[minv[0]] = 0;
		colory[maxv[1]] = 0;
	}
	for (int i=1;i<=n;i++)
	{
		if (colorx[i] == -1) color.push_back(make_pair(x[i],i));
		if (colory[i] == -1) color.push_back(make_pair(y[i],i));
	}
	sort(color.begin(), color.end());
	int pi = 0, pj = -1;
	int cnt = 0;
	for (;pi<color.size();pi++)
	{
		while (pj + 1 < color.size() && cnt != n)
		{
			pj++;
			if (s.count(color[pj].second) == 0) cnt++;
			s.insert(color[pj].second);
		}
		//cout<<y[maxv[0]] - x[minv[0]]<<" "<<(ll)color[pj].first - (ll)color[pi].first<<endl;
		if (cnt == n) ans = min(ans, ((ll)y[maxv[0]] - (ll)x[minv[0]]) * ((ll)color[pj].first - (ll)color[pi].first));
		multiset<int>::iterator iter = s.find(color[pi].second);
		s.erase(iter);
		if (s.count(color[pi].second) == 0) cnt--;
	}
}

int main()
{
	//freopen("E.in","r",stdin);
	scanf("%d",&n);
	ll maxval = 0LL, minval = INF;
	for (int i=1;i<=n;i++) 
	{
		scanf("%d%d",&x[i], &y[i]);
		if (x[i] > y[i]) swap(x[i], y[i]);
		maxval = max(maxval, (ll)y[i]);
		minval = min(minval, (ll)x[i]);
	}
	
	ans = INF;
	for (int i=1;i<=n;i++)
	{
		if (x[i] == minval) minv.push_back(i);
		if (y[i] == maxval) maxv.push_back(i);
	}
	solve1();
	if (!(minv.size() == 1 && maxv.size() == 1 && minv[0] == maxv[0])) solve2();
	
	printf("%lld\n",ans);
	return 0;
}
