#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <list>
#include <queue>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <math.h>

#define PREP(i, m, n) for(int i = m; i < n; i++)
#define MREP(i, m, n) for(int i = m - 1; i >= n; i--)

#define rep(i, n) for(int i = 0; i < (n); i++)
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define all(v) v.begin(), v.end()
#define rev(v) v.rbegin(), v.rend()
#define prime first
#define weight second
#define MP make_pair
#define PB push_back

using namespace std;

int main(){
	map<char, bool> table;

	table['q'] = true;
	table['w'] = true;
	table['e'] = true;
	table['r'] = true;
	table['t'] = true;
	table['a'] = true;
	table['s'] = true;
	table['d'] = true;
	table['f'] = true;
	table['g'] = true;
	table['z'] = true;
	table['x'] = true;
	table['c'] = true;
	table['v'] = true;
	table['b'] = true;
	table['y'] = false;
	table['u'] = false;
	table['i'] = false;
	table['o'] = false;
	table['p'] = false;
	table['h'] = false;
	table['j'] = false;
	table['k'] = false;
	table['l'] = false;
	table['n'] = false;
	table['m'] = false;

	string input;
	while(cin >> input && input != "#"){
		int Switch = 0;
		bool currentState = table[input[0]];
		for(int i = 1; i < input.size(); i++){
			if(table[input[i]] != currentState){
				currentState = table[input[i]];
				Switch++;
			}
		}
		cout << Switch << endl;
	}
	
	return 0;
}