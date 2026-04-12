//#include <stdio.h>
//#include <iostream>
//#include <math.h>
//#include <numeric>
//#include <vector>
//#include <map>
//#include <functional>
//#include <stdio.h>
//#include <array>
//#include <algorithm>
//#include <string>
//#include <assert.h>
//#include <stdio.h>
//#include <queue>
//#include<iomanip>
//using namespace std;
//
//
//using namespace std;
////
////#define N (1<<17) 
////// update(l,r,v) := [l,r]の区間に対してvを一様に足す. k,a,bは飾り
////
////struct NODE{
////	int sum;//更新された値. この値を参照する時は評価が完全に完了しているようにする.
////	int lazy;	//遅延されている値を保存している
////	NODE(){
////		sum = lazy = 0;
////	}
////};
////
////NODE seg[2 * N];
////
////// inlineつけないと大変なことになるよ!(遅い)
////inline void lazy_evaluate_node(int k, int a, int b){
////	seg[k].sum +=seg[k].lazy;
////	if (k < N){ // 2*k(左の子番号) < 2*N (節点の数) のイメージで. 末端ノードじゃなきゃ伝搬するのと等価.
////		seg[2 * k].lazy += seg[k].lazy;	//次は君が伝搬してね☆って感じ.
////		seg[2 * k + 1].lazy += seg[k].lazy;
////	}
////	seg[k].lazy = 0;
////}
////
////inline void update_node(int k){ // kの子が既に評価されていることが前提. 末端以外のときしか呼び出さないような位置に書くのでif文要らない.
////	seg[k].sum = min(seg[2 * k].sum , seg[2 * k + 1].sum);
////}
////
////// update(l,r,v) := [l,r]を更新する. 区間は1-indexed.
////void update(int l, int r, int v, int k = 1, int a = 1, int b = N){
////	lazy_evaluate_node(k, a, b); 	// とりあえず辿ったノードは都合がいいので伝搬しとけ精神.
////
////	if (b < l || r < a) //[a,b]と[l,r]が交差している場合
////		return;
////	if (l <= a && b <= r){ // [l,r]が[a,b]を完全に含んでいる場合
////		seg[k].lazy += v;
////		lazy_evaluate_node(k, a, b); //一回遅延評価しとかないと都合悪いので.
////		return;
////	}
////
////	int m = (a + b) / 2;
////	update(l, r, v, 2 * k, a, m);
////	update(l, r, v, 2 * k + 1, m + 1, b);
////	update_node(k);
////}
////
////// get(l,r) := [l,r]に対するクエリの答えを得る. 区間は1-indexed.
////int get(int l, int r, int k = 1, int a = 1, int b = N){
////	lazy_evaluate_node(k, a, b); // とりあえず辿ったノードは都合がいいので伝搬しとけ精神.
////
////	if (b < l || r < a) //[a,b]と[l,r]が交差している場合
////		return 0;
////
////	if (l <= a && b <= r){ // [l,r]が[a,b]を完全に含んでいる場合
////		return seg[k].sum;
////	}
////
////	int m = (a + b) / 2;
////	int vl = get(l, r, 2 * k, a, m);
////	int vr = get(l, r, 2 * k + 1, m + 1, b);
////	update_node(k);
////	return min(vl , vr);
////}
//
//
//int main() {
//	//int n;
//	//cin >> n;
//	//vector<int> aa(n);
//	//vector<pair<int,int>>aaa;
//	//for (int i = 0; i < n; ++i){
//	//	int a, b;
//	//	cin >> a >> b;
//	//	aaa.push_back(make_pair(a, b)); 
//	//	aa[a]++;
//	//	aa[b]--;
//	//}
//	//vector<int> ans;
//	//ans.push_back(aa[0]);
//	//int amin=99999999;
//	//for(int i=0;i<n;++i){
//	//	ans.push_back(ans[i] + aa[i]);
//	//}
//
//	//RMQ r;
//	//r.init(65536);
//	//for (int i = 0; i < 65536;++i){
//	//	r.update(i, ans[i]);
//	//}
//
//	//cout << r.query(0, 7) << endl; //1
//	//cout << r.query(3, 6) << endl; //2
//	//cout << r.query(1, 5) << endl; //1
//	//cout << r.query(5, 7) << endl; //4
//	//return 0;
//
//	vector<long long int>times;
//	for (int i = 0; i < 7; ++i){
//		long long int c;
//		cin >> c;
//		times.push_back(c);
//	}
//	if (times[0] == 0)cout << "YES" << endl;
//	else{
//		times[0]--;
//	}
//
//	{
//		vector<long long int> atimes(times);
//		while (1){
//			auto zero_it = find(atimes.begin(), atimes.end(), 0);
//			if (zero_it != atimes.end()){//5 3 2 0 4 4 2 
//				const int num = zero_it - atimes.begin();
//				int from = num;
//				while (1){
//					from = (from + 1) % 7;
//					if (from == num)break;
//					int to = (from + 1) % 7;
//					if (atimes[from] != 0 && atimes[to] == 0){
//						break;
//					}
//					if (atimes[from] > atimes[to]){
//						break;
//					}
//					long long int amin = min(atimes[from], atimes[to]);
//					atimes[from] -= amin;
//					atimes[to] -= amin;
//					if (atimes[from] == 0 && atimes[to] == 0){
//						break;
//					}
//				}
//				if (all_of(atimes.begin(), atimes.end(), [](const int aaa){return aaa == 0; })){
//					cout << "YES" << endl;
//					return 0;
//				}
//				else{
//					break;
//				}
//			}
//			else{
//				long long int aamin = atimes[0];
//				for (int i = 0; i < 7; ++i){
//					aamin = min(aamin, atimes[i]);
//				}
//				for (int i = 0; i < 7; ++i){
//					atimes[i] -= aamin;
//				}
//			}
//		}
//	}
//	{
//		vector<long long int> btimes(times);
//		for (int i = 0; i < 7; ++i){//times[i]のまえがあいだになる
//			btimes = times;
//			int from = (i + 6) % 7;
//			while (1){
//				from = (from + 1) % 7;
//				if (from == (i + 6) % 7)break;
//				int to = (from + 1) % 7;
//				if (btimes[from] != 0 && btimes[to] == 0){
//					break;
//				}
//				if (btimes[from] > btimes[to]){
//					break;
//				}
//				long long int amin = min(btimes[from], btimes[to]);
//				btimes[from] -= amin;
//				btimes[to] -= amin;
//				if (btimes[from] == 0 && btimes[to] == 0){
//					break;
//				}
//			}
//			if (all_of(btimes.begin(), btimes.end(), [=](int a){return a == 0; })){
//				cout << "YES" << endl;
//				return 0;
//			}
//			else{
//				continue;
//			}
//		}
//	}
//	cout << "NO" << endl;
//	return 0;
//}
////3 4 4 4 4 4 4

