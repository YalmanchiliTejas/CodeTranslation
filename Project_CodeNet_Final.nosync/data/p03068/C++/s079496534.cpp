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

const int inf = 2000000;
int main()
{
	int N,K;
	string S;
	cin>>N>>S>>K;

	char c = S[K-1];
	for(int i=0; i<S.size(); i++)
	{
		if(S[i] != c)
		{
			S[i] = '*';
		}
	}
	cout<<S<<endl;
	return 0;
}