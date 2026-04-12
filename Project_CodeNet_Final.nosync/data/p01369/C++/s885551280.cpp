#include<cmath>
#include<iostream>
#include<algorithm>
#include<iomanip>
#include<vector>
#include<string>
#include<queue>
#include<stack>
#include<cstdio>
#include<map>
#define rep(i,n) for(int i=0;i<n;i++)
#define fori(i,k,n) for(int i=k;i<n;i++)
using namespace std;
const int dx[4] = { 0, 1, 0, -1 }, dy[4] = { 1, 0, -1, 0 };
const int dX[8] = { 0, 1, 1, 1, 0, -1, -1, -1 }, dY[8] = { 1, 1, 0, -1, -1, -1, 0, 1 };
/*
(char)'1' - (int)48 = (int)1; 


*/


int main()
{
	string m = "yhnujmikolp";
	string a;
	cin >> a;
	while (a != "#")
	{
		int ans = 0;
		bool w = false;
		if (m.find(a[0]) != string::npos)w = true;
		for (int i = 1; i < a.size(); i++)
		{
			if (m.find(a[i]) != string::npos)
			{
				if (w == true);
				else
				{
					w = true;
					ans++;
				}
			}
			else
			{
				if (w == false);
				else
				{
					w = false;
					ans++;
				}
			}


		}
		cout << ans << endl;
		cin >> a;
	}
}