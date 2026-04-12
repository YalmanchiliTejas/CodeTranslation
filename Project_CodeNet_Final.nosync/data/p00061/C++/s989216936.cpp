#include<stdio.h>
#include <algorithm>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <iterator>
#include <list>
#include <map>     
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <iomanip>
#include <stack>
#include <string>
#include <vector>
using namespace std;
#define ll long long
#define ld long double
#define rep(a,t) for(int a=0;a<t;a++) 
#define forever while(true)
#define Sort(a) sort(a.begin(),a.end())
#define Reverse(a) reverse(a.begin(),a.end())
#define pb push_back
 
int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	vector<pair<int, int> > a;
	while (true) {
		int p, s;
		char mudaisyo;
		cin >> p >> mudaisyo >> s;
		if (p == s&&s == 0) { break; }
		a.push_back(make_pair(s, p));
	}
	Sort(a);
	Reverse(a);
	int t;
	
	while (cin >> t) {
		int last = 0;
		for (int i = 0; i < a.size() - 1; i++)
		{
			if (a[i].second == t) {
				cout << last + 1 << endl;
				break;
			}
			if (a[i].first != a[i + 1].first) {
				last ++;
			}
			if (i == a.size() - 2) {
				cout << last+1 << endl;
			}
		}
	}
	return 0;
}
