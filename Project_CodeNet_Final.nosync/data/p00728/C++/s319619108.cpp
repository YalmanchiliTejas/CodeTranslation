#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int n,inp,sum;

	while(cin>>n,n!=0)
	{
		vector<int> score;
		for(int i=0;i<n;i++)
		{
			cin>>inp;
			score.push_back(inp);
		}

		sort(score.begin(),score.end());

		sum=0;
		for(int i=1;i<n-1;i++)
			sum+=score[i];

		cout<<sum/(n-2)<<endl;
	}
}