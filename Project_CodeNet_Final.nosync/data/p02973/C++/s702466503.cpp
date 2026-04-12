#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int MAX_N = 100005;
ll A[MAX_N],used[MAX_N];

int main()
{
	int N;
	cin >> N;
	rep(i,N)
	{
		cin >> A[i];
	}
	deque<int> d;
	rep(i,N)
	{
		int p = lower_bound(d.begin(),d.end(),A[i]) - d.begin();
		if (p == 0)
		{
			d.push_front(A[i]);
		}
		else
		{
			d[p-1] = A[i];
		}
	}
	cout << d.size() << endl;
	return 0;
}