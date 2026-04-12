#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <queue>
#include <utility>
#include <vector>
#include <set>
#include <memory.h>
#include <iomanip>
#include <bitset>
#include <list>
#include <stack>
#include <deque>

using namespace std;

#define mod 1000000007

int main()
{
	int n;
	cin >> n;
	long long int maxofall = 0, minofall = mod;
	int maxindex = 0, minindex = 0;
	vector<pair<long long int, long long int> > v;
	for(int i = 0; i < n; i++){
		long long int x, y;
		cin >> x >> y;
		if(x > y) swap(x, y);
		v.push_back(make_pair(x, y));
	}
	sort(v.begin(), v.end());
	for(int i = 0; i < n; i++){
		long long int x = v[i].first;
		long long int y = v[i].second;
		if(y > maxofall){
			maxindex = i;
			maxofall = y;
		}
		if(x < minofall){
			minindex = i;
			minofall = x;
		}
	}
	long long int amax = maxofall, amin = v[minindex].second;
	long long int bmax = v[maxindex].first, bmin = minofall;
	for(int i = 0; i < n; i++){
		long long int x = v[i].first;
		long long int y = v[i].second;
		if(i == maxindex || i == minindex) continue;
		amin = min(amin, y);
		bmax = max(bmax, x);
	}
	long long int ans = (amax - amin) * (bmax - bmin);
	if(maxindex == minindex){
		cout << ans << endl;
		return 0;
	}
	amax = maxofall;
	amin = minofall;
	bmax = max(v[n - 1].first, v[0].second);
	bmin = min(v[1].first, v[0].second);
	long long int miny = v[0].second;
	long long int maxy = v[0].second;
	ans = min(ans, (amax - amin) * (bmax - bmin));
	for(int i = 1; i < n; i++){
		long long int x = v[i].first;
		long long int y = v[i].second;
		miny = min(miny, y);
		maxy = max(maxy, y);
		if(i == n - 1) ans = min(ans, (amax - amin) * (max(bmax , maxy) - miny));
		else ans = min(ans, (amax - amin) * (max(bmax, maxy) - min(v[i + 1].first, miny)));
	}
	cout << ans << endl;
	return 0;
}