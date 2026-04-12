#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
	int N,M;
	while(cin>>N>>M, N|M)
	{
		int t;
		set<int> s;
		for (int i = 0; i < N + M; i++)
		{
			cin>>t;
			s.insert(t);
		}

		int past = 0, m = 0;
		for (set<int>::iterator it = s.begin(); it != s.end(); ++it)
		{
			m = max(m, *it - past);
			past = *it;
		}
		cout << m << endl;
	}
	return 0;
}