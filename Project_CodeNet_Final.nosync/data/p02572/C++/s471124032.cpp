#include <bits/stdc++.h>
#define ll long long
#define M 1000000007 
#define MM 998244353
#define PI 3.14159265 
using namespace std;
 
int main()
{
	long long int n, sum = 0, prosum = 0;
	cin >> n;
	long long int a[n];

	for (long long int i = 0; i < n; i++)
	{
		cin >> a[i];
		sum = sum + a[i];
	}

	for (long long int i = 0; i < n; i++)
	{
		sum = sum - a[i];
		prosum+=(sum%M * a[i]%M)%M;
	}

	prosum = prosum%M;

	cout << prosum;

  	return 0;
}