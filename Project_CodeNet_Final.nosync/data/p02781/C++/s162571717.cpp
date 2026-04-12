#include<iostream>
#include<math.h>
#include<algorithm>
#include<stdint.h>
#include<vector>
#include<deque>
#include<stack>
#include<functional>
#include<string>
#include<cstring>
#include<time.h>
#include<array>
#include<iomanip>
#include<list>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<random>
#include<bitset>
#include <queue>
#include <map>


using namespace std;
using ll = long long;
using ull = unsigned long long;
using uint = unsigned int;
using ldouble = long double;


//BDD,ZDD,kdtree, bdtree,bicalc, bolonoy, doloney, tree, chinesemod,segmenttree,daikusutora, saidairyuu, 2bugurahu, heirokenshutu, topologicalsort, kyourenketuseibun

#define REP(i,a,b) for(int i = a; i < b; ++i)
#define PRI(s) cout << s << endl
#define PRIY PRI("Yes")
#define PRIN PRI("No")

//M桁め以下の、０でない数字が１この整数
int count(vector<int> & N, int M) {
	if (M == 0) return 0;
	return N[M] + 9 * (M - 1);
}

int msn0(vector<int>& N, int M) {
	while (N[M] == 0 && M > 0) --M;
	return M;
}

int count2(vector<int>& N, int M) {
	if (M <= 1)return 0;
	ll ans = 0;
	ans += count(N, msn0(N, M - 1));
	ans += 9 * (N[M] - 1) * (M - 1);
	ans += 81 * (M - 1) * (M - 2) / 2;
	return ans;
}

int count3(vector<int>& N, int M) {
	ll ans = 0;
	ans += count2(N, msn0(N, M - 1));
	ans += 81 * (N[M] - 1) * (M - 1) * (M - 2) / 2;
	ans += 81 * 9 * (M - 1) * (M - 2) * (M - 3) / 6;
	return ans;
}

int main() {
	string s;
	int K;
	int M;
	cin >> s >> K;
	M = s.size();
	vector<int> N(M + 1);
	for (int i = 0; i < M; ++i) N[M - i] = s[i] - '0';
	if (M < K) PRI(0);
	else if (K == 1) PRI(count(N, M));
	else if (K == 2) PRI(count2(N, M));
	else PRI(count3(N, M));
	return 0;
}


