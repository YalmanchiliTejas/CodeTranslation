#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <limits>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <iterator>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <queue>

#define MAX 100009
#define INF 99999999
#define in(a,b)  ( (b).find(a) != (b).end())
#define clr(a,b) memset((a), (b), sizeof((a)))
#define pb       push_back
#define all(a)   a.begin(), a.end()  
#define mp       make_pair
#define ll	long long
#define fi	first
#define se second

const long double pi = 3.141592653589793238L;
const ll mod = 1e9 + 7;

/**
*
* @Author Lahia omar
*/

using namespace std;

void split(vector<string> &v, string cur) {
	istringstream iss(cur);
	copy(istream_iterator<string>(iss), istream_iterator<string>(), back_inserter(v));
}
int t;
string a, b, c;
int main(int argc, char* argv[]) {
	cin >> a >> b >> c;
	cout << ((stoll(a + b + c) % 4 == 0) ? "YES" : "NO" )<< endl;
	return 0;
}