#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cassert>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <iostream>
#include <map>
#include <set>
#include <cassert>
#include <string.h>

using namespace std;

int main()
{
	vector <int > v;
	int n;
	int a;
	cin >> n;
	for (int i = 0; i<n; i++) 
	{
		cin >> a;
		v.push_back(a);
	}
		
	int c = 0;
	
	
	for (int i = n-1; i>=0; i--)
	{
		int flag = 0; 
		int cur = v[i];
		for (int j = i-1; j>=0; j--)
		{
			if (v[i]<v[j]){
				flag = 1;
				break;
			}
			else {
				continue;
				
			}
		}
		
		if (flag == 0) c++;
	}
	
	cout << c <<endl;
	
	
	
	
	
	
	
	
	return 0;
}

