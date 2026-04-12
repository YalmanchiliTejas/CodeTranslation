#include<iostream>
#include<algorithm>
using lint=int64_t;
using namespace std;

int main()
{
	int N;
	int H[100]={};

	cin >> N;
	for(int i=0;i<N;i++)
		cin >> H[i];
	
	int ans=0;
	int Max=H[0];
	for(int i=0;i<N;i++)
	{
		if(H[i]>=Max)
			ans++;

		Max=max(Max,H[i]);
	}

	cout << ans << endl;
	return 0;
}
