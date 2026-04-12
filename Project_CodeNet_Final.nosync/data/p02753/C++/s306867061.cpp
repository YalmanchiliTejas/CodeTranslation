#include <iostream>
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <stdio.h> 
#include <map>
#include <cmath>
#include <cstring>
#include <stack>
#include <queue>
#include <set>
#include <deque>
#include <sstream>
#include <vector>
#include <algorithm>

typedef long long ll;
using namespace std;

int main() {
	string s;
	cin>>s;
	if(s[0]==s[1] && s[1]==s[2]) {
		cout << "No";
	} else {
		cout << "Yes";
	}
	
	return 0;
}