#include <cmath>
#include <ctime>
#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <list>
#include <deque>
#include <stack>
#include <bitset>
#include <functional>
#include <numeric>
#include <utility>
#include <iomanip>
#include <cstdio>
#include <cctype>
#include <queue>
#include <complex>
#include <climits>

typedef long long ll;

using namespace std;
char tower[100][1000];

int main(void){
	char c;
	int n, p, p1, p2;
	cin >> n;
	int pos_t[100] = {0}, pos_r = 0;
	string s;
	while(1){
		cin >> s;
		if(s == "quit") break;
		if(s == "push"){
			cin >> p;
			cin >> tower[p-1][pos_t[p-1]++];
		}
		if(s == "pop"){
			cin >> p;
			cout << tower[p-1][--pos_t[p-1]] << endl;
		}
		if(s == "move"){
			cin >> p1 >> p2;
			c = tower[p1-1][--pos_t[p1-1]];
			tower[p2-1][pos_t[p2-1]++] = c;
		}

	}
	return 0;
}