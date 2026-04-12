#include <iostream>
#include <cstdio>
#include <string>
#include <sstream>
#include <algorithm>
#include <math.h>
#include <map>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>

#define PI 3.14159265359

#define INF 99999999;

#define rep(i, n) for(int i=0; i<n; i++)
#define REP(n) rep(i, n)

typedef long long ll;

using namespace std;



/*
class LightSwitchingPuzzle
{
public:
	int minFlips(string s)
	{

	}
}
*/


int main()
{
	int n, m, t, time;
	vector<int> vi;
	
	while (cin >> n >> m)
	{
		if (n == 0 && m == 0) break;
		
		vi.clear();
		time = 0;
		
		vi.push_back(0);
		REP(n)
		{
			cin >> t;
			vi.push_back(t);
		}
		REP(m)
		{
			cin >> t;
			vi.push_back(t);
		}
		
		sort(vi.begin(), vi.end());
		
		for (int i=0; i<vi.size()-1; i++)
		{
			time = max(time, vi[i+1] - vi[i]);
		}
		
		cout << time << endl;
		
		/*
		//テスト出力
		REP(vi.size())
		{
			cout << vi[i] << " ";
		}
		*/
	}
	
	return 0;
}