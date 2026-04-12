#include "bits/stdc++.h"
using namespace std;
#define rep(i,n)for(int i=0;i<(int)(n);i++)

int main()
{
	int h, w;
	cin >> h >> w;

	int i, j;

	vector<vector<char>>a(h, vector<char>(w));

	for (i = 0; i < h; i++)
	{
		for (j = 0; j < w; j++)
		{
			cin >> a.at(i).at(j);
		}
	}
	vector<bool>r(h, false);
	vector<bool>c(w, false);

	for (i = 0; i < h ; i++)
	{
		for (j = 0; j < w; j++)
		{
			if (a.at(i).at(j) == '#')
			{
				r.at(i) = true;
				c.at(j) = true;
			}
		}
	}
	for (i = 0; i < h; i++)
	{
		if (r.at(i))
		{
			for (j = 0; j < w; j++)
			{
				if (c.at(j))
				{
					cout << a.at(i).at(j);
				}
			}
			cout << endl;
		}
	}

}



/**/
/*#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.141592653589793

int main(void) {
	return 0;
}
*/