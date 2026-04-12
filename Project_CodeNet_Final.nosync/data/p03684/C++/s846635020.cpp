#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
	vector<pair<int,int> > a;
	vector<pair<int,int> > b;
	vector<pair<int, pair<int, int> > > c;
	int p[100001];
	int k;
	int n, m;
	int s, t;
	int y, z;
	long long ans;
	int h1, h2;
int par(int x,int v){
	if (p[x] == x)return x;
	else{
		if (v == 0)h1++;
		else h2++;
		 p[x] = par(p[x],v);
		 return p[x];
	}
}
int main(void){


	int x;
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		scanf("%d %d", &x, &y);
		a.push_back(make_pair(x, i));
		b.push_back(make_pair(y, i));
	}
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	for (int i = 1; i < n; i++){
		c.push_back(make_pair(a[i].first - a[i - 1].first, make_pair(a[i - 1].second, a[i].second)));
		c.push_back(make_pair(b[i].first - b[i - 1].first, make_pair(b[i - 1].second, b[i].second)));
	}
	sort(c.begin(), c.end());
	for (int i = 0; i < n; i++)p[i] = i;
	x = 0;
	ans = 0;
	for (int i=0; x < n - 1;i++){
		h1 = 0;
		h2 = 0;
		y = par(c[i].second.first,0);
		z = par(c[i].second.second,1);
		if (y != z){
			if(h1<h2)p[y] = z;
			else p[z] = y;
			ans = ans + c[i].first;
			x++;
		}
	}


	printf("%lld\n", ans);

	return 0;
}
