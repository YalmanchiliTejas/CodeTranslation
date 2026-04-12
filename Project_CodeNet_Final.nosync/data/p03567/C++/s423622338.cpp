//inlclude前用define 
#define _USE_MATH_DEFINES

//include
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
#include<type_traits>
#include<numeric>
//#include<deque>
#include<iomanip>
#include<set>
#include<tuple>
#include<map>

using namespace std;

//typedef
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<char> VC;
typedef long long int ll;

//define
#define INF 1e9 
#define NUM 1000000007
#define all(x) begin(x), end(x)
#define rep(i,n) for(int i=0;i<(int)(n);i++)

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	string s;
	cin >> s;
	bool  flag = false;
	string ans = "No";
	rep(i, s.size()-1) {
		if (s[i] == 'A' && s[i + 1] == 'C') {
			ans = "Yes";
		}
	}
	cout << ans << endl;

	return 0;
	
}



