#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <functional>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include<complex>
#include <cassert>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define repd(i, n) for (int i = n; i > 0; i--)
#define mod 1000000007
#define MOD 998244353
#define inf 1e20
typedef long long int ll;
typedef pair<ll, ll> pr;
typedef complex<double> com;


int main(){
	string s;
	cin >>s;
	if (s == "a" || s == "i" || s == "u" || s == "e" || s == "o") {
		cout << "vowel";
	}
	else {
		cout << "consonant";
	}
	return 0;
}
//Ctrl+Aを使わない