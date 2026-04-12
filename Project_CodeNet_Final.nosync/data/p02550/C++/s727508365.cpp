#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<string>
#include<climits>
#include<stack>
#include<queue>
#include<unordered_map>
#include<map>
#include<set>
#include<fstream>
#include<list>
#include<sstream>

#define loopi(x,y) for(int i = x;i<(y);i++)
#define loopj(x,y) for(int j = x;j<(y);j++)
#define rloopi(x,y) for(int i = x;i>=(y);i--)
#define rloopj(x,y) for(int j = x;j>=(y);j--)


#define nl cout<<"\n";
#define ll long long int
#define mod  1000000007

using namespace std;


int main()
{
	ios :: sync_with_stdio(false);
	cin.tie(nullptr);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	long long int n, x, m;
	cin >> n >> x >> m;

	unordered_map<int, int> hash;

	vector<int> rem;

	rem.push_back(x);

	hash[x] = 0;
	long long sum = 0;
	int start_cycle = -1;
	int i;
	for (i = 0; i <= m; i++)
	{
		long long p = rem[i];
		p = (p * p) % m;
		if (hash.find(p) != hash.end())
		{
			start_cycle = hash[p];
			break;
		}
		hash[p] = i + 1;
		rem.push_back(p);
	}
	for (i = 0; i < start_cycle && i < n ; i++)
	{
		sum += rem[i];
	}

	long long remains = n - i;

	long long int cycle_sum = 0;
	int k = rem.size();

	for (int j = start_cycle; j < k; j++)
	{
		cycle_sum += rem[j];
	}


	sum += cycle_sum * (remains / (k - start_cycle));

	remains = remains % (k - start_cycle);

	for (int j = start_cycle; j < start_cycle + remains; j++)
	{
		sum += rem[j];
	}

	cout << sum;
	return 0;

}