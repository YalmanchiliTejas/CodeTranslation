#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <map>
#include <cstdlib>
#include <istream>
#include <set>
#define rep0(i,n) for (long long int i = 0; i <= (n); ++i)
#define rep1(i,n) for (long long int i = 1; i <= (n); ++i)
#define REP(a,b) for (long long int i = a; i <= (b); ++i) 
#define MOD 100000007
#define ps push_back 
using namespace std;
typedef long long ll;
int main() {
	int n;
	cin >> n;
	if (n == 7)printf("YES");
	else if(n == 5)printf("YES");
	else if(n == 3)printf("YES");
	else printf("NO");
	return 0;
}