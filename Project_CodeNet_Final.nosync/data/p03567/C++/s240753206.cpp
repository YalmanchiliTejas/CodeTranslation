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
	string s;
	cin >> s;
	rep(i, 0, s.length() - 1) {
		if (s[i] == 'A' && s[i + 1] == 'C') {
			cout << "Yes" << endl;
			return 0;
		}
	}

	cout << "No" << endl;

	return 0;
}