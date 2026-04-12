#include <iostream>
#include <fstream>
#include <string> 
#include <cmath>  
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <functional>

using namespace std;
using ll = long long;

#define FOR(i, m, n) for(int i = (m);i < (n);i++)
#define REP(i,n) for(int i = 0; i < int(n); i++)
#define VI vector<int>
#define VVI vector<vector<int>>
#define VVVI vector<vector<vector<int>>>
#define VL vector<ll>
#define VVL vector<vector<ll>>
#define VB vector<bool>
#define VVB vector<vector<bool>>
#define PAIR pair<int,int>
#define MP make_pair
#define VP vector<pair<int,int>>
#define VS vector<string>
#define QUE queue<int>
#define DEQ deque<int>
#define PQUE priority_queue<int> //5,5,4,3,3,2,...
#define REPQUE priority_queue<int, vector<int>, greater<int>> //1,1,2,3,4,4,5,...
#define SUM(obj) accumulate((obj).begin(), (obj).end(), 0)
#define SORT(obj) sort((obj).begin(), (obj).end()) // 1,2,3,4,5...
#define RESORT(obj) sort((obj).begin(), (obj).end(), greater<int>()) // 5,4,3,2,1...
#define UB(obj,n) upper_bound((obj).begin(), (obj).end(), n) //itr > n
#define LB(obj,n) lower_bound((obj).begin(), (obj).end(), n) //itr>= n

const ll INF = (ll)9e18;

int main() {
	int N;
	cin >> N;
	VS S(N);
	VVI alphabet(N, VI(26, 0));
	REP(i, N) {
		cin >> S[i];
		REP(j, S[i].size()) {
			alphabet[i][S[i][j] - 'a']++;
		}
	}

	bool flag = true;
	REP(j,26){
		int minc = 100000000;
		REP(i, N) {
			minc = min(minc, alphabet[i][j]);
		}
		if (minc != 0) flag = false;
		REP(i, minc) {
			cout << (char)(j + 'a');
		}
	}
	if (flag) cout << " ";
	cout << endl;
	return 0;
}

