#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <cmath>
#include <queue>
#include <map>
#include <numeric> //lcm


#define ERROR() cout << "ERROR!!" << endl; return 0;
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = n-1; i >= 0; --i)
#define rep1(i,n) for(int i = 1; i <= (n); ++i)

#define debug(vec) for(auto v : vec) cout << v << " "; cout << endl;

#define debug2D(vec2D) for(auto vec : vec2D) { for (auto v : vec) cout << v << " "; cout << endl; } 

using namespace std;

typedef long long ll;

const long long int INF = 1000000000; //<10^10
//const ll MOD = 998244353;
const ll MOD = 1000000007;

inline bool maxch(int& a, int b) { if (a < b) { a = b; return true; } else return false; }

int main() {
	//int k, n, m;
	string s;
	cin >> s;

	bool a = false, b = false;
	for(char c : s) a = a || (c == 'A');
	for(char c : s) b = b || (c == 'B');
	if (a && b) 
	cout << "Yes" << endl;
	else cout << "No" << endl;
}


