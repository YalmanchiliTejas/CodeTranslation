#include<iostream>
#include <cassert>
#include <algorithm>
#include <functional>
using namespace std;

int main()
{
	int N,a=0,i,count=0,j,max=0;
	int H[100];
	cin >> N;
	for( i = 0; i < N; i++ )
	{
		cin >> H[i];
	}

	for( i = 0; i < N; i++ )
	{
		count = 0;
		for( j = 0; j < i; j++ )
		{
			if( H[i] >= H[j] )
			{
				count++;
			}
		}
		if( count == i )
		{
			max++;
		}
	}

	cout << max <<endl;

	return 0;
}
