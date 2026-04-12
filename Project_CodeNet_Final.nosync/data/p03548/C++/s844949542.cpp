#include<iostream>
using namespace std;
#include<string>
#include<strstream>
#include<sstream>
#include<algorithm>
#include<math.h>
#include<iomanip>
#include<set>
long long mod = 10e18;
long long is(int n)
{
	if (n == 0)
		return 2;
	if (n == 1)
		return 1;
	return (is(n - 1) + is(n - 2));
}
int main()
{
	int n, z, v;
	cin >> n >> z >> v;
	n -= v;
   //if(n%(z+v)==0)
	cout << n / (z + v);
 
	
}