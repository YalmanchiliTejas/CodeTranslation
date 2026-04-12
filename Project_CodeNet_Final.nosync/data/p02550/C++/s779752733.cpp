#include<bits/stdc++.h>
using namespace std;

//-std=c++11
//#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
	cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif

#define LL long long
#define FI ios_base::sync_with_stdio(0); cin.tie(NULL);
#define PREC cout << setprecision(10) << fixed;

const int MOD = 1e9 + 7;
const int INF = 1e9 + 9;
const int MX = 1e5 + 5;

int main()
{
	#define int long long
	int n,x,m;
	cin >> n >> x >> m;

	int start;

	set<int> st;
	st.insert(x);
	int last = x;
	while(1) {
		int next = (last * last)%m;
		if(st.find(next) != st.end()) {
			start = next;
			break;
		}
		st.insert(next);
		last = next;
	}

	vector<int> val;
	int sum = 0;
	val.push_back(start);
	sum += start;
	last = start;
	while(1) {
		int next = (last * last)%m;
		if(next == start) {
			break;
		}
		val.push_back(next);
		sum += next;
		last = next;
	}
	int sz = val.size();

	int ans = 0;

	int curr = x;
	while(curr != start && n > 0) {
		ans += curr;
		curr = (curr * curr)%m;
		n--;
	}

	int cyc = n/sz;
	ans += cyc * sum;

	int rem = n%sz;
	for(int i=0;i<rem;i++) {
		ans += val[i];
	}

	cout << ans << endl;
	return 0;
}
