
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <cstring>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <array>
#include <cassert>
#include <bitset>
using namespace std;
using LL = long long;

int main(void)
{
	string S;
	cin >> S;
	for(int i=1;i<S.size();++i)
	if (S[i-1] == 'A'&&S[i] == 'C') {
		cout << "Yes\n"; return 0;
	}
	cout << "No\n";
	return 0;
}

