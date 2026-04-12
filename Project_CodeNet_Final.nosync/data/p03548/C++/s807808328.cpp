#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <fstream>
#include <set>
#include <utility>
#include <algorithm>
#include <queue>
#include <stack>
#include <deque>
#include <numeric>
#include <sstream>
#include <list>
#include <map>
#include <stdlib.h>
#include <time.h>

#define rep(i,p,n) for(int i=(int)p;i<(int)n;i++)
#define repp(i,p,n) for(int i=(int)p;i>=(int)n;i--)
#define Sort(x) sort(x.begin(),x.end());
#define ll long long
#define INF 2000000000

using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	a -= c;
	cout << a / (b+c) << endl;
	return 0;
}

