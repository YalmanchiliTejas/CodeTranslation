#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>
typedef long long ll;
#define MAX(x, y)	(((x) > (y))? (x) : (y))
#define MIN(x, y)	(((x) < (y))? (x) : (y))
#define ABS(x)		(((x) < 0)? (-1*(x)) : (x))
#define REPI(x,y)	for (int i=(x);i<(y);i++)
#define REPJ(x,y)	for (int j=(x);j<(y);j++)
#define MEMCLR(X)	memset((X),0,sizeof((X)))

using namespace std;
typedef pair<int, int> Point;
typedef vector<vector<Point>> Graph;

int i,j,X,Y,Z,ans;

int main() {
	cin >> X >> Y >> Z;
	
	cout << ((X-Z)/(Y+Z));
	
	return 0;
}
