#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 3123;

int n;
long long int values[MAXN];
long long int pd[MAXN][MAXN];
bool stat[MAXN][MAXN];

long long int rec(int l, int r)
{
	if(l==r)
		return values[l];

	if(stat[l][r])
		return pd[l][r];

	stat[l][r] = true;
	return pd[l][r] = max(values[l] - rec(l+1,r), values[r] - rec(l,r-1));
}

int main()
{
	cin >> n;
	for(int i=0;i<n;i++)
		cin >> values[i];

	cout << rec(0, n-1) << endl;

	return 0;
}