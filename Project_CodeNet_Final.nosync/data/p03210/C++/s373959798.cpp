
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <functional>
#include <limits.h>
#include <set>
#include <map>
#include <tuple>
using namespace std;

#define ll long long
#define ull unsigned long long
#define rep(i,N) for (int i=0;i<N;i++)
#define loop(i,N,M) for(int i=N;i<M;i++)
#define MAX(v) *max_element(v.begin(),v.end())
#define MIN(v) *min_element(v.begin(),v.end())
#define SORTL2S(type,v) sort(v.begin(),v.end(),greater<type>())
#define SORTS2L(type,v) sort(v.begin(),v.end())
#define SORTMF(v,func) sort(v.begin(),v.end(),func)

//変数
ll X;

//解法
void solve() {

	if (X == 7 || X == 5 || X == 3) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}

	return;
}

int main() {
	//入力

	cin >> X;

	solve();
	cout << endl;
	return 0;
}