#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;

typedef pair<long long int, long long int> P;

P p[200000];

int main() {
	
	int N;
	cin >> N;
	
	long long int xmin = 100000000000LL;
	long long int ymin = 100000000000LL;
	long long int xmax = 0;
	long long int ymax = 0;
	
	for(int i = 0; i < N; i++){
		cin >> p[i].first >> p[i].second;
		if(p[i].first > p[i].second){
			swap(p[i].first, p[i].second);
		}
		xmax = max(xmax, p[i].first);
		ymax = max(ymax, p[i].second);
		xmin = min(xmin, p[i].first);
		ymin = min(ymin, p[i].second);
	}
	
	long long int ans = (ymax - ymin) * (xmax - xmin);
	
	sort(p, p + N);
	long long int diff = ymax - xmin;
	
	long long int pmin = p[0].first;
	long long int dmin = 10000000000LL;
	long long int pmax = 0;
	
	for(int i = 0; i < N; i++){
		pmax = max(pmax, p[i].first);
	}
	
	ans = min(ans, diff * (pmax - pmin));
	
	for(int i = 0; i < N - 1; i++){
		dmin = min(dmin, p[i].second);
		pmin = min(p[i + 1].first, dmin);
		pmax = max(pmax, p[i].second);
		ans = min(ans, diff * (pmax - pmin));
	}
	dmin = min(dmin, p[N - 1].second);
	pmin = dmin;
	pmax = max(pmax, p[N - 1].second);
	ans = min(ans, diff * (pmax - pmin));
	
	cout << ans << endl;
	
	return 0;
}

