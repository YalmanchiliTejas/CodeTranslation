#include<string>
#include<sstream>
#include<stdio.h>
#include<iostream>
#include<iomanip>
#include<ios>
#include<algorithm>
#include<stack>
#include<queue>
#include<cmath>
#include<type_traits>
#include<random>
#include<vector>
#include<map>

using namespace std;

	

int main()
{
	int N;
	cin >> N;
	int H[N];
	for(int i=0;i<N;i++)
	{
		cin >> H[i];
	}
	int result = 1;
	for(int i=1;i<N;i++)
	{
		bool judge = 1;
		for(int j=0;j<i;j++)
		{
			if(H[i]<H[j])
			{
				judge = 0;
			}
		}
		if(judge==1)
		{
			result = result + 1;
		}
	}
	cout << result << endl;
	
}
