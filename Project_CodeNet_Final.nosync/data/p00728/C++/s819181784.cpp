#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int N, d[1000];
	while(cin >> N, N)
	{
		for(int i=0; i<N; i++)
			cin >> d[i];

		sort(d,d+N);
		int ret=0;
		for(int i=1; i<N-1; i++)
			ret+=d[i];

		cout << ret/(N-2) << endl;
	}
}