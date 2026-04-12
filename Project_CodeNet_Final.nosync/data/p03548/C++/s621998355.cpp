#include<iostream>
#include<string>
using namespace std;
int main()
{
	int x,y,z,ans,l;
	cin >> x >> y >> z;

	l = x - z;

	ans = l / (z + y);

	printf("%d", ans);
	

	return 0;
}