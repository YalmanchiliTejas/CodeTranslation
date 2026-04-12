/*
* Problem link
* 
*/

#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef vector<double> V;
typedef vector<V> VV;
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) FOR(i,0,n)
template<typename T>
inline bool chmax(T &a, T b) {
	bool res = a < b;
	if (res)a = b;
	return res;
}
int main() {
#ifdef INPUT_FROM_FILE
	ifstream cin("sample.in");
	ofstream cout("sample.out");
#endif
	int T;
	cin >> T;
	while (T--) {
		LL money;
		int t,n;
		cin >> money >> t >> n;
		vector<VV> cost(2);
		REP(i, n) {
			LL type;double  a, b;
			cin >> type >> a >> b;
			cost[type].push_back({ a,b });
		}
		LL res=-114514;
		for(auto &it:cost[0]){
			LL mine = money;
			LL other = 0;
			REP(i, t) {
				other += mine*it[0];
				mine -= it[1];
			}
			chmax(res, mine + other);
		}
		for (auto &it : cost[1]) {
			LL mine = money;
			LL other = 0;
			REP(i, t) {
				mine += mine*it[0];
				mine -= it[1];
			}
			chmax(res, mine + other);
		}

		cout << res << endl;



	}
	

	return 0;
}