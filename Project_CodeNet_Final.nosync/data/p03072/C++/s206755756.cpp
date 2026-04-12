#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <list>
#include <string>
#include <numeric>
#include <math.h>
#include <set>
#include <map>
#include <fstream>
#include <complex>
using namespace std;

int main()
{
	int N;
	cin>>N;
	vector<int> H(N);
	for(int i=0; i<N; i++)
	{
		cin>>H[i];
	}
	int sum = 1;
	int max = H[0];
	for(int i=1; i<N; i++)
	{
		if(max<=H[i])
		{
			sum++;
			max = H[i];
		}
	}
	cout<<sum<<endl;
	return 0;
}