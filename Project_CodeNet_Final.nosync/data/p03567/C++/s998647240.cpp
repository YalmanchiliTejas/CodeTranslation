#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <fstream>
#include <set>
#include <utility>
#include <algorithm>
#include <queue>
#include <stack>
#include <deque>
#include <numeric>
#include <sstream>
#include <list>
#include <map>

#define rep(i,p,n) for(int i=(int)p;i<(int)n;i++)
#define repp(i,p,n) for(int i=(int)p;i>=(int)n;i--)
#define Sort(x) sort(x.begin(),x.end());
#define ll long long 
#define vi vector<int>
#define vvi vector<vector<int>>
#define vvvi <vector<vector<vector<int>>> 
#define vc vector<char> 
#define vvc vector<vector<char>>
#define vvvc vector<vector<vector<char>>> 

using namespace std;

int main() {
	string s;
	cin >> s;
	rep(i, 0, s.length() - 1) {
		if (s[i]=='A' && s[i+1]=='C') {
			cout << "Yes" << endl;
			return 0;
		}
	}

	cout << "No" << endl;

	return 0;
}
