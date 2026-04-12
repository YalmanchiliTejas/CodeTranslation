#include <bits/stdc++.h>
using namespace std;
const long long inf = -1e18;
const int o = (1<<18);
long long n[2*o], prop[2*o];
long long bio[200005];
vector <pair <long long, long long> > lg[200005];
void sp(int poz)
{
	n[poz*2] += prop[poz];
	prop[poz*2] += prop[poz];	
	n[poz*2+1] += prop[poz];
	prop[poz*2+1] += prop[poz];
	prop[poz] = 0;
}
void u(int l, int r, int p, int k, int poz, long long x)
{
    if(l > k || r < p)
    {
    	return;
	}
	if(l >= p && r <= k)
	{
		n[poz] += x;
		prop[poz] += x;
		return;
	}
	sp(poz);
	u(l, (l+r)/2, p, k, poz * 2, x);
	u((l+r)/2+1, r, p, k, poz * 2 + 1, x);
	n[poz] = max(n[poz*2], n[poz*2+1]);
}
long long g(int l, int r, int p, int k, int poz)
{
	if(l > k || r < p)
	{
		return inf;
	}
	if(l >= p && r <= k)
	{
		return n[poz];
	}
	sp(poz);
	return max(g(l, (l+r)/2, p, k, poz*2), g((l+r)/2+1, r, p, k, poz*2+1));
}
int main()
{
	for(int i = 0; i < 2*o; i++)
	{
		n[i] = 0;
		prop[i] = 0;
	}
	int b, q;
	cin >> b >> q;
	int p, k, d;
	long long maxb = 0;
	for(int i = 0; i < q; i++)
	{
		cin >> p >> k >> d;
		p--;
		k--;
		lg[k].push_back(make_pair(p, d));
		u(0, o-1, p, o-1, 1, -d);
	}
	for(int i = 0; i < b; i++)
	{
		bio[i] = -g(0, o-1, i, i, 1);
		bio[i] = max(bio[i], bio[i]+g(0, o-1, 0, i-1, 1));
		maxb = max(maxb, bio[i]);
		u(0, o-1, i, i, 1, bio[i]);
		if(!lg[i].empty())
		{
			for(int j = 0; j < lg[i].size(); j++)
			{
				u(0, o-1, lg[i][j].first, o-1, 1, lg[i][j].second);
			}
		}
		//cout << bio[i] << endl;
	}
	cout << maxb << endl;
	return 0;
}
