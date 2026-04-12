#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	vector<ll> a(n+1);
	for(int i=1; i<=n; i++)
		cin >> a[i];

	ll dpX[n+1][n+1], dpY[n+1][n+1];

	for(int i=1; i<=n; i++){
		dpX[i][i] = a[i];
		dpY[i][i] = -a[i];
	}

	for(int l=2; l<=n; l++)
		for(int i=1; i<=n-l+1; i++){
			int j = i+l-1;
			dpX[i][j] = max(dpY[i][j-1]+a[j], dpY[i+1][j]+a[i]);
			dpY[i][j] = min(dpX[i][j-1]-a[j], dpX[i+1][j]-a[i]);
		}

	cout << dpX[1][n] << endl;

	return 0;
}