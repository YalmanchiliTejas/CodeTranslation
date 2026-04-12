#include <iostream>
#include <float.h>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <iomanip>
#include <sstream>
#include <bitset>
#include <fstream>
#include <queue>
#include <set>
#include <stdlib.h>
#include <time.h>
#include <list>
#include <stack>
#include <queue>
#include <sstream>

#define For(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)  For(i,0,n)

//clear memory
#define CLR(a) memset((a), 0 ,sizeof(a))
#define SORT(c) sort((c).begin(),(c).end())
#define vi(m,a) vector<int> m(a)
#define vti(m,a,i) vector<vector<int>> m(a,vector<int>(i))
#define ALL(it,a) for(auto it = a.begin(); it!=a.end(); it++)
#define Fe(it,a) for(auto &it : a)
#define all(a) begin(a),end(a)

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
#define WARU 1000000007;

int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };




int main() {
	string str;
	cin >> str;
	bool ok = false;
	rep(i, str.size()-1) {
		if (str[i] == 'A' && str[i + 1] == 'C')
			ok = true;
	}
	if (ok)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
}