#include<stdio.h>
#include <iostream>
#include <math.h>
#include <numeric>
#include <vector>
#include <map>
#include <functional>
#include <stdio.h>
#include <array>
#include <algorithm>
#include <string>
#include <assert.h>
#include <stdio.h>
#include <queue>
#include<iomanip>
#include<bitset>
#include<stack>
using namespace std;

//7:10
//
//#define REP(i,n) for(int i=0;i<(int)n;++i)
//#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
//#define ALL(c) (c).begin(), (c).end()
//
//typedef int Weight;
//struct Edge {
//	int src, dst;
//	Weight weight;
//	Edge(int src, int dst, Weight weight) :
//		src(src), dst(dst), weight(weight) { }
//};
//bool operator < (const Edge &e, const Edge &f) {
//	return e.weight != f.weight ? e.weight > f.weight : // !!INVERSE!!
//	e.src != f.src ? e.src < f.src : e.dst < f.dst;
//}
//typedef vector<Edge> Edges;
//typedef vector<Edges> Graph;
//
//typedef vector<Weight> Array;
//typedef vector<Array> Matrix;
//
//#define RESIDUE(s,t) (capacity[s][t]-flow[s][t])
//Weight maximumFlow(const Graph &g, int s, int t) {
//	int n = g.size();
//	Matrix flow(n, Array(n)), capacity(n, Array(n));
//	REP(u, n) for (auto e = g[u].begin(); e != g[u].end();++e)capacity[e->src][e->dst] += e->weight;
//
//	Weight total = 0;
//	while (1) {
//		queue<int> Q; Q.push(s);
//		vector<int> prev(n, -1); prev[s] = s;
//		while (!Q.empty() && prev[t] < 0) {
//			int u = Q.front(); Q.pop();
//			for (auto e = g[u].begin(); e != g[u].end(); ++e) if (prev[e->dst] < 0 && RESIDUE(u, e->dst) > 0) {
//				prev[e->dst] = u;
//				Q.push(e->dst);
//			}
//		}
//		if (prev[t] < 0) return total; // prev[x] == -1 <=> t-side
//		Weight inc = 999999999;
//		for (int j = t; prev[j] != j; j = prev[j])
//			inc = min(inc, RESIDUE(prev[j], j));
//		for (int j = t; prev[j] != j; j = prev[j])
//			flow[prev[j]][j] += inc, flow[j][prev[j]] -= inc;
//		total += inc;
//	}
//	return total;
//}
#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define ALL(x) (x).begin(),(x).end()


