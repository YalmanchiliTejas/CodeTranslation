#include<iostream>
#include<math.h>
#include<vector>
#include<algorithm>
#include<stdio.h>


using namespace std;
int main(void)
{
	int h, w;
	cin >> h >> w;
	vector<vector<char> > v(h+1, vector<char>(w+1));
	int i, j,num;
	vector<int> n(h, 0);
	vector<int> m(w, 0);
	for (i = 0; i < h; i++)
	{
		for (j =0 ; j < w; j++)
		{
			cin >> v[i][j];
		}
	}
	for (i = 0; i < h; i++)
	{
		 num = 0;
		for (j = 0; j < w; j++)
		{
			if (v[i][j] == '.')
			{
				num++;
			}
			if (num == w)
			{
				n[i] = 1;
			}
		}
	}

	for (j = 0; j < w; j++)
	{
	    num = 0;
		for (i = 0; i < h; i++)
		{
			if (v[i][j] == '.')
			{
				num++;
			}
			if (num == h)
			{
				m[j] = 1;
			}
		}
	}

	for (i = 0; i < h; i++)
	{
		for (j = 0; j < w; j++)
		{
			if (n[i] == 1)
			{
				while(n[i]==1)
				i++;
			}
			if (m[j])
			{
				while(m[j]==1)
				j++;
			}
			if (i == h || j == w)
			{
				continue;
			}
			cout << v[i][j];
		}
		cout << endl;
	}
	return 0;
}