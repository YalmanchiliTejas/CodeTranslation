#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <ctype.h>
#include <map>
#include <vector>
#include <stdlib.h>
#include <cctype>
#define REP(i,n) for(int i=0;i<(int)n;++i)
#define REP1(j,n) for(int j=0;j<(int)n;++j)
#define REPD(i,n) for(int i=n;i>=0;--i)
#define REPD1(j,n) for(int j=n;j=>0;--j)
#define REPS(i,n) for(int i=1;i<=(int)n;++i)
#define REPS1(j,n) for(int j=1;j<=(int)n;++j)
#define rep(i,a,n) for(int i=a;i<=(int)n;++i)
#define SZ(x) ((int)(x).size())	//size() unsigned -> int
#define DescSort(a) sort(a.begin(),a.end(),std::greater<int>())

using namespace std;
typedef long long ll;

int main(void) {
	char c;
	cin >> c;
	if (c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o')
		cout << "vowel" << endl;
	else
		cout << "consonant" << endl;
	return 0;
}