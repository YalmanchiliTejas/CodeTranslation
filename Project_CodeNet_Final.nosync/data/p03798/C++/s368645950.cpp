#include <iostream>
#include <list>
#include <vector>
#include <map>
#include <string>
#include <cmath>
#include <algorithm>
#include <cassert>

#define REP(i, n) for(int (i)=0;(i)<(n);++(i))
#define MOD 1000000007

typedef long long ll;

using namespace std;

bool check(string s, char c) {
	assert(s.size() == 3);
	assert(c == 'o' || c == 'x');

	if (c == 'o') {
		if (s[1] == 'S') {
			if ((s[0] == 'S' && s[2] == 'S') || (s[0] == 'W' && s[2] == 'W')) return true;
			else return false; 
		}
		else if (s[1] == 'W') {
			if ((s[0] == 'S' && s[2] == 'W') || (s[0] == 'W' && s[2] == 'S')) return true;
			else return false; 
		}
	}
	else if (c == 'x') {
		if (s[1] == 'S') {
			if ((s[0] == 'S' && s[2] == 'W') || (s[0] == 'W' && s[2] == 'S')) return true;
			else return false; 
		}
		else if (s[1] == 'W') {
			if ((s[0] == 'S' && s[2] == 'S') || (s[0] == 'W' && s[2] == 'W')) return true;
			else return false; 
		}
	}
}

int main(){
    int N;
    string s;
    cin >> N;
    cin >> s;

    string t = "";
    bool flag_making;
    // まず1, 2, 3番目を固定して考える(8パターン)
    vector<string> first_t = {"SSS", "SSW", "SWS", "SWW", "WSS", "WSW", "WWS", "WWW"}; 
    REP(i, first_t.size()) {
    	if (check(first_t[i], s[1])) {
    		t = first_t[i];
    		for (int j = 2; j < N; ++j) {
  				char c = s[j];
    			// t が完成したとき
    			if (j == N - 1) {
    				string last_s(3, 'a');
    				last_s[0] = t[j - 1];
    				last_s[1] = t[j];
    				last_s[2] = t[0];
    				string first_s(3, 'a');
    				first_s[0] = t[j];
    				first_s[1] = t[0];
    				first_s[2] = t[1];
    				flag_making = check(last_s, s[j]) && check(first_s, s[0]);
    			}
    			else {
    				if (c == 'o') {
    					if (t[j - 1] == 'S' && t[j] == 'S') t += 'S';
    					else if (t[j - 1] == 'S' && t[j] == 'W') t += 'W';
    					else if (t[j - 1] == 'W' && t[j] == 'S') t += 'W';
    					else if (t[j - 1] == 'W' && t[j] == 'W') t += 'S';
    				}
    				else if (c == 'x') {
    					if (t[j - 1] == 'S' && t[j] == 'S') t += 'W';
    					else if (t[j - 1] == 'S' && t[j] == 'W') t += 'S';
    					else if (t[j - 1] == 'W' && t[j] == 'S') t += 'S';
    					else if (t[j - 1] == 'W' && t[j] == 'W') t += 'W';
    				}
    			}
    		}
    	}
    	if (flag_making) break;
    }

    if (flag_making) cout << t << endl;
    else cout << "-1" <<endl;
}
