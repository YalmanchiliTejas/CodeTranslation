#include<iostream>
#include<string>
#include<vector>
#include<numeric>
#include<math.h>
#include<algorithm>
#include<iomanip>
#include<list>
#include<bitset>
using namespace std;

/* ---------------------------------------------------------------------- */
// 順列
class Permutation {
	// 公開関数
public:
	// コンストラクタ
	Permutation();
	// デストラクタ
	~Permutation();
	// 順列を計算するメイン関数
	const vector<vector<int>>& calc_main(int N);
	// 内部関数
private:
	// 順列を計算するための再帰関数
	void calc_perm(vector<bool> jdg, vector<int> num);
	// 内部変数
private:
	// 計算した順列を格納するvector配列
	vector<vector<int>> ans;
	// 計算する階乗を示す整数
	int N = 1;
};
/* ---------------------------------------------------------------------- */

// コンストラクタ
Permutation::Permutation() {
	// 答えを格納するメンバ変数のvector配列を初期化
	ans.clear();
}

// デストラクタ
Permutation::~Permutation() {
}

// 順列を計算するメイン関数
const vector<vector<int>>& Permutation::calc_main(int N) {
	// 計算する階乗を示す整数を内部変数に格納
	this->N = N;

	// 順列に含まれているかを確認するbool型のvector配列を宣言
	vector<bool> jdg(this->N, false);

	// 再帰関数を用いて順列を計算
	vector<int> num;
	// 初期化
	num.clear();
	calc_perm(jdg, num);

	// 順列が格納されたvector配列を戻り値として返す
	return ans;
}

// 順列を計算するための再帰関数
void Permutation::calc_perm(vector<bool> jdg, vector<int> num) {
	// すべての整数を使って順列を作成した場合
	if (jdg.end() == find(jdg.begin(), jdg.end(), false)) {
		// 答えを格納
		ans.push_back(num);
	}

	// 整数のループ
	for (size_t i = 1; i <= N; i++) {
		if (jdg[i - 1] == false) {
			vector<int> dnum = num;
			dnum.push_back(i);
			jdg[i - 1] = true;
			calc_perm(jdg, dnum);
			jdg[i - 1] = false;
		}
	}
}

int main() {

	int N, M;
	cin >> N >> M;

	vector<vector<int>> edge(N, vector<int>());

	int a, b;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		a--;
		b--;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}

	Permutation P;
	const vector<vector<int>>& perm = P.calc_main(N - 1);

	int ini = 0;
	bool jdg = true;
	int ans = 0;

	for (int i = 0; i < perm.size(); i++) {
		ini = 0;
		jdg = true;
		for (int j = 0; j < perm[i].size(); j++) {
			if (edge[ini].end() != find(edge[ini].begin(), edge[ini].end(), perm[i][j])) {
				ini = perm[i][j];
			}
			else {
				jdg = false;
				break;
			}
		}
		if (jdg == true) {
			ans += 1;
		}
	}

	cout << ans << endl;

	return 0;
}

