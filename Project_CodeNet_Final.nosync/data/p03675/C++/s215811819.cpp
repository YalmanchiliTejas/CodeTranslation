#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define mo 1000000007
#define MAX 1000004
#define fast_io ios::sync_with_stdio(false)

int main()
{
	fast_io;
	int n, x;
	cin >> n;
	deque<int> d;
	for(int i=1;i<=n;i++)
	{
		cin >> x;
		if(i%2 == n%2)
			d.push_front(x);
		else
			d.push_back(x);

	}
	while(!d.empty())
	{
		cout << d.front() << " ";
		d.pop_front();
	}
	return 0;
}