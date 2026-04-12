#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <climits>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <numeric>
#include <iostream>

using namespace std;

#define FOR(i, a, b)   for(int i = (a); i < (b); ++i)
#define RFOR(i, a, b)  for(int i = (a); i > (b); --i)
#define rep(i, n)	   for(int i = 0; i < (n); ++i)
#define all(c)		   begin(c), end(c)
#define rall(c)		   rbegin(c), rend(c)
#define SZ(a)		   ((ll) a.size())

typedef long long		   ll;
typedef unsigned long long ull;


int main(){
	int x,y,z;
	scanf("%d %d %d",&x,&y,&z);
	int ans=(x-z)/(y+z);
	printf("%d",ans);
	return 0;
}
