#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cassert>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <iostream>
#include <map>
#include <set>
using namespace std;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
typedef long long ll;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
int main()
{
	while(1)
	{
		int x[5],y[5];
		cin >> x[0] >> y[0];
		if(x[0]+y[0] == 0) return 0;
		for(int i=1;i<5;i++) cin >> x[i] >> y[i];
		for(int i=0;i<5;i++)
		{
			for(int j=0;j<5;j++)
			{
				if(i == j) continue;
				if(x[i]+y[i] < x[j]+y[j])
				{
					goto out;
				}
			}
			cout << (char)('A'+i) << " " << x[i]+y[i] << endl;
			out:;
		}
	}
}