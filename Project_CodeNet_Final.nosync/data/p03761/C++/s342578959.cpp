#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <queue>
#include <algorithm>
#include<iostream>
#include<vector>
#include<map>
#include<string>
#include <iomanip>
#include<deque>
#include<stack>
#include<set>
#include <numeric>

using namespace std;
typedef unsigned int uint;
typedef long long ll;
//typedef pair<int, int> P;
const int INF = 1e9 + 1;
const ll LLINF = 1e17 + 1;
const int DX[9] = { 0,0,1,-1, 1, 1, -1, -1, 0 }; // 4;４近傍
const int DY[9] = { 1,-1,0,0, 1, -1, 1, -1, 0 }; // 8:８近傍 9:(0,0)を含む
const int MOD = 1e9 + 7; //10^9 + 7
const double PI = 3.14159265358979323846264338327950288;




int main() {

	//==================================
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	cout << fixed << setprecision(15);
	//==================================

	int N;
	cin >> N;
	vector<string> S(N);
	for (int i = 0; i < N; i++) {
		cin >> S[i];
	}

	vector<vector<int>> alp(N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 26; j++) {
			alp[i].emplace_back(0);
		}
	}


	int base = 'a';
	for (int i = 0; i < N; i++) {

		for (int j = 0; j < S[i].size(); j++) {
			alp[i][S[i][j] - base]++;
		}
	}

	vector<char> ans;
	for (int i = 0; i < 26; i++) {

		int times = INF;
		for (int j = 0; j < N; j++){
			times = min(times, alp[j][i]);
		}

		for (int j = 0; j < times; j++) {
			ans.emplace_back(char(base + i));
		}

	}

	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i];
	}


}	


