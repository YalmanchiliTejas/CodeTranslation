#include <bits/stdc++.h>
using namespace std;
int b, n[3005];
long long r[3005][3005];
int main()
{
    cin >> b;
    for(int i = 0; i < b; i++)
    {
    	cin >> n[i];
	}
	for(int i = 0; i < b; i++)
	{
		r[i][i] = n[i];
	}
	for(int i = 1; i < b; i++)
	{
		int l = 0;
		for(int d = i; d < b; d++)
		{
			r[l][d] = max(n[l] - r[l+1][d], n[d] - r[l][d-1]);
			l++;
		}
	}
	cout << r[0][b-1] << endl;
}

