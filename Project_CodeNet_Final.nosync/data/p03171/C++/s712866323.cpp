#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MP make_pair
#define PII pair<int, int>
#define PLL pair<ll, ll>
#define PLI pair<ll, int>
#define PIL pair<int, ll>
#define STR string
#define Fst first
#define Snd second
#define SHN 1e9
#define LSHN 1e18
using namespace std;
int n;
ll d[3010][3010];
ll a[3010];
ll sum=0;
int main()
{
	cin >>n;
	for (int i=0;i<n;i++) cin >>a[i],sum+=a[i];
	for (int len=1;len<=n;len++)
	{
		for (int i=0;i<n;i++)
		{
			int j=i+len-1;
			if (i==j) d[i][j]=a[i];
			else
				d[i][j]=max(min(d[i+1][j-1],d[i+2][j])+a[i],min(d[i+1][j-1],d[i][j-2])+a[j]);
		}
	}
	cout <<d[0][n-1]-(sum-d[0][n-1]);
	return 0;
}