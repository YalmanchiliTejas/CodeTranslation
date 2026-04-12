#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<iomanip>
#include<set>

using namespace std;

int main()
{
	long long n,k;
	cin >> n >> k;

	long long ans=0;
	for(int b=k+1;b<=n;b++)
	{
		ans+=n/b*(b-k)+(0<n%b-k+1 ? n%b-k+1 : 0)-(k==0 ? 1:0);
	}
	
	cout << ans << endl;




}