
#include<iostream>
#include<utility>
#include<string>
#include<vector>
#include<algorithm>
#include<deque>
#include<queue>
#include<set>
#include<map>
#include<functional>

using namespace std;
#define LL long long
#define ALF "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define LLBIG 1999999999999999999
#define INTBIG 1111111111
#define MOD 1000000007
#define PI pair<int,int>
#define VI vector<int>
#define VVI vector<vector<int>>

int main() {
	int n, k; string s; cin >> n >> s >> k;
	char c = s[k - 1];
	for (int i = 0; i < n; i++)
		if (s[i] != c)s[i] = '*';
	cout << s << endl;


	return 0;
}
