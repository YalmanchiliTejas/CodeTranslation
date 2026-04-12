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
#include <cstdlib>
#include <numeric>
#include <queue>
#include <complex>
#include <sstream>
#include <stack>

using namespace std;

#define reep(i,f,n) for(int i=f; i<int(n); ++i)
#define rep(i,n) reep(i,0,n)

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef complex<double> Point;

struct Data
{
	int point;
	char name[32];
	
	bool operator> (const Data& d)const
	{
		return point > d.point;
	}
};

int main()
{
	int n;
	bool first = true;
	while(scanf("%d", &n), n){
		if(!first)
			puts("");
		else
			first = false;
		
		vector<Data> data(n);
		rep(i, n){
			int won, lose, tie;
			scanf("%s%d%d%d", data[i].name, &won, &lose, &tie);
			data[i].point = won*3 + tie;
		}
		stable_sort(data.begin(), data.end(), greater<Data>());
		rep(i, n)
			printf("%s,%d\n", data[i].name, data[i].point);
	}
	
	return 0;
}