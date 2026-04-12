#include<bits/stdc++.h>
#define lli long long int
#define pb push_back
#define FORA(i,s,e) for(int i = s; i < e; i++)
#define FORB(i,s,e) for(int i = s; i <= e; i++)

using namespace std;


int main(void)
{
	lli n;
	cin >> n;
	vector<lli> a(n);
	for (int i = 0; i < n; i++)cin >> a[i];
	lli sum = 0;
	vector <lli> ans(n);
	for(int i = 0; i < n; i++)
	{ 
		ans[n - 1 - i] = sum;
		sum = (sum + a[n - 1 - i])%1000000007;
	}

	lli fin = 0;
	for (int i = 0; i < n; i++)
	{
		fin += (a[i] * ans[i]) % 1000000007;
	}

	cout << fin % 1000000007 << endl;
	return 0;
}