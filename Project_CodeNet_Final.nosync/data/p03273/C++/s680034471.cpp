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
using ll = long long;
#define MAX_N 1000001
#define MAX_M 100010
const long long mod = 1e9 + 7;
#define vec vector<int>
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
#define printvec(vec) for(int aqw=0;aqw<vec.size();aqw++){cout<<vec[aqw]<<" ";}ent;
#define rep(i,n) for(int i=0;i<(int)n;++i)
#define REP(i,m,n) for(int i=m;i<(int)n;++i)
#define INF 1e+9
using P = pair<int, int>;
#define PLL pair<ll, ll>;
#define MAX_V 1000
#define PI 3.141592653589793
// cout << setprecision(15) << std::fixed;


int main()
{
	int h, w;
	cin >> h >> w;
	vecst st;
	string t(w, '.');
	for (int i = 0;i < h;i++) {
		string s;
		cin >> s;
		if (s != t) st.push_back(s);
	}
	char ans[110][110];
	int wp = 0;
	for (int j = 0;j < w;j++) {
		bool che = false;
		for (int i = 0;i < st.size();i++) {
			if (st[i][j] == '#') {
				che = true;
				break;
			}
		}
		if (che) {
			for (int i = 0;i < st.size();i++) {
				ans[i][wp] = st[i][j];
			}
			wp++;
		}
	}
	for (int i = 0;i < st.size();i++) {
		for (int j = 0;j < wp;j++) {
			cout << ans[i][j];
		}
		ent;
	}
}
