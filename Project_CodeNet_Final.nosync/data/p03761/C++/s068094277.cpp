#include<iostream>
#include<string>
#include<vector>
#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<numeric>
#include<iomanip>
#include<deque>
#include<tuple>
#include<queue>
#include<map>
#include <cstdint>
#include <boost/multiprecision/cpp_int.hpp>


#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define vi vector<int>
#define all(x) (x).begin(),(x).end()
#define Endl endl
#define F first
#define S second

namespace mp = boost::multiprecision;

using cpp_int = mp::cpp_int;
using ll = long long;
using namespace std;

int digits(ll n) {
	int count = 0;
	while (n > 0) {
		n /= 10;
		count++;
	}
	return count;
}
int main() {
	int n;
	cin >> n;
	vector<int>alpha(26);
	rep(i, n) {
		string s;
		cin >> s;
		vector<int>alpha1(26);
		rep(j, s.size()) {
			int a = s[j];
			a -= 97;
			//cout << a << endl;
			if (i == 0) {
				alpha[a]++;
			}
			alpha1[a]++;
		}
		rep(j, 26) {
			//cout <<"p "<< alpha[j] << endl;
			//cout <<"ph"<< alpha1[j] << endl;
			alpha[j] = min(alpha[j], alpha1[j]);
		}
	}
//	cout << "a" << endl;
	rep(i, 26) {
		char a = 'a' + i;
		//cout << alpha[i] << endl;
		rep(j, alpha[i]) {
			cout << a ;
		}
	}
	cout << endl;
}