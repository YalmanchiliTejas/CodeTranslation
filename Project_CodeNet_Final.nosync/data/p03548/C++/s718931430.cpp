#include<iostream>
using namespace std;
long long X,Y,Z,ans;
int main()
{
	cin>>X>>Y>>Z;
	X-=Z;
	while(X>=Y+Z) X-=Y+Z,ans++;
	cout<<ans<<endl;
	return 0;
}