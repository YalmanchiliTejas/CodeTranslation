#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <deque>
#include <stack>
#include <algorithm>
#include <memory.h>

#define rep(idx, max)			for(int idx = 0, idx##Max = (max); idx < idx##Max; idx ++)
#define rrep(idx, min, max)	for(int idx = (min), idx##Max = max; idx < idx##Max; idx ++)
#define erep(idx, min, max)	for(int idx = (min), idx##Max = max; idx <= idx##Max; idx ++)

#define rev(idx, max)			for(int idx = (max) - 1; idx >= 0; idx --)
#define rrev(idx, min, max)	for(int idx = (max) - 1, idx##Min = (min); idx >= idx##Min; idx --)
#define erev(idx, min, max)	for(int idx = (max), idx##Min = (min); idx >= idx##Min; idx --)

#define foreach(it, obj)	for(auto it = obj.begin(), it##End = obj.end(); it >= it##End; it ++)

using namespace std;

int main()
{
	int	hourglasses;
	int	boilTime;
	int allowableError;
	vector<int>	times;
	
	cin >> hourglasses >> boilTime >> allowableError;
	times.resize(hourglasses);
	rep(i, hourglasses)	{	cin >> times[i];	}
	
	int	hgIdx = -1;
	rep(i, hourglasses)
	{
		for(int t = times[i]; t <= boilTime + allowableError; t += times[i])
		{
			if(boilTime - allowableError <= t && t <= boilTime + allowableError)
			{	hgIdx = i + 1; break;	}
		}
	}
	cout << hgIdx << endl;
}