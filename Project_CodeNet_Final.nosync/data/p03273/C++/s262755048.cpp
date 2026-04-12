#include"iostream"
#include"string"
using namespace std;

int main()
{
	int h, w;
	cin >> h >> w;
	char a[110][110];
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			cin >> a[i][j];
		}
	}
	int check = 0;

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			if (a[i][j] == '#')check++;
		}
		if (check == 0)
		{
			for (int i1 = i ; i1 < h; i1++)
			{
				for (int j = 0; j < w; j++)
				{
					a[i1][j] = a[i1+1][j];
				}
			}
			i--;
			h--;
		}
		check = 0;
	}


	for (int j = 0; j < w; j++)
	{
		for (int i = 0;i < h; i++)
		{
			if (a[i][j] == '#')check++;
		}
		if (check == 0)
		{
			for (int j1 = j; j1 < w; j1++)
			{
				for (int i = 0; i < h; i++)
				{
					a[i][j1] = a[i][j1 + 1];
				}
			}
			j--;
			w--;
		}
		check = 0;
	}

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			cout << a[i][j];
		}
		cout<<endl;
	}
}
