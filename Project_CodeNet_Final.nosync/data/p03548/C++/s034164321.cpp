#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <list>
#include <map>
#include <set>
#define long long ll
using namespace std;

int main()
{
	int x,y,z;
	while(cin>>x>>y>>z)
	{
		int k=(x-z)/(y+z);
		cout<<k<<endl;
	}
} 