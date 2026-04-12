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
#include <sstream>
#include <iterator>
#include <complex>
using namespace std;
vector<int> color_max;

int main()
{
	int N;
	cin>>N;
	vector<int> A(N);

	for(int i=0; i<N; i++)
	{
		cin>>A[i];
	}
	
	
	for(int i=0; i<N; i++)
	{
		if(color_max.empty() || color_max[0]>=A[i])
		{
			color_max.insert(color_max.begin(),A[i]);
		}
		else
		{
			auto pos = lower_bound(color_max.begin(),color_max.end(),A[i]);
			//cout<<"distance:"<<distance(color_max.begin(),pos)<<endl;
			color_max[distance(color_max.begin(),pos) - 1] = A[i];
		}
		/*
		for(int i=0; i<color_max.size(); i++)
		{
			cout<<color_max[i]<<endl;
		}
		cout<<endl;
		*/
	}
	
	cout<<color_max.size()<<endl;
	return 0;
}