#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
#include<climits>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<bitset>
#include<iomanip>
using namespace std;

#define rep(i,j,n) for(int i=(j);i<(n);i++)
#define rep2(i,j,n) for(int i=(j);i<=(n);i++)
#define all(i) i.begin(),i.end()

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<string> vs;
typedef vector<vector<string>> vvs;
typedef pair<int, int> pi;
typedef long long i64;

int main() {
	int n;
	while (cin >> n, n != 0) {
		vi s(n);
		int sum = 0;
		rep(i, 0, n) {
			cin >> s[i];
			sum += s[i];
		}
		sum -= *max_element(all(s)) + *min_element(all(s));
		cout << sum / (n - 2) << endl;
	}
}

