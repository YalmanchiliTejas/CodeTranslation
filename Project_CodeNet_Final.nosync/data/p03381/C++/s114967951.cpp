#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define LINF 1000000000LL * 1000000
#define MAXN 45002
using namespace std;
 
int n;
int a[200000];
int b[200000];
int main()
{
	ios_base::sync_with_stdio(0);
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
		b[i] = a[i];
	}
	sort(b , b + n);
	for(int i = 0;i < n; i++)
		if(a[i] <= b[n / 2 - 1])
		{
			cout << b[n / 2] << endl;
		}
		else
			cout << b[n / 2 - 1] << endl;
}