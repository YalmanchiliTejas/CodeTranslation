#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <string>
#include <utility>
#include <cmath>
#include <iomanip>

using namespace std;

#define REP(i,n) for(int (i)=(0);(i)<(n);++i)
#define ll long long
#define PB push_back
#define INF 1000000000

int main()
{
	int x;
	cin >> x;

	if(x==3 || x==5 || x==7)cout << "YES" << endl;
	else cout << "NO" << endl;

	return 0;
}