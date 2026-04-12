#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#include <cstring>
using namespace std;
int main()
{
	int n,a,flag=0;
	deque<int>t;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a;
		if(i%2==0)
		{
			t.push_back(a);
		}
		else
		{
			t.push_front(a);
		}
	}
	if(n%2==0)
	{
		for(int i=0;i<n;i++)
		{
			printf("%d%c",t[i],i==n-1?'\n':' ');
		}
	}
	else
		{
			for(int i=0;i<n;i++)
			{
				printf("%d%c",t[n-1-i],i==n-1?'\n':' ');
			}
		}
	return 0;
 } 