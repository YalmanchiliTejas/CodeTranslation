#define _USE_MATH_DEFINES
#include <iostream>
#include <complex>
#include <algorithm>
#include <vector>
#include <stack>
#include <string>
#include <queue>
#include <cmath>
#include <math.h>
#include <numeric>
#include <list>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <climits>
#include <set>
#include <memory.h>
#include <memory>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cassert>
#include <map>
#include <cassert>
#include <time.h>
#include <ctime>

using namespace std;

typedef complex<double> xy_t;
typedef pair<xy_t, xy_t> line;
typedef vector<xy_t> polygon;
typedef long long ll;
typedef pair<int, int> P;
typedef pair<int , P> PP;
typedef pair<int, string> Ps;
typedef vector<int> vec;
typedef vector<vec> mat;
const int INF = 1 << 29;
const double EPS = 1e-10;
const double PI = 3.1415926535897932384626433832795;
const int CLK = CLOCKS_PER_SEC;

#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, m, n) for(int i = m; i < n; i++)
#define repD(i, n) for(int i = n; i >= 0; i--)

bool fail[1000];
int nxt[1000];

bool check(string s, int n){
	if(n % 3 == 0 && n % 5 == 0) return s == "FizzBuzz";
	if(n % 3 == 0) return s == "Fizz";
	if(n % 5 == 0) return s == "Buzz";
	if(!isdigit(s[0])) return false;
	return n == atoi(s.c_str());
	int num = 0;
	int sz = s.size();
	rep(i, sz){
		if(!isdigit(s[sz-1-i])) return false;
		num = num * 10 + s[sz-1-i] - '0';
	}
	return num == n;
}

int main(){
	int m, n;
	int rest;
	string s;
	while(cin >> m >> n && (m || n)){
		getline(cin, s);
		memset(fail, false, sizeof(fail));
		rep(i, m){
			nxt[i] = (i+1)%m;
		}
		int pos = m-1;
		rest = m;
		rep(i, n){
			getline(cin, s);
			
			if(rest == 1 ) continue;
			if(!check(s, i+1)){
				int tmp = nxt[pos];
				nxt[pos] = nxt[tmp];
				fail[tmp] = true;
				rest--;
			}else{
				pos = nxt[pos];
			}
		}
		
		vector<int> res;
		rep(i, m) if(!fail[i]) res.push_back(i+1);
		rep(i, (int)res.size()){
			if(i != 0) cout << " ";
			cout << res[i];
		}
		cout << endl;
	}
	return 0;
}