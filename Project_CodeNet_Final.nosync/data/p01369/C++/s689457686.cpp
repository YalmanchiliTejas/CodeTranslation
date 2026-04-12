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

#define PI 3.14159265359

#define INF 1000000;

#define rep(i,n) for(int i=0;i<n;i++)
#define REP(n) rep(i,n)

using namespace std;


/*
class ElectronicPetEasy
{
public:
	string isDifficult(int st1, int p1, int t1, int st2, int p2, int t2)
	{
		
	}
};
*/


bool isRight(char c)
{
	string rightChars = "yuiophjklnm";
	
	if (rightChars.find(c) != string::npos)
	{
		return true;
	} else {
		return false;
	}
}


int main()
{
	string inp;
	
	while (cin >> inp, inp != "#")
	{
		bool flag = isRight(inp[0]);
		int ans = 0;
		
		for (int i=1; i<inp.length(); i++)
		{
			if (flag != isRight(inp[i]))
			{
				ans++;
				flag = !flag;
			}
		}
		
		cout << ans << endl;
	}
	
	return 0;
}