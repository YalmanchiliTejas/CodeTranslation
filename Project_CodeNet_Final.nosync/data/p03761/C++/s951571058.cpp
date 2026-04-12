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
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
using namespace std;
using ll = int64_t;
#define MAX_N 1010
#define MAX_M 100010
const long long mod = pow(10, 9) + 7;
#define vect vector<int>
#define vecll vector<ll>
#define vecllvec vector<vector<ll>>
#define vecb vector<bool>
#define vecBvec vector<vector<bool>>
#define vecst vector<string>
#define veche vector<char>
#define vecd vector<double>
#define vecvec vector<vector<int>>
#define vecDvec vector<vector<double>>
#define vecHvec vector<vector<char>>
#define all(x) (x).begin(),(x).end()
#define ent cout<<endl
#define printvec(vect) for(int aqw=0;aqw<vect.size();aqw++){cout<<vect[aqw]<<" ";}ent;
#define rep1(n) for(ll i = 0; i < (n); ++i)
#define rep2(i, n) for(ll i = 0; i < (n); ++i)
#define rep3(i, a, b) for(ll i = (a); i < (b); ++i)
#define rep4(i, a, b, c) for(ll i = (a); i < (b); i += (c))
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
#define INF 100100101001LL;
#define print(x) cout<<x<<endl;
using P = pair<int, int>;
#define PLL pair<ll, ll>;
#define MAX_V 10010
#define PI 3.141592653589793
#define vecP vector<P>
//cout << setprecision(15) << std::fixed;


int main() {
	int n;
	cin >> n;
	vector<map<char, int>> M(n);
	for (int i = 0;i < n;i++) {
		string s;
		cin >> s;
		for (int j = 0;j < s.size();j++) {
			//print(s[j]);
			M[i][s[j]]++;
		}
	}
	string ans = "";
	for (char al = 'a';al <= 'z';++al) {
		vect A;
		for (int i = 0;i < n;i++) {
			A.push_back(M[i][al]);
		}
		int cut = *min_element(all(A));
		ans += string(cut,al);
	}
	print(ans);
}