#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
typedef long long LL;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	deque<int> a;
	int n; cin >> n;
	for(int i = 0; i < n; i++)
	{
		int x; cin >> x;
		if(i&1)
			a.push_front(x);
		else
			a.push_back(x);
	}
	if(n&1)
		reverse(a.begin(),a.end());
	for(int i = 0; i < n; i++)
		cout<<a[i]<<" ";
	cout<<endl;

	cout<<flush;
	return 0;
}