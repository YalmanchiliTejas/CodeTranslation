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
#include <fstream>
#include<list>

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

	int x;

	cin >> x;

	if (x >= 30)
		cout << "Yes";
	else
		cout << "No";


	return 0;
}
