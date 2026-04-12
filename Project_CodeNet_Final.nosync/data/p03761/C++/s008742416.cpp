/*       Rohan Balot
    NSIT, New Delhi, India  */
#include <algorithm>
#include <bitset>
#include <functional>
#include <iostream>
#include <iomanip>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <utility>

#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
 
#define ALL(t) (t).begin(), (t).end()
#define ALLR(t) (t).rbegin(), (t).rend()
#define MP make_pair
 
const int N = int( 1e6 ) + 1;
const int M = int( 1e6 ) + 1;
const int MOD = int( 1e9 ) + 7;
const double PI = acos(-1);
const double eps = 1e-6;

void __answer()
{
	int n;
	cin >> n;
	vector< vector<int> > f(n, vector<int>(26, 0));
	for (int i = 0; i < n; i++) {
		string a;
		cin >> a;
		for (int j = 0; j < a.size(); j++) {
			f[i][a[j] - 'a']++;
		}
	}
	string s;
	bool foo = true;
	for (int i = 0; i < 26; i++) {
		int t = 1e9;
		for(int x = 0; x < n; x++)
			t = min(t, f[x][i]);
		for(int j = 0; j < t; j++) {
			foo = false;
			cout << char('a' + i);
		}
	}
	if(foo) cout << "";
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifdef LOCAL
        freopen("sample_input.txt", "r", stdin);
    #endif
    __answer();
    return 0;
}