const int mod = 1000000007;

struct Mod {
	long long int num;
	Mod() : num(0) { ; }
	Mod(long long int n) : num((n % mod + mod) % mod) { ; }
	operator long long int() { return num; }
};

Mod operator+(Mod a, Mod b) { return Mod((a.num + b.num) % mod); }
Mod operator-(Mod a, Mod b) { return Mod((mod + a.num - b.num) % mod); }
Mod operator*(Mod a, Mod b) { return Mod(((long long)a.num * b.num) % mod); }
Mod operator+=(Mod &a, Mod b) { return a = a + b; }
Mod operator-=(Mod &a, Mod b) { return a = a - b; }
Mod operator*=(Mod &a, Mod b) { return a = a * b; }
Mod operator^(Mod a, int n) {
	if (n == 0) return Mod(1);
	Mod res = (a * a) ^ (n / 2);
	if (n % 2) res = res * a;
	return res;
}
Mod inv(Mod a) { return a ^ (mod - 2); }
Mod operator/(Mod a, Mod b) { return a * inv(b); }

#define MAX_N 1024000

Mod fact[MAX_N], factinv[MAX_N];
void init() {
	fact[0] = Mod(1); factinv[0] = 1;
	REP(i, MAX_N - 1) {
		fact[i + 1] = fact[i] * Mod(i + 1);
		factinv[i + 1] = factinv[i] / Mod(i + 1);
	}
}
Mod comb(int a, int b) {
	return fact[a] * factinv[b] * factinv[a - b];
}

long long int memo[20];//nけた

long long int powint(long long int a, int b){
	if (b == 0)return 1;
	if (b == 1)return a;
	else{
		long long int ans = 1;
		long long int c = powint(a, b / 2);
		ans *= c*c;
		ans *= (b % 2) ? a : 1;
		return ans;
	}

}


int backnum[100000][20];

struct Node{
	Node(int aid):children(),ancs(){
		id=(aid);
		for (int i = 0; i < 20; ++i){
			ancs[i] = -1;
		}
	}
	int id;
	vector<int>children;
	array<int, 20>ancs;
};

int main()
{
	string s;
	cin >> s;
	vector<int>nums;
	vector<int>fun;
	nums.push_back(s[0]-48);
	for (int i = 0; i < (s.size()-1)/2; ++i){
		if (s[2 * i + 1] == '*'){
			fun.push_back(0);
		}
		else if (s[2 * i + 1] == '+'){
			fun.push_back(1);
		}
		else{
			assert(false);
		}
		nums.push_back(s[2 * i + 2]-48);
	}
	int aaa;
	cin >> aaa;

	bool lrok;
	//lefttoright
	{
		long long int ans = nums[0];
		for (int i = 1; i < nums.size();++i){
			if (fun[i - 1])ans += nums[i];
			else{
				ans *= nums[i];
			}
		}
		lrok = (ans == aaa);
	}
	
	bool seok;
	//iiyatu
	{
		while (1){
			auto it(find(fun.begin(), fun.end(), 0));
			if (it == fun.end())break;
			nums[(it - fun.begin())] *= nums[(it - fun.begin()) + 1];
			nums.erase(nums.begin() + (it - fun.begin()) + 1);
			fun.erase(it);
		}

		long long int ans = nums[0];
		for (int i = 1; i < nums.size();++i){
			if (fun[i - 1])ans += nums[i];
			else{
				ans *= nums[i];
			}
		}
		seok = (ans == aaa);
	}
	string k;
	if (lrok){
		if (seok){
			k = "U";
		}
		else{
			k = "L";
		}
	}
	else{
		if (seok){
			k = "M";
		}
		else{
			k = "I";
		}
	}

	cout << k << endl;

	return 0;
}