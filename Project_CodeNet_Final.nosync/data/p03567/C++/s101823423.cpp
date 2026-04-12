#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cstdio>
#include <cassert>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <string>
#include <deque>
#include <queue>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <bitset>
#include <stack>
#include <iomanip>
#include <utility>
#include <functional>
using namespace std;
#define ll long long
#define ull unsigned ll
/*Fast I/O goes here*/
const double EPS = 1e-8;
const ll PR = 19260817;
const ll inv2 = 500000004;
const ll inv3 = 333333336;
int main() {
	string s;cin>>s;for(int i=0; i<s.length()-1; i++) if(s[i]=='A'&&s[i+1]=='C') {puts("Yes");return 0;} puts("No");
	return 0;
}