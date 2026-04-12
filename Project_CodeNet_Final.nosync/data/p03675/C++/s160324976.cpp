
#include <string>
#include <vector>
#include <cmath>
#include <list>
#include <set>
#include <algorithm>
#include <map>
#include <iostream>
#include <sstream>
#include <queue>
#include <iomanip>

#include <string.h>

typedef unsigned long long u64; 
typedef unsigned int uint;

using namespace std;

#define MIN(a, b) a < b ? a : b

int main()
{
	int n;
	list<int> answer;

	cin >> n;
	bool isRight = false;

	for(int i = 0; i < n; i++)
	{
		int m;
		cin >> m;
		if(isRight)
		{
			answer.push_back(m);
		}
		else
		{
			answer.push_front(m);
		}
		isRight = !isRight;
	}

	if( isRight)
	{
		for(auto it = answer.begin(); it != answer.end(); it++)
		{
			cout << *it << " ";
		}
	}
	else
	{
		for(auto it = answer.rbegin(); it != answer.rend(); it++)
		{
			cout << *it << " ";
		}
	}
	
	cout << endl;
}