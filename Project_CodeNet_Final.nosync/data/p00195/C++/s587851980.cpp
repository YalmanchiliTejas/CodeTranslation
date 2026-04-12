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
	int s[5][3];
	char shop[5] = {'A', 'B', 'C', 'D', 'E'};
	
	while (cin >> s[0][0] >> s[0][1])
	{
		if (s[0][0] == 0 && s[0][1] == 0) break;
		
		for (int i=1; i<5; i++)
		{
			cin >> s[i][0] >> s[i][1];
		}
		
		REP(5)
		{
			s[i][2] = s[i][0] + s[i][1];
		}
		
		int index = 0;
		int max = s[0][2];
		
		for (int i=1; i<5; i++)
		{
			if (max < s[i][2])
			{
				max = s[i][2];
				index = i;
			}
		}
		
		cout << shop[index] << " " << max << endl;
		
		/*
		//テスト出力
		REP(5)
		{
			cout << s[i][2] << " ";
		}
		cout << endl;
		*/
	}
	
	return 0;
}