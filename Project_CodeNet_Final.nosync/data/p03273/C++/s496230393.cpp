#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	int h, w;
	cin >> h >> w;
	
	vector<string> v(h);
	for(int i = 0; i < h; i++)
	{
		cin >> v[i];
	}
	
	bool check[h][w] = {{true}};
	bool flag = true;
	while(flag != false)
	{
		bool flag2 = false;
		for(int i = 0; i < h; i++)
		{
			for(int j = 0; j < w; j++)
			{
				if(v[i][j] == '#')
				{
					break;
				}
				
				if(j == w - 1)
				{
					flag2 = true;
					v.erase(v.begin() + i);
					h--;
				}
			}
		}
		
		for(int i = 0; i < w; i++)
		{
			for(int j = 0; j < h; j++)
			{
				if(v[j][i] == '#')
				{
					break;
				}
				
				if(j == h - 1)
				{
					flag2 = true;
					for(int k = 0; k < h; k++)
					{
						v[k].erase(v[k].begin() + i);
					}
					w--;
				}
			}
		}
		
		flag = flag2;
	}
	
	for(int i = 0; i < h; i++)
	{
		cout << v[i] << endl;
	}
	
    return 0;
}