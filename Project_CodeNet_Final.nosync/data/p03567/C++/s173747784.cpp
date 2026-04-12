#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <utility>
#include <iomanip>
 
using namespace std;
 
 
int main() {
	string s;
	cin >> s;
	string res = "No";
	for(int i = 0; i+1 < s.length(); i++) {
		if(s.substr(i,2) == "AC") {
			res = "Yes";
		}
	}
	cout << res << endl;
	return 0;
}


