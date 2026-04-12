#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <sstream>
#include <climits>
#include <cmath>
#include <map>
#include <stack>
using namespace std;
#define M_PI 3.141592
#define toRad 2.0*M_PI/360.0
#define inin(x) int x;cin>>x;
#define all(x) x.begin(),x.end()
#define debug(x) cout<<#x<<" "<<x<<endl;
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define EPS 1e-12
#define pri_max 60000
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
/*
bool memo[pri_max] = {};
vector<int> pri;
void calc()
{
	for (int i = 2; i < pri_max; i++)
	{
		if (memo[i] == false)
		{
			pri.push_back(i);
			for (int l = i; l < pri_max; l += i)
			{
				memo[l] = true;
			}
		}
	}
}*/
int main()
{
	vector <pii> a;
	pii temp;
	while (scanf("%d,%d", &temp.second, &temp.first) && temp.first != 0 || temp.second != 0)a.push_back(temp);
	sort(all(a));
	reverse(all(a));
	vector<int> jun[200];
	int k = 0,v=a[0].first;
	for (int i = 0; i < a.size(); i++)
	{
		if (v != a[i].first)
		{
			v = a[i].first;
			k++;
		}
		jun[k].push_back(a[i].second);
	}

	int num;
	while (cin >> num)
	{
		bool flag = true;
		for (int i = 0; i < 200&&flag; i++)
		{
			for (int l = 0; l < jun[i].size(); l++)
			{
				if (jun[i][l] == num)
				{
					cout << i + 1 << endl;
					flag = false;
					break;
				}
			}
		}
	}
}