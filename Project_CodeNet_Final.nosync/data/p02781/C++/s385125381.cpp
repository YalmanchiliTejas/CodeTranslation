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
string s;
int n;
ll d[110][5][2];
ll res;
int main()
{
	cin >>s>>n;
	for (int i=1;i<s.size();i++)
	{
		ll r=1;
		for (int j=0;j<n-1;j++) r*=i-1-j;
		for (int j=0;j<n-1;j++) r/=j+1;
		for (int j=0;j<n;j++) r*=9;
		res+=r;
		//cout <<i<<" "<<r<<" ##\n";
	}
	d[0][1][1]=s[0]-'0'-1;
	d[0][1][0]=1;
	for (int i=1;i<s.size();i++)
	{
		for (int j=1;j<=n;j++)
		{
			d[i][j][0]=d[i-1][j-(s[i]!='0')][0];
			d[i][j][1]=d[i-1][j][1]+d[i-1][j-1][1]*9;
			d[i][j][1]+=d[i-1][j-1][0]*max(0,s[i]-'0'-1);
			if (s[i]!='0') d[i][j][1]+=d[i-1][j][0];
			//cout <<i<<" "<<j<<" "<<d[i][j][0]<<" "<<d[i][j][1]<<" ##\n"; 
		}
	}
	cout <<d[s.size()-1][n][0]+d[s.size()-1][n][1]+res;
	return 0;
}