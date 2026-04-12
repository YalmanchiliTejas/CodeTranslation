#include <iostream>
#include <string>
#include <unordered_map>
#include <stdio.h>
#include <list>
#include <vector>
#include <algorithm>
#include <stack>
#include <climits>
#include <cmath>
#include <queue>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; ++i)
typedef long long ll;

int main()
{
	int n; cin >> n;
	int m; cin >> m;
	int roop=1;
	for(int i=2;i<n;i++)
	{
		roop*=i;
	}

	vector<vector<int >> ab(n,vector<int>(n));
	rep(i,n)
		rep(j,n)
		{
			ab[i][j]=0;
		}

	rep(i,m)
	{
		int foo,fooo;
		cin >> foo >> fooo;
		ab[foo-1][fooo-1]=1;
		ab[fooo-1][foo-1]=1;
	}

	vector<int> root(n);
	rep(i,n)root[i]=i;
	int c=0;
	rep(ii,roop)
	{
		//rep(i,n)cout<<root[i];cout<<endl;
		bool isthrogh = true;
		rep(i,n-1)if(!ab[root[i]][root[i+1]])isthrogh=false;
		if(isthrogh)c++;
		next_permutation(root.begin(),root.end());
	}
	cout<<c<<endl;
	
	return 0;
}