#include <iostream>
#include <vector>
#include <list>
using namespace std;


//bは大きい順
bool f(vector<int> &b, int n, int num, int begin, int end) {
	//cout << "  " << n << " " << num << " (" << begin << " - " << end << ")" << endl;
	if (begin == end) {
		b[begin] = num;
		return false;
	}
	int centerIdx = (begin + end) / 2;
	if (b[centerIdx] >= num) {//centerIdxの位置はnum以上
		//centerIdxより左には存在しない
		return f(b, n, num, centerIdx + 1, end);
	}
	//それ以外のとき、左に存在する
	/*
	if (b[centerIdx + 1] < num) {//右に存在すると分かったとき、その左端における場合
		b[centerIdx + 1] = num;
		return true;
	}
	*/
	return f(b, n, num, begin, centerIdx);
}

int main() {
	int n; cin >> n;
	vector<int> a(n);
	vector<int> b(n);
	
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		b[i] = -1;
	}
	int color = 1;
	b[0] = a[0];
	for (int i = 1; i < n; i++) {
		/*
		cout << "(";
		for (int j = 0; j < color; j++) {
			if (j != 0) cout << " ";
			cout << b[j];
		}
		cout << ")" << endl;
		*/
		if (b[color - 1] >= a[i]) {
			b[color++] = a[i];
			continue;
		}
		f(b, color, a[i], 0, color);
	}
	cout << color << endl;

	
}