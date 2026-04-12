#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define ALL(obj)   (obj).begin(),(obj).end()

#define debug(var)  do{std::cout << __LINE__ << "> " << #var << ": ";view(var);}while(0)
template<typename T> void view(T e){std::cout << e << std::endl;}
template<typename T> void view(const std::vector<T>& v){for(const auto& e : v){ std::cout << e << " "; } std::cout << std::endl;}
template<typename T> void view(const std::vector<std::vector<T> >& vv){ for(const auto& v : vv){ view(v); } }

using namespace std;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;

void Main() {
	int N, M; cin >> N >> M;
	vvi Graph(N, vector<int>(N, 0));
	REP(i, M) {
		int a, b;
		cin >> a >> b;
		--a, --b;
		Graph[a][b] = 1;
		Graph[b][a] = 1;
	}
	vector<int> vec(N);
	REP(i, N) vec[i] = i;
	int ans = 0;
	do {
		if (vec[0] != 0) continue;
		bool fail = false;
		REP(i, N - 1) {
			if (Graph[vec[i]][vec[i + 1]] != 1) {
				fail = true;
				break;
			}
		}
		if (!fail) ++ans;
    } while (next_permutation(vec.begin(), vec.end()));
	cout << ans << endl;
}

int main() {
    cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	cout << fixed << setprecision(15);
	Main();
}
