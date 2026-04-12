#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <limits>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <functional>

using namespace std;

using ll = long long;
using ui = unsigned int;
const ll MOD = 1000000007;
const ll INF = 9223372036854775807;

//AtCoder Beginner Contest 054-C

// nPn�̏���ɑ΂��ď��������s����
void foreach_permutation(int n, std::function<void(int *)> f) {
	int *indexes = new int[n];
	for (int i = 0; i < n; i++) indexes[i] = i;
	do {
		f(indexes);
	} while (std::next_permutation(indexes, indexes + n));
	delete[] indexes;
}

ll N;
vector<vector<ll>> graph;
ll result;

int main() {
	scanf("%lld", &N);
	ll M;
	scanf("%lld", &M);

	graph.resize(N);

	for (ll i = 0; i < M; i++) {
		ll a;
		scanf("%lld", &a);
		ll b;
		scanf("%lld", &b);
		graph[a - 1].push_back(b - 1);
		graph[b - 1].push_back(a - 1);
	}

	result = 0;

	foreach_permutation(N - 1, [](int *indexes) {
		//indexes[0] ~ indexes[N - 2]

		ll prev = 0;
		bool ok = true;

		for (ll i = 0; i < N - 1; i++) {
			ll next = indexes[i] + 1;

			auto it = find(graph[prev].begin(), graph[prev].end(), next);
			if (it == graph[prev].end()) {
				//no path
				ok = false;
				break;
			}
			prev = next;
		}

		if (ok) {
			result++;
		}
	});

	printf("%lld\n", result);
}


//AtCoder Beginner Contest 126
/*
struct UnionFindTree {
	ll num_node = 0;
	ll num_root = 0;
	vector<ll> parent;
	vector<ll> count;

	UnionFindTree(ll num_node) {
		this->num_node = num_node;
		this->num_root = num_node;
		parent.clear();
		parent.resize(num_node);
		count.clear();
		count.resize(num_node);
		for (ll i = 0; i < num_node; i++) {
			parent[i] = i;
			count[i] = 1;
		}
	}

	ll FindRoot(ll node) {
		vector<ll> found_node;

		while (true) {
			if (parent[node] == node) {
				for (auto index : found_node) {
					parent[index] = node;
				}
				break;
			}
			else {
				found_node.push_back(node);
				node = parent[node];
			}
		}

		return node;
	}

	bool Unite(ll node1, ll node2) {
		ll node1root = FindRoot(node1);
		ll node2root = FindRoot(node2);

		if (node1root == node2root) {
			return false;
		}

		count[node1root] += count[node2root];
		count[node2root] = 0;
		parent[node2root] = node1root;
		this->num_root--;

		return true;
	}

	ll CountNode(ll node) {
		return count[FindRoot(node)];
	}

	ll CountRoot() {
		return this->num_root;
	}
};

int main() {
	ll N;
	scanf("%lld", &N);
	ll M;
	scanf("%lld", &M);

	UnionFindTree uf(N);

	for (ll i = 0; i < M; i++) {
		ll X;
		scanf("%lld", &X);
		ll Y;
		scanf("%lld", &Y);
		ll Z;
		scanf("%lld", &Z);

		uf.Unite(X - 1, Y - 1);
	}
	   
	printf("%lld\n", uf.CountRoot());
}
*/

