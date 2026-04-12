#include "bits/stdc++.h"
using namespace std;
#define rep(i,n)for(int i=0;i<(int)(n);i++)
#define PI 3.141592653589793
//vector < vector<int>>a(0, vector<int>(0));二次元配列宣言


int main()
{
	int n;
	cin >> n;
	//n = 200000;
	vector<long long int>a(n);
	vector<long long int>b(n+1);
	long long int ans=0;
	int i,j;
	b.at(0) = 0;
	for (i = 0; i < n; i++)
	{
		cin >> a.at(i);

		//a.at(i) = 1000000000;
		b.at(i+1) +=  b.at(i)+a.at(i);
	}
	for (i = 1; i < n; i++)
	{
		ans += a.at(i) * (b.at(i) % 1000000007);
		ans = ans % 1000000007;
		//cout << ans << endl;
	}
	cout << ans << endl;

	
}