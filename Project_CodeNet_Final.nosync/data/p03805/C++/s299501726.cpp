#include<string>
#include<stdio.h>
#include<iostream>
#include<iomanip>
#include<ios>
#include<algorithm>
#include<stack>
#include<queue>
#include<cmath>
#include<type_traits>
#include<random>
#include<vector>
#include<map>


using namespace std;

bool flag = 0;

vector<bool> used;

int connect[10][10] = {};

int co;

int N,M;

void tansaku(int x,int depth)
{
	used[x] = 1;
	if(depth==N-1)
	{
		co = co + 1;
		used[x] = 0;
		return;
	}
	for(int i=0;i<N;i++)
	{
		if(connect[x][i]==1 && used[i]==0)
		{
			tansaku(i,depth+1);
		}
	}
	used[x] = 0;

}

int main()
{
	cin >> N >> M;
	vector<int> a(M);
	vector<int> b(M);
	for(int i=0;i<N;i++)
	{
		used.push_back(0);
	}
	for(int i=0;i<M;i++)
	{
		cin >> a[i] >> b[i];
		a[i] = a[i] - 1;
		b[i] = b[i] - 1;
		connect[a[i]][b[i]] = 1;
		connect[b[i]][a[i]] = 1;
	}
	co = 0;
	tansaku(0,0);
	cout << co << endl;
}


