#include <bits/stdc++.h>
using namespace std;

int main()
{
	#ifdef ARTHUR_LOCAL
		ifstream cin("input.txt");
	#endif

	int n;
	cin>>n;

	vector<int> A;

	for(int i=0; i<n; i++)
	{
		int a;
		cin>>a;
		A.push_back(a);
	}

	vector<int> ends = {-A[0]};

	for(int i=1; i<n; i++)
	{
		int k = (upper_bound(ends.begin(),ends.end(),-A[i])-ends.begin());
		if(k==ends.size()) ends.push_back(-A[i]);
		else ends[k]=-A[i];
	}

	cout << ends.size() << "\n";
}