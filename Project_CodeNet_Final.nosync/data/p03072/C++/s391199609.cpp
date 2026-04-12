#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main() {
	int N;cin>>N;
	int h = -1;
	int ans = 0;
	for (int i = 0; i < N; i++)
	{
		int a;cin>>a;
		if (a >= h)
		{
			ans++;
			h = a;
		}
	}

	cout<<ans<<endl;
;
	return 0;
}