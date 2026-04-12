#include <iostream>
#include <list>
#include <vector>
#include <map>
#include <string>
#include <cmath>
#include <algorithm>

#define REP(i, n) for(int (i)=0;(i)<(n);++(i))
#define MOD 1000000007

typedef long long ll;

using namespace std;
int main(){
    int N;
    cin >> N;
    string S[N];
    REP(i, N) {
    	cin >> S[i];
    }

    map<char, int> count_map[N];
    for (int i = 0; i < N; ++i) {
	    for (char c = 'a'; c <= 'z'; ++c) {
	    	count_map[i][c] = 0;
	    }
	    for (int j = 0; j < S[i].size(); ++j) {
	    	count_map[i][S[i][j]]++;
	    }
	}

	map<char, int> min_map;
	for (char c = 'a'; c <= 'z'; ++c) {
	    	min_map[c] = 100;
	}
	for (int i = 0; i < N; ++i) {
	    for (char c = 'a'; c <= 'z'; ++c) {
	    	min_map[c] = min(min_map[c], count_map[i][c]);
	    }
	}

	string ans = "";
	for (char c = 'a'; c <= 'z'; ++c) {
	   for (int i = 0; i < min_map[c]; ++i) {
	   		ans += c;
	   }
	}

	cout << ans << endl;
}
