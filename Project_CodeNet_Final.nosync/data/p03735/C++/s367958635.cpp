#include<iostream>

#include <vector>
#include <list>
#include<stack>
#include<queue>
#include<array>

#include <set>
#include<map>

#include<string>
#include<stdlib.h>

#include<algorithm>
#include <functional>
#include<math.h>

#include<fstream>
#include<iomanip>

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int,int>;

#define FOR(k,m,n) for(ll (k)=(m);(k)<(n);(k)++)
#define REP(i,n) FOR((i),0,(n))
#define WAITING(str) int str;std::cin>>str;
#define DEBUGING(str) cout<<str<<endl

constexpr int INF = (1 << 30);
constexpr ll INFL = (1ll << 60);
constexpr ll MOD = 1000000007;// 10^9+7


//変数
int N;
vector<pair<ll, ll>> xy;






//サブ関数
//入力
void input()
{
	cin >> N;

	ll a, b;
	REP(i, N) {
		cin >> a >> b;
		xy.push_back({ a,b });
	}
}

ll calc_res2(const vector<ll>& minv) {
	ll res = minv.back() - minv.front();
	ll last = minv.back();
	priority_queue<pair<ll, ll>,
		vector<pair<ll,ll>>,
		greater<pair<ll,ll>>> pq;

	REP(i, N) {
		pq.push({ min(xy[i].first,xy[i].second),i });
	}

	bool ignore = true;
	set<int> st;
	REP(i, N) {
		auto best = pq.top(); pq.pop();
		if (st.find(best.second) != st.end()) {
			res = min(res, last - best.first);
			break;
		}
		st.insert(best.second);
		
		if (ignore) {
			ignore = false;
		}
		else {
			res = min(res, last - best.first);
		}
		auto next = max(xy[best.second].first, xy[best.second].second);
		last = max(last, next);
		pq.push({ next,best.second });
	}
	return res;
}

//計算
void calc()
{
	vector<ll>  minv, maxv;
	for (auto p : xy) {
		ll a = p.first;
		ll b = p.second;
		minv.push_back(min(a, b));
		maxv.push_back(max(a, b));
	}
	sort(minv.begin(), minv.end());
	sort(maxv.begin(), maxv.end());

	ll res1 = abs(minv.back() - minv.front())
		* abs(maxv.back() - maxv.front());

	ll tmp = maxv.back() - minv.front();
	ll res2 = calc_res2(minv)*tmp;
	cout << min(res1, res2) << endl;
} 


//出力
void output()
{

}


//デバッグ
void debug()
{
	int N;
	cin>>N;
}


//メイン関数
int main()
{
	input();
	calc();
	output();
	debug();
	
	return 0;
}
