#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <cmath>
#include <map>
#include <string>
#include <bitset>
#include <set>

using ll = long long;
using namespace std;

int main(void) {
	string s;
	cin >> s;
	
	set<char> st;
	for(int i = 0; i < s.size(); ++i) {
		st.insert(s[i]);
	}
	
	if( st.size() == 2 ) cout << "Yes" << endl;
	else cout << "No" << endl;
	
	return 0;
}
