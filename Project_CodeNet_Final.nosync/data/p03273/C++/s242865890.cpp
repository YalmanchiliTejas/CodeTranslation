#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define in insert
#define mp make_pair
using namespace std;
const int N = 200;
char a[N][N];
int n,m,k;
string s;
set<int>setik;

vector<char>v;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> m;
	for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) cin >> a[i][j];

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			int c = 0;
			int c1 = 0;
			if(a[i][j] == '.')
			{
				for(int k = j; k < m; k++)
				{
					if(a[i][k] == '.')c++;
				}
			}
			//cout << c << ' ' ;
			if(c == m)
			{
				for(int k = j; k < m; k++)
				{
					a[i][k] = '-';
					//if(a[i][k] == '.')c++;
				}	
			}
		}
	}

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			int c1 = 0;
			if(a[i][j] == '.' || a[i][j] == '-')
			{
				for(int k = i; k < n; k++)
				{
					if(a[k][j] == '.' || a[k][j] == '-')c1++;
				}
			}

				if(c1 == n)
					{
						for(int k = i; k < n; k++)
					{
						a[k][j] = '-';
					//if(a[i][k] == '.')c++;
					}	
			}
		}
	}
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			if(a[i][j] != '-')cout << a[i][j];
		}
		cout << endl;
	}
	
}
