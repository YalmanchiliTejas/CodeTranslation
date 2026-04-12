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



using namespace std;



int main()
{
	int n, s, sum;
	
	while (cin >> n)
	{
		if (n == 0) break;
		
		vector<int> vi;
		for (int i=0; i<n; i++)
		{
			cin >> s;
			vi.push_back(s);
		}
		
		sort(vi.begin(), vi.end());
		
		/*
		//テスト出力
		for (int i=0; i<vi.size(); i++)
		{
			cout << vi[i] << endl;
		}
		*/
		
		sum = 0;
		for (int i=1; i<vi.size()-1; i++)
		{
			sum += vi[i];
		}
		
		cout << sum / (vi.size() - 2) << endl;
	}
	
	return 0;
}