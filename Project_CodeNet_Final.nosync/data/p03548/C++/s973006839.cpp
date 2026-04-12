#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <cstdlib>
#include <stack>
#include <queue>
#include <cmath>

#define rep(i,j,k) for(int i=(int)j;i<(int)k;i++)
#define repp(i,j,k) for(int i=j;i>=k;i--)
#define llrep(i,j,k) for(long long int i=j;i<(long long int)k;i++)
#define Sort(x) sort(x.begin(),x.end()); 
#define vi vector<int>
#define vvi vector<vector<int>> 
#define ll long long
int mod=1e9+7;
const int INF = 1e9;

using namespace std;



int main(void) {
	int x, y, z;
	cin >> x >> y >> z;
	//if (x % (y + z) == 0)cout << (x / (y + z)) - 1 << endl;
	//else cout << x / (y + z) << endl;

	int count = 0;
	x -= z;
	while (x >= (y + z)) {
		x -= (y + z);
		count++;
	}

	cout << count << endl;


	return 0;
}