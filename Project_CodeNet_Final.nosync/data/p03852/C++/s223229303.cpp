#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) FOR(i,0,n)
#define rep(i,n) FOR(i,0,n)
#define DEBUG(x) cout<<#x<<": "<<x<<endl
#define vint vector<int>
#define vdouble vector<double>
#define vstring vector<string>
using namespace std;

#include<map>
#include<set>
#include<queue>

typedef long long ll;
typedef unsigned long long ull;

int main() {

	char c;
	cin >> c;

	string ret;
	if (c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o'){
		ret = "vowel";
	}
	else{
		ret = "consonant";
	}
	cout << ret;
}