//AtCoder Beginner Contest 096-D
/*
void recursive_comb(int *indexes, int s, int rest, std::function<void(int *)> f) {
	if (rest == 0) {
		f(indexes);
	}
	else {
		if (s < 0) return;
		recursive_comb(indexes, s - 1, rest, f);
		indexes[rest - 1] = s;
		recursive_comb(indexes, s - 1, rest - 1, f);
	}
}

// nCk�̑g�ݍ��킹�ɑ΂��ď��������s����
void foreach_comb(int n, int k, std::function<void(int *)> f) {
	int *indexes = new int[k];
	recursive_comb(indexes, n - 1, k, f);
	delete[] indexes;
}

bool Prime(ll x) {
	if (x == 1 || x == 2) {
		return true;
	}

	if (x % 2 == 0) {
		return false;
	}

	for (ll i = 3; i <= (ll)std::sqrt(x); i += 2) {
		if (x % i == 0) {
			return false;
		}
	}

	return true;
}

ll A[8] = {
	2, 5, 7, 13, 19, 37, 67, 79
};

bool success;

int main() {
	success = true;
	foreach_comb(8, 5, [](int *indexes) {
		//std::cout << indexes[0] << ',' << indexes[1] << ',' << indexes[2] << ',' << indexes[3] << ',' << indexes[4] << std::endl;
		ll sum = A[indexes[0]] + A[indexes[1]] + A[indexes[2]] + A[indexes[3]] + A[indexes[4]];
		if (Prime(sum) == true) {
			success = false;
		}
	});

	printf("%d", success ? 1 : 0);
}
*/


//AtCoder Regular Contest 062
/*
int main() {
	char s[101010];
	scanf("%s", s);
	ll len = strlen(s);

	ll result = 0;
	for (ll i = 0; i < len; i++) {
		if (i % 2 == 0) {
			//g
			if (s[i] == 'p') {
				result--;
			}
		}
		else {
			//p
			if (s[i] == 'g') {
				result++;
			}
		}
	}

	printf("%lld\n", result);
}
*/

//diverta 2019 Programming Contest 2 - C
/*
struct LLPair {
	ll a = 0;
	ll b = 0;
	LLPair() {}
	LLPair(ll a, ll b) {
		this->a = a;
		this->b = b;
	}
};

int main() {
	ll N;
	scanf("%lld", &N);
	vector<ll> A(N);
	for (ll i = 0; i < N; i++) {
		scanf("%lld", &A[i]);
	}

	std::sort(A.begin(), A.end(), std::greater<ll>());

	if (A.size() == 2) {
		printf("%lld\n", A[0] - A[1]);
		printf("%lld %lld\n", A[0], A[1]);
		return 0;
	}

	vector<LLPair> result;
	ll hold = A[N - 1];
	bool sw = false;
	for (ll i = 1; i < N - 1; i++) {
		if (A[i] >= 0) {
			result.push_back(LLPair(hold, A[i]));
			hold = hold - A[i];
		}
		else {
			if (sw == false) {
				result.push_back(LLPair(A[0], hold));
				hold = A[0] - hold;
				sw = true;
			}

			result.push_back(LLPair(hold, A[i]));
			hold = hold - A[i];
		}
	}

	if (sw == false) {
		result.push_back(LLPair(A[0], hold));
		hold = A[0] - hold;
	}

	printf("%lld\n", hold);
	for (auto item : result) {
		printf("%lld %lld\n", item.a, item.b);
	}
}
*/

//SoundHound Inc. Programming Contest 2018 -Masters Tournament- C
/*
int main() {
	ll n;
	scanf("%lld", &n);
	ll m;
	scanf("%lld", &m);
	ll d;
	scanf("%lld", &d);

	ll x = d == 0 ? n : 2 * (n - d);

	printf("%0.10f\n", (double)x * (double)(m - 1) / (double)n / (double)n);
}
*/

