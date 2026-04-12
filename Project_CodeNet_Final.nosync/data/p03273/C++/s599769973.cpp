#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;
#define loop(i,N) for(ll (i)=0; (i)<(N);++(i))
struct _OMAZINAI_ { _OMAZINAI_() { std::ios::sync_with_stdio(false); std::cin.tie(0); } } __omazinai_instance__;
#define INF ((1LL<<61) + (1<<29))
#define YesNo(x) {std::cout << ((x)?"Yes":"No") << std::endl;}
#define YESNO(x) {std::cout << ((x)?"YES":"NO") << std::endl;}
#define OddEven(x) {std::cout << ((x)%2?"Odd":"Even") << std::endl;}
#define ODDEVEN(x) {std::cout << ((x)%2?"ODD":"EVEN") << std::endl;}
typedef long long int ll;
void _INPUT_IMPL_() {};
template <class T, class... Args> void _INPUT_IMPL_(T& dest, Args&... args) { cin >> dest; _INPUT_IMPL_(args...); }
void _OUTPUT_IMPL_() {};
template <class T, class... Args> void _OUTPUT_IMPL_(T dest, Args... args) { cout<< dest << (sizeof...(Args)?" ":""); _OUTPUT_IMPL_(args...); }
#define in(type, ...) type __VA_ARGS__; _INPUT_IMPL_(__VA_ARGS__)
#define in_v(type, name, cnt) vector<type> name(cnt); loop(i, cnt) cin >> name[i];
#define sort_v(v) std::sort(v.begin(), v.end())
#define out(...) (_OUTPUT_IMPL_(__VA_ARGS__), std::cout<<std::endl)
//小さい方に寄る
#define space_op(x, y, a, b, c) ([](auto x_, auto y_, auto a_, auto b_, auto c_){if(x_<y_)return a_;if(x_>y_)return c_;return b_;}(x,y,a,b,c))
#define space_out(x, y, a, b, c) out(space_op(x, y, a, b, c))

int main() {
	in(int, H, W);
	bool xr[200] = {}, yr[200] = {};
	vector<vector<char>> m;
	loop(y, H) {
		vector<char> t;
		string s;
		cin >> s;
		loop(x, W) {
			char c = s[x];
			t.push_back(c);
			if (c == '#') {
				xr[x] = true;
				yr[y] = true;
			}
		}
		m.push_back(t);
	}
	loop(y, H) {
		if (yr[y]) {
			loop(x, W) {
				if (xr[x])
					std::cout << m[y][x];
			}
			std::cout << std::endl;
		}
	}
}