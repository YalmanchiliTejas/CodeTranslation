//code by 27.
#include<stdio.h>
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<math.h>
#include<vector>
#include<queue>
#include<map>
#include<stack>
#include<fstream>
#include<stdlib.h>
#include<set>
#include<climits>
#include<cmath>
#include<memory.h> 
#include<sstream>
#include<time.h>
using namespace std;
const long long BIGER=1000000000000000;
const int BIG=1000000000;
int main()
{
	string st;
	cin>>st;
	for(int i=0;i<st.size()-1;i++)
	{
		if(st[i]=='A'&&st[i+1]=='C')
		{
			cout<<"Yes";
			return 0;
		}
	}
	cout<<"No";
	return 0;
}