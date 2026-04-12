#include <bits/stdc++.h>
using namespace std;

int main() {
	int h,w;
	cin >> h >> w;
	vector<vector<char>> a(h+1,vector<char>(w+1,'.'));
	vector<vector<char>> b(h+1,vector<char>(w+1,'.'));
	for(int i=0;i<h;i++)
	{
		for(int j=0;j<w;j++)
		{
			cin >> a.at(i).at(j);
		}
	}
	string k = "Possible";
	int x=0,y=0;
	for(int i=0;i<h+w-2;i++)
	{
		b.at(x).at(y) = '#';
		int x1 = x + 1,y1 = y + 1;
		if(a.at(x1).at(y) == '#' && 
		   a.at(x).at(y1) == '#')
		{
			k = "Impossible";
			break;
		}
		else if(a.at(x1).at(y) == '#')
		{
			x++;
		}
		else if(a.at(x).at(y1) == '#')
		{
			y++;
		}
		else
		{
			k = "Impossible";
			break;
		}
	}
	b.at(h-1).at(w-1) = '#';
	if(a == b)
	{
		k = "Possible";
	}
	else
	{
		k = "Impossible";
	}
    cout << k << endl;
	return 0;
}
