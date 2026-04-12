#define _USE_MATH_DEFINES
#include <iostream>
#include <fstream>
#include<vector>
#include<algorithm>
#include<numeric>
#include<set>
using namespace std;

struct init{
	init(){
		cin.tie(0); ios::sync_with_stdio(false);
	}
}________init;
typedef vector<int> E;
typedef vector<E> Graph;
typedef long long LL;
#define rep(i,n) for (auto i = 0; i < n;i++)
#define range(it,v) for (auto& it : v)
inline bool inner(int l, int v, int r){
	return (l <= v&&v <= r);
}
int main() {
#ifdef INPUT_FROM_FILE
	ifstream cin("sample.in");
	ofstream cout("sample.out");
#endif
	int  N;
	while (cin >> N) {
		LL a, d, M;
		int K;
		cin >> a >> d >> M;
		a -= d;
		vector<int> x(M),y(M),z(M);
		rep(i, M)cin >> x[i] >> y[i] >> z[i];
		cin >> K; K--;
		rep(id, M){
			int i = M - id - 1;
			y[i]--, z[i]--;
			if (x[i] == 0 && inner(y[i], K, z[i])){
				int sz = z[i] - y[i];
				int m = K - y[i];
				K = y[i] + (sz - m);
			}
		}

		LL val = a + d*(K + 1);
		rep(i, M){
			if (inner(y[i], K, z[i])){
				if (x[i] == 0){
					int sz = z[i] - y[i];
					int m = K - y[i];
					K = y[i] + (sz - m);
				}
				if (x[i] == 1){
					val += 1;
				}
				if (x[i] == 2){
					val /= 2;
				}
			}
		}
		cout << val << endl;
	}
	return 0;
}