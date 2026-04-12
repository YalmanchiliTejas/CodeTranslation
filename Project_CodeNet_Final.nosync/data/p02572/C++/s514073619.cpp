#include <bits/stdc++.h>
using namespace std;

const int64_t mod=1000000000+7;

int main()
{
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i=0;i<n;++i)
	{
		cin >> a[i];
	}

	int64_t sum=0;
	int64_t right=0;
	for (int i=n-2;i>=0;--i)
	{
		right+=a[i+1];
		right%=mod;
		sum+=a[i]*right;
		sum%=mod;
	}
	cout << sum << endl;
}



