#include <iostream>
#include <algorithm>
#include <string>
#include <limits.h>
#include <vector>
#include <numeric>
#include<random>



using namespace std;

vector<pair<long long int, long long int>> getPrimeElements(long long int num) {

	long long int firstnum = num;

	vector<pair<long long int, long long int>> result;
	pair<long long int, long long int> wk;

	if (num % 2 == 0) {
		wk.first = 2;
		wk.second = 0;
		while (num % 2 == 0) {
			wk.second++;
			num /= 2;
		}

		result.push_back(wk);
	}

	long long int waru = 3;

	while (true) {

		if (num % waru == 0) {
			wk.first = waru;
			wk.second = 0;
			while (num % waru == 0) {
				wk.second++;
				num /= waru;
			}

			result.push_back(wk);
		}
		waru += 2;

		if (waru * waru > num) break;

	}

	if (num != 1) {
		wk.first = num;
		wk.second = 1;
		result.push_back(wk);

	}

	return result;
}


int getKeta(int num) {

	if (num == 0)return 1;

	int res = 0;

	while (num > 0) {
		num /= 10;
		res++;
	}

	return res;
}

vector<int> bunkai(int num) {

	string str = to_string(num);
	vector<int> res;

	for (int i = 0; i < str.size(); i++) {
		int a = str[i] - '0';
		res.push_back(a);
	}

	return res;

}

struct SegmentTree {
private:
	int n;
	vector<long long int> node;
	int TANNI;

public:

	long long int Func(long long int a, long long int b) {
		return (a + b);
	}



	
	//元配列ｖをセグメント木で表現する。
	SegmentTree(vector<long long int> v, int tanni) {
		//最下段のノード数は元配列のサイズ以上になる最小の2冪　-> これを n とおく
        // セグメント木全体で必要なノード数は 2n-1 個である
		int sz = v.size();
		n = 1; while (n < sz) n *= 2;

		TANNI = tanni;
		node.resize(2 * n - 1, TANNI);

		//最下段に値を入れた後に、下の段から順番に値を入れる。
		//値を入れるには、自分の子の２値を参照すればよい。
		for (int i = 0; i < sz; i++)node[i + n - 1] = v[i];
		for (int i = n - 2; i >= 0; i--)node[i] = Func(node[2 * i + 1], node[2 * i + 2]);

	}

	void update(int x, long long int val) {
		//最下段のノードにアクセスする。葉の要素がｎ個。葉以外の要素がｎ－１なので、ｎ－１を足せばよい。
		x += (n - 1);

		//最下段のノードを更新したら、あとは親に上って更新していく。
		node[x] = val;
		while (x > 0) {
			x = (x - 1) / 2;
			node[x] = Func(node[2 * x + 1], node[2 * x + 2]);
		}
	}

	//[a, b)の半閉区間内では答えがどうなるか。
	//k := 自分がいるノードのインデックス
	//対象区間は[l,r)にあたる。
	long long int getAns(int a, int b, int k = 0, int l = 0, int r = -1) {

		//最初に呼び出された時の対象区間は[0,n)
		if (r < 0) r = n;

		//要求区間と対象区間が交わらない　⇒単位元を返す
		if (r <= a || b <= l) return TANNI;
		
		//要求区間が対象区間を完全に被覆　⇒対象区間を答えの計算に使う。
		if (a <= l && r <= b)return node[k];

		//要求区間が対象区間の一部を被覆する場合　⇒子の探索を行う。
		//左の子をvl, 右側の子をvrとしている。
		//新しい対象区間は、現在の対象区間を半分に割ったもの。
		int vl = getAns(a, b, 2 * k + 1, l, (l + r) / 2);
		int vr = getAns(a, b, 2 * k + 2, (l + r) / 2, r);

		return Func(vl, vr);
	}
};





struct solve {

private:

	int k;
	int cnt = 0;

public:

	solve(int num) {
		k = num;
	}

	string ans = "";
	void runrun(int keta, string now) {

		if (keta == now.size()) {
			cnt++;

			if (cnt == k) {
				ans = now;
				return;
			}

			return;
		}

		if (ans.size() != 0)return;
		

		int c = now[now.size() - 1] - '0';

		if (c != 0)runrun(keta, now + to_string(c - 1));
		runrun(keta, now + to_string(c));
		if (c != 9)runrun(keta, now + to_string(c + 1));

		return;
	}


};


int main()
{
	
	int x;
	cin >> x;
	
	if (x >= 30) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}

	return 0;


}


