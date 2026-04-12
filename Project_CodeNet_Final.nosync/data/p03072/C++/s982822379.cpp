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
	for(int i=0;i<N;i++)
	{
		bool ok=true;
		for(int j=0;j<i;j++)
		{
			if(H[j]>H[i])ok=false;
		}
		if(ok)
			ans++;
	}

	cout << ans << endl;
	return 0;
}

