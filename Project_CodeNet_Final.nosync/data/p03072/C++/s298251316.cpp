#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<climits>
#include<iostream>
#include<sstream>
#include<utility>
#include<map>
#include<vector>
#include<queue>
#include<algorithm>
#include<set>
#include<stack>
using namespace std;
typedef long long ll;
typedef pair<int, int>P;



int main()
{
	int N,m=0,r=0;
	cin>>N;
	for(int i=0;i<N;i++)
	{
		int t;
		cin>>t;
		if(m<=t)
		{
			r++;
			m=t;
		}
	}
	cout<<r<<endl;
}
