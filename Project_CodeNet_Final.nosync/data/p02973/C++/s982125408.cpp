#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <climits>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <string>
#include<vector>
#include <set>
#define rep(i,n) for(i=0;i<n;i++)
#define P pair<int,int>
#define ll long long 
using namespace std;
int n;
ll a[100000];

int main()
{
	ll b, c, d, e, f, i, j,m;
	vector<ll> v;
	cin >> n;
	cin >> b;
	v.push_back(b);
	m = b;
	for(i=1;i<n;i++){
		cin >> b;
		if (m >= b) {
			v.push_back(b);
			m = b;
			continue;
		}

		rep(j, v.size()) {
			if (v[j] < b) {
				v[j] = b;
				if (j == v.size() - 1)m = b;
				break;
			}
		}


	}
	//rep(i, v.size())cout << v[i] << "\n";
	cout << v.size();

	return 0;
}