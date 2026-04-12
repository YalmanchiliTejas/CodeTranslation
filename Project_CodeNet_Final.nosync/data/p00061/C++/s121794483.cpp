#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <sstream>
#include <cmath>
#include <climits>
#include <set>
#include <iostream>
#include <map>
#include <functional>

using namespace std;

#define reep(i,f,n) for(int i=f; i<int(n); ++i)
#define rep(i,n) reep(i,0,n)

typedef vector<int> vi;
typedef pair<int, int> pii;

int main()
{
	vector<pii> result;
	int n, acc;
	while(scanf("%d,%d", &n, &acc), n|acc)
		result.push_back(pii(acc, n));
	sort(result.rbegin(), result.rend());

	map<int, int> rank;
	rep(i, result.size()){
		if(!i) rank[result[i].second] = 1;
		else rank[result[i].second] = rank[result[i-1].second] + (result[i-1].first != result[i].first);
	}
	
	while(scanf("%d", &n) != EOF){
		printf("%d\n", rank[n]);
	}

	return 0;
}