#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
#include <math.h>
#include <stdio.h>
#include <ctype.h>
#include <ios> 
#include <iomanip>
using namespace std;

#define N_MAX   (100000)
#define LL_MAX_NUM (1LL<<60)
#define INF 1e7

typedef long long ll;
typedef long long int lli;

int main() {
	char c; cin >> c;
	cout << ((c=='a'||c=='i'||c=='u'||c=='e'||c=='o')?"vowel":"consonant") << endl;
	return 0;
}