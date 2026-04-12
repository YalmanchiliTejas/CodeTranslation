#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cmath>
#include<sstream>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<utility>
#include<iomanip>
#include<vector>
#include<string>
#include<queue>
#include<stack>
#include<map>
#include<list>
#include<set>
#include<stdlib.h>
#include<time.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define repp(i,k,n) for(int i=k;i<(int)n;i++)
using namespace std;
const int dx[4] = { 0, 1, 0, -1 }, dy[4] = { 1, 0, -1, 0 };
const int dX[8] = { 0, 1, 1, 1, 0, -1, -1, -1 }, dY[8] = { 1, 1, 0, -1, -1, -1, 0, 1 };
struct XY
{
	int x;
	int y;
};
vector<long long> Prime;
void SieveOfEratosthenes(long long e) //setup vector<long long>Prime(~x)
{
	bool *x=new bool[e];
	for (long long i = 0; i <= e; i++)x[i] = false;
	for (long long i = 2; i <= e; i++)
	{
		if (x[i]);
		else
		{
			Prime.push_back(i);
			for (long long l = i; l <= e; l += i)x[l] = true;
		}
	}
	return;
}
int StringToInt(string a)
{
	stringstream ss;
	int x;
	ss << a;
	ss >> x;
	return x;
}
string IntToString(int a)
{
	stringstream ss;
	string x;
	ss << a;
	ss >> x;
	return x;
}
int GetRandom(int MIN, int MAX)
{
	static int flag=0;
	if (flag == 0)
	{
		srand((unsigned int)time(NULL));
		flag = 1;
	}
	return MIN + (int)(rand()*(MAX - MIN + 1.0) / (1.0 + RAND_MAX));
}
int in()
{
	int x;
	cin >> x;
	return x;
}
void outl(string a)
{
	cout << a << endl;
	return;
}
void outl(int a)
{
	cout << a << endl;
	return;
}
void out(string a)
{
	cout << a;
	return;
}
void out(int a)
{
	cout << a;
	return;
}
/*
(char)'1' - (int)48 = (int)1;
???1111181
 (char)A=(int)65
 (char)a=(int)97
*/
////////////////////////////////////////////////////

int main()
{
	while (1)
	{
		vector<pair<int, string > > a;
		pair<int, string> z;
		z.first = 0;
		z.second = "A";
		for (int i = 0; i < 5; i++)
		{
			a.push_back(z);
			z.second='B'+i;
		}
		bool end = false;
		for (int i = 0; i < 5; i++)
		{
			int x = in() + in();
			if (i == 0 && x == 0)
			{
				end = true;
				break;
			}
			a[i].first += x;
		}
		if (end)break;
		sort(a.begin(), a.end());
		cout << a[4].second << " " << a[4].first << endl;

	}

}