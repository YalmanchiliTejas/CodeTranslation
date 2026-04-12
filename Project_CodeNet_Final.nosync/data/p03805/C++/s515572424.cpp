#include "bits/stdc++.h"
#define REP(i,n) for(int i=0;i< (n);i++)
#define REPR(i, n) for(int i = (n);i >= 0;i--)
#define FOR(i, m, n) for(int i = (m);i < (n);i++)
#define FORR(i, m, n) for(int i = (m);i >= (n);i--)
#define SORT(v, n) std::sort(v, v+n);
#define VSORT(v) std::sort(v.begin(), v.end());
#define VRSORT(v) std::sort(v.rbegin(), v.rend());
#define ll long long
#define pb(a) push_back(a)
#define ALL(obj) (obj).begin(),(obj).end()

using namespace std;

const int INF = 99999999;
const ll LINF = 9999999999999;

typedef pair<int, int> P;
typedef pair<ll, ll> LP;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

ll n, m;
multimap<ll, ll> a;
ll cou = 0;
vector<int> v;

bool findroot(ll key,ll goal) {
	auto range = a.equal_range(key);

		
		// 取得したイテレータの範囲をループで回します。

		for (auto iterator = range.first; iterator != range.second; iterator++)

		{

			// ここで、"key1" をキーに持つキーと値のセットをひとつひとつ処理します。

			auto target = *iterator;
			if (target.second == goal) return true;

		}
		return false;
}

int main() {


		std::ios::sync_with_stdio(false);
		std::cin.tie(0);
	
		
		cin >> n >> m;
		v.resize(n - 1);
		REP(i, m) {
			ll b, c;
			cin >> b >> c;
			a.insert(make_pair(b, c));
			a.insert(make_pair(c, b));
		}
		
		iota(v.begin(), v.end(), 2);       // v に 2, ... N を設定
		do {
			//for (auto x : v) cout << x << " "; cout << "\n";    // v の要素を表示
			//まず、1からv[0]にいくルートがあるか探す
			if (findroot(1, v[0])==false) {
				//なかったら打ち切り
				continue;
			}
			else {
				//打ち切りにはならず、サイズが極端に小さければすでにおｋ
				if (v.size() <= 1) {
					cou++;
				}
			}
			//次にv[0]からv[1]...v[n-2]にまでルートがあるか探す。
			REP(i, n - 2) {
				//もしルートが合ったら
				if (findroot(v[i], v[i + 1])==true) {
					//これがラストならカウントをふやす
					if (i == n - 3) cou++;
				}
				else {
					//なかったら打ち切り
					i=999;
				}
			}
		} while (next_permutation(v.begin(), v.end()));     // 次の順列を生成

		cout << cou << endl;

	return 0;
}