#include <iostream>
#include <algorithm>
#include <vector>
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

const long long int INF = 1 << 29; //<10^10
//const ll MOD = 998244353;
const ll MOD = 1000000007;

inline bool maxch(int &a, int b) { if (a < b) {a = b; return true;} else return false;}

int main() {
  string _n;
	int k;
	cin >> _n >> k;

	int size = _n.size();

	vector<int> n(size);
	rep(i, size) {
	  n[i] = static_cast<int>(_n[i] - '0');
	}

	vector<vector<int>> dp1(size,vector<int>(k+1,0)), dp2(size,vector<int>(k+1,0));
	dp1[0][1] = 1;
	dp2[0][1] = n[0] - 1;
	dp2[0][0] = 1;

	rep(i, size-1) rep(j,k+1) {
		if (n[i+1] == 0) {
			dp1[i + 1][j] += dp1[i][j];
			dp2[i + 1][j] += dp2[i][j];
			if (j != k) dp2[i + 1][j+1] += dp2[i][j]*9;
		}
		else {
			if (j != k) {
				dp1[i + 1][j + 1] += dp1[i][j];
				dp2[i + 1][j + 1] += dp1[i][j] * (n[i+1] - 1) + dp2[i][j] * 9;
			}		
			dp2[i + 1][j] += dp1[i][j] + dp2[i][j];
		}
	}

	//debug2D(dp1);
	//cout << endl;
	//debug2D(dp2);

	cout << dp1[size-1][k] + dp2[size-1][k] << endl;
}


