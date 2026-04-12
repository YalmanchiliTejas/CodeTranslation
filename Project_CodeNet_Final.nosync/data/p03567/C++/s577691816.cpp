#include <map>
#include <set>
#include <list>
#include <ctime>
#include <cmath>
#include <queue>
#include <stack>
#include <bitset>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <sstream>
#include <iomanip>
#include <cstdlib>
#include <utility>
#include <iostream>
#include <algorithm>
using namespace std;
int main ( ) {
	string s;
	int i,l;
	cin>>s;
	l=s.length();
	for (i=1;i<l;i++) {
		if (s[i-1]=='A' && s[i]=='C') {
			puts("Yes");
			return 0;
		}
	}
	puts("No");
	return 0;
}