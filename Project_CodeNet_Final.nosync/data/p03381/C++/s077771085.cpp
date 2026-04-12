#define _CRT_SECURE_NO_WARNINGS
#pragma _attribute_((optimize("-O2")))
#pragma comment(linker, "/STACK:102400000,102400000")

#include <iostream>
#include <queue>
#include <stack>
#include <cstdio>
#include <vector>
#include <map>
#include <list>
#include <set>
#include <cstdio>
#include <bitset>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <string>
#include <sstream>
#include <time.h>
#include <complex>
#include <iomanip>
#define Endl endl
#define int long long

//#define Local

using namespace std;


signed main()
{
	//ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	//freopen("input1.txt","r",stdin);
	//freopen("output1.txt","w",stdout);

	int n;
	cin>>n;
	vector<pair<int,int> > all;
	for(int i=0;i<n;i++)
	{
		int tmp;
		cin>>tmp;
		all.push_back({tmp,i});
	}
	vector<int> res(n);
	sort(all.begin(),all.end());
	for(int i=0;i<n;i++)
	{
		if(i<n/2)
			res[all[i].second]=all[n/2].first;
		else
			res[all[i].second]=all[n/2-1].first;
	}
	for(int i=0;i<n;i++)
		cout<<res[i]<<endl;


	#ifdef Local
	cout << "time: " << (long long)clock() * 1000 / CLOCKS_PER_SEC << " ms" << endl;
#endif
	return 0;
}
