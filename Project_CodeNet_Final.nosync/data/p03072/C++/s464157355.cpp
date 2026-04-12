/*author: hyperion_1724
  date: 
*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin>>N;
	int ans=0;
	int p=0;
	for (int i = 0; i < N; ++i)
	{
		int h;
		cin>>h;
		if(h>=p)
		{
			ans++;
			p=h;
		}
	}
	cout<<ans<<endl;

	return 0;
}