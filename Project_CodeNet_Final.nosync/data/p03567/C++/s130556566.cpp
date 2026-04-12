#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>  
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <cctype>
#include <list>
#include <cmath>
#include <bitset>
#include <queue>
#include <stack>
#include <sstream>
#include <functional>
#include <cassert>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
typedef pair<char, char> pcc;
const int inf = 0x3f3f3f3f;
const LL lnf = 0x3f3f3f3f3f3f3f3fLL;
const double pi = 3.14159265358979323846;
const double eps = 1e-8;
const int mod = 1e9 + 7;
const int maxn = 0 + 10;

char str[maxn];

int main() {
	int CAS = 0;
	//std::ios::sync_with_stdio(0);  
	//std::cin.tie(0);  
#ifdef NIGHT_13  
	freopen("in.txt", "r", stdin);
	//freopen("out2.txt", "w", stdout);
	int time_night_13 = clock();
#endif // NIGHT_13  

	while (scanf("%s", str) != EOF) {
		if (strstr(str, "AC") != NULL) {
			puts("Yes");
		}
		else {
			puts("No");
		}
	}


#ifdef NIGHT_13  
	fprintf(stderr, "\n^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
	fprintf(stderr, "\t   Time: %d ms", (int)clock() - time_night_13);
	fprintf(stderr, "\n...........................................\n\n");
#endif // NIGHT_13  
	return 0;
}