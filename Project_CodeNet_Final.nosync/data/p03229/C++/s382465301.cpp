#include <bits/stdc++.h>
using namespace std;

// vector
template<typename T> ostream& operator<<(ostream& s, const vector<T>& v) {
	int len = v.size();
	for (int i = 0; i < len; ++i) {
		s << v[i]; if (i < len - 1) s << "\t";
	}
	return s;
}
template<typename T> ostream& operator<<(ostream& s, const deque<T>& v) {
	int len = v.size();
	for (int i = 0; i < len; ++i) {
		s << v[i]; if (i < len - 1) s << "\t";
	}
	return s;
}

int main() {
    // ifstream in("input.txt");
    // cin.rdbuf(in.rdbuf());

    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    sort(A.begin(), A.end());
    // cout << A << endl;

    // 差が最大となるのは /\/\/ or \/\/\/ のように大小交互に並ぶ場合
    // 例えば/\/の場合、差の合計は
    // (b-a)+(b-c)+(d-c) = -a+2b-2c+d となる
    
    // 数列と係数をソートしたものの各項の積の和をw型とm型で比較する

    // 係数の数列
    vector<int> cf_m(N);
    vector<int> cf_w(N);

    for (int i = 0; i < N; i++) {
        if (i%2==0) {
            // 偶数番目
            if(i == 0 || i == N-1) {
                cf_m[i] = -1;
                cf_w[i] = +1;
            } else {
                cf_m[i] = -2;
                cf_w[i] = +2;
            }
        } else {
            // 奇数番目
            if (i == N-1) {
                cf_m[i] = +1;
                cf_w[i] = -1;
            } else {
                cf_m[i] = +2;
                cf_w[i] = -2;
            }
        }
    }
    sort(cf_m.begin(), cf_m.end());
    sort(cf_w.begin(), cf_w.end());
    // cout << cf_m << endl;
    // cout << cf_w << endl;

    long sum_m = 0, sum_w = 0;
    for(int i = 0; i < N; i++) {
        sum_m += A[i] * cf_m[i];
        sum_w += A[i] * cf_w[i];
    }
    cout << max(sum_m, sum_w) << endl;
}
