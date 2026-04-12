# include <iostream>
# include <algorithm>
# include <vector>
# include <string>
# include <set>
# include <map>
# include <cmath>
# include <iomanip>
# include <functional>
# include <utility>
# include <stack>
# include <queue>
# include <list>
# include <bitset>
# include <complex>
#include<limits.h>
#include<unordered_map>
#include<unordered_set>
#include<deque>
#include<cstdio>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
constexpr long long MOD = 1000000000 + 7;
constexpr long long INF = 1000000000;
const double PI = acos(-1);
int num_edge = 0, head[100000];
struct Edge { int nxt, to; }edge[100000];
LL n, m, sum = 0, f[100000] = {}, W[1000][1000] = {}, now = 0;
string str;
void add_edge(int from, int to) {
	edge[++num_edge].nxt = from;
	edge[num_edge].to = to;
	head[from] = num_edge;
}

char p[1000][1000];
int main() {
	cin >> str;
	for (int i = 0; i < str.size() - 1; i++) {
		if (str[i] == 'A'&&str[i + 1] == 'C') {
			cout << "Yes" << endl;
			break;
		}
		if (i == str.size() - 2)
			cout << "No"<<endl;
	}
	return 0;
}