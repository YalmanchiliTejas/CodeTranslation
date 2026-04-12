#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int r,g,b;
	cin>>r>>g>>b;
	int ans = r*100+g*10+b;
	if (ans%4==0)
	{
		printf("YES");
	}
	else {
		printf("NO");
	}
	return 0;
}