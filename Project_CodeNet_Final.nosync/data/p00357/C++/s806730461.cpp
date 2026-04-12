#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<math.h>
#include<iomanip>
#include<set>
#include<numeric>
#include<cstring>
#include<cstdio>
#include<functional>
#include<bitset>
#include<limits.h>
#include<cassert>
#include<iterator>
#include<complex>
#include<stack>
#include<sstream>
#include<iterator>
#include<list>

using namespace std;

typedef  long long int lint;

#define rep(i, n) for (lint i = 0; i < n; i++)
#define sort(v) sort((v).begin(), (v).end())
#define reverse(v) reverse((v).begin(), (v).end())
#define upper(v,hoge) upper_bound(v.begin(),v.end(),hoge)
#define lower(v,hoge) lower_bound(v.begin(),v.end(),hoge)
#define llower(v,hoge) *lower_bound(v.begin(), v.end(), hoge)
#define lupper(v,hoge) *upper_bound(v.begin(), v.end(), hoge)
#define mp make_pair
#define IP pair<int,int>
#define enld endl

int main() {
	lint N;
	cin >> N;
	vector<lint>D(N);
	rep(i, N) {
		cin >> D[i];
	}
	lint M = 0;//行ける最大値
	rep(i, N) {
		if (i <= M) {
			M = max(M, i + D[i] / 10);
		}
	}
	bool yes1 = false;
	if (M >= N - 1) {
		yes1 = true;
	}
	reverse(D);
	M = 0;
	rep(i, N) {
		if (i <= M) {
			M = max(M, i + D[i] / 10);
		}
	}
	bool yes2 = false;
	if (M >= N - 1) {
		yes2 = true;
	}
	if (yes1 && yes2) {
		cout << "yes" << endl;
	}
	else {
		cout << "no" << endl;
	}
}
