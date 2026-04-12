#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#define rep(i,a,n) for(ll i =(a);i<(n);i++)
#define urep(i,a,n) for(ll i = (a);i>=(n);i--)
#define all(x) (x).begin(),(x).end()
#define INF 1e9
const int mod = 1e9 + 7;
typedef long long ll;
using namespace std;
ll dx[4] = { 1,-1,0,0 };
ll dy[4] = { 0,0,1,-1 };
ll N, M, Q, H, W, D, L, R,K;
ll A;
ll B[200001];
ll ans;
string S;
char s[52][52];
ll gcd(ll a, ll b) {
	if (b == 0)return a;
	else return gcd(b, a%b);
}
char a[100][100];
ll Hcount[100];
ll Wcount[100];
int main() {
	cin >> H >> W;
	rep(i, 0, H) {
		rep(j, 0, W) {
			cin >> a[i][j];
			if (a[i][j] == '.') {
				Hcount[i]++;
				Wcount[j]++;
			}
		}
	}
	rep(i, 0, H) {
		rep(j, 0, W) {
			if (Hcount[i]!=W && Wcount[j]!=H)
				cout << a[i][j];
		}
		if(Hcount[i] != W)
			cout << endl;
	}
	cin >> N;
	return 0;
}