//AtCoder Beginner Contest 089-D
/*
struct LLPair {
	ll L = 0;
	ll R = 0;
};

struct LLPoint {
	ll x = 0;
	ll y = 0;
	LLPoint() {}
	LLPoint(ll x, ll y) {
		this->x = x;
		this->y = y;
	}
};

int main() {
	ll H;
	scanf("%lld", &H);
	ll W;
	scanf("%lld", &W);
	ll D;
	scanf("%lld", &D);

	vector<vector<ll>> A(H, vector<ll>(W, 0));
	for (ll j = 0; j < H; j++) {
		for (ll i = 0; i < W; i++) {
			scanf("%lld", &A[j][i]);
		}
	}

	ll Q;
	scanf("%lld", &Q);

	vector<LLPair> query(Q);
	for (ll i = 0; i < Q; i++) {
		scanf("%lld %lld", &query[i].L, &query[i].R);
	}

	vector<LLPoint> point(H * W);
	for (ll j = 0; j < H; j++) {
		for (ll i = 0; i < W; i++) {
			point[A[j][i] - 1] = LLPoint(i, j);
		}
	}

	vector<ll> integral(H * W, 0);
	for (ll i = 0; i < D; i++) {
		for (ll j = i; j < H * W; j += D) {
			ll next = j + D;
			if (next >= H * W) {
				break;
			}

			integral[next] = integral[j] + abs(point[j].x - point[next].x) + abs(point[j].y - point[next].y);
		}
	}

	for (auto item : query) {
		printf("%lld\n", integral[item.R - 1] - integral[item.L - 1]);
	}
}
*/

//AtCoder Regular Contest 097-D
/*
struct LLPair {
	ll a = 0;
	ll b = 0;
};

struct UnionFindTree {
	ll num_node = 0;
	vector<ll> parent;
	vector<ll> count;

	UnionFindTree(ll num_node) {
		this->num_node = num_node;
		parent.clear();
		parent.resize(num_node);
		count.clear();
		count.resize(num_node);
		for (ll i = 0; i < num_node; i++) {
			parent[i] = i;
			count[i] = 1;
		}
	}

	ll FindRoot(ll node) {
		vector<ll> found_node;

		while (true) {
			if (parent[node] == node) {
				for (auto index : found_node) {
					parent[index] = node;
				}
				break;
			}
			else {
				found_node.push_back(node);
				node = parent[node];
			}
		}

		return node;
	}

	bool Unite(ll node1, ll node2) {
		ll node1root = FindRoot(node1);
		ll node2root = FindRoot(node2);

		if (node1root == node2root) {
			return false;
		}

		count[node1root] += count[node2root];
		count[node2root] = 0;
		parent[node2root] = node1root;

		return true;
	}

	ll Count(ll node) {
		return count[FindRoot(node)];
	}
};

int main() {
	ll N;
	scanf("%lld", &N);
	ll M;
	scanf("%lld", &M);
	vector<ll> p(N);
	for (ll i = 0; i < N; i++) {
		scanf("%lld", &p[i]);
	}
	vector<LLPair> sw(M);
	for (ll i = 0; i < M; i++) {
		scanf("%lld %lld", &sw[i].a, &sw[i].b);
	}

	UnionFindTree uf(N);

	for (ll i = 0; i < M; i++) {
		uf.Unite(sw[i].a - 1, sw[i].b - 1);
	}

	ll result = 0;

	for (ll i = 0; i < N; i++) {
		if (uf.FindRoot(p[i] - 1) == uf.FindRoot(i)) {
			result++;
		}		
	}

	printf("%lld\n", result);
}
*/

//AtCoder Grand Contest 019-B
/*
//TLE
int main() {
	char A[202020];
	scanf("%s", A);
	ll len = strlen(A);

	ll result = 1;

	for (ll i = 0; i < len * 2ll - 1ll; i++) { //0:0������ 1:0�����ڂ�1�����ڂ̊� 2:1������
		if (i % 2 == 0) {
			ll index = i / 2;
			ll searchMax = min(index, len - 1 - index);

			//i/2�����ڂ𒆐S
			ll count = 0;
			for (ll j = 1; j <= searchMax; j++) {
				if (A[index - j] != A[index + j]) {
					count++;
				}
			}

			result += count;
		}
		else {
			ll index = i / 2;
			ll searchMax = min(index + 1, len - 1 - index);

			//i/2�����ڂ̉E�𒆐S
			ll count = 0;
			for (ll j = 0; j < searchMax; j++) {
				if (A[index - j] != A[index + j + 1]) {
					count++;
				}
			}

			result += count;
		}
	}

	printf("%lld\n", result);
}
*/