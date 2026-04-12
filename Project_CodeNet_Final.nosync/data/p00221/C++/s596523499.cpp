#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <functional>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <utility>
#include <sstream>
#include <complex>
#include <numeric>

using namespace std;

#define FOR(i,a,b) for(long long i=(a);i<(b);i++)
#define REP(i,N) for(long long i=0;i<(N);i++)
#define ALL(s) (s).begin(),(s).end()
#define fi first
#define se second

#define PI acos(-1.0)
#define INF 1000000007
#define EPS 1e-10
#define MAX_N 20000
#define MAX_M 16

typedef long long ll;
typedef pair<ll, ll> P;
typedef pair<double, double> PD;
typedef pair<string, ll> PS;
typedef vector<ll> V;
typedef pair<P, char> PC;

int m, n;
bool f[1001];

string changes(int i){
	stringstream ss;
	string res;
	ss << i;
	ss >> res;
	return res;
}

int main(){
	while (cin >> m >> n&&m + n){
		REP(i, 1001)f[i] = 1;
		int now = 1, co = m;
		FOR(i, 1, n + 1){
			string t;
			cin >> t;
			while (!f[now]){
				now++;
				if (now > m)now = 1;
			}
			if (co == 1)continue;
			if (i % 15 == 0){
				if (t != "FizzBuzz"){
					f[now] = 0;
					co--;
				}
			}
			else if (i % 5 == 0){
				if (t != "Buzz"){
					f[now] = 0;
					co--;
				}
			}
			else if (i % 3 == 0){
				if (t != "Fizz"){
					f[now] = 0;
					co--;
				}
			}
			else{
				string s = changes(i);
				if (s != t){
					f[now] = 0;
					co--;
				}
			}
			now++;
			if (now > m)now = 1;
		}
		bool ff = 0;
		FOR(i, 1, m + 1){
			if (f[i]){
				if (!ff) {
					cout << i;
					ff = 1;
				}
				else{
					cout << " " << i;
				}
			}
		}
		cout << endl;
	}
}