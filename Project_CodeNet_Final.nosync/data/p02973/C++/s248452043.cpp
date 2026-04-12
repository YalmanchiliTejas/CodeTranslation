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


//AtCoder Beginner Contest 134-E
int main() {
	ll N;
	scanf("%lld", &N);
	vector<ll> A(N);
	for (ll i = 0; i < N; i++) {
		scanf("%lld", &A[i]);
	}

	//priority_queue<ll, vector<ll>, greater<ll>> pq;
	multiset<ll> ms;

	ll result = 0;

	for (ll i = 0; i < N; i++) {
		//for (auto it = ms.begin(); it != ms.end(); it++) {
		//	printf("%lld ", *it);
		//}
		//printf("\n");

		if (ms.empty()) {
			//printf("empty\n");
			result++;
			ms.insert(A[i]);
		}
		else {
			auto it = ms.lower_bound(A[i]);
			if (it == ms.begin()) {
				//�����̐��l�͂Ȃ�
				//printf("found: begin - 1\n");
				ms.insert(A[i]);
				result++;
			}
			else {
				it--;
				//printf("found: %lld\n", *it);
				ms.erase(it);
				ms.insert(A[i]);
			}
		}
	}

	printf("%lld\n", result);
}


//AtCoder Beginner Contest 136-E
/*
vector<ll> Divisor(ll n) {
	vector<ll> ret;
	for (ll i = 1; i * i <= n; i++) {
		if (n % i == 0) {
			ret.push_back(i);
			if (i * i != n) {
				ret.push_back(n / i);
			}
		}
	}
	std::sort(ret.begin(), ret.end());
	return (ret);
}

int main() {
	ll N;
	scanf("%lld", &N);
	ll K;
	scanf("%lld", &K);
	vector<ll> A(N);
	for (ll i = 0; i < N; i++) {
		scanf("%lld", &A[i]);
	}

	ll sumAll = 0;
	for (ll i = 0; i < N; i++) {
		sumAll += A[i];
	}

	auto list = Divisor(sumAll);

	ll result = 1;

	for (auto val : list) {
		ll sum = 0;
		vector<ll> mod;
		for (ll i = 0; i < N; i++) {
			ll m = A[i] % val;
			if(m > 0)

			if (m <= val / 2) {
				mod.push_back(m);
				sum += m;
			}
			else {
				mod.push_back(m - val);
				sum += m - val;
			}
		}

		if (sum < 0) {
			std::sort(mod.begin(), mod.end());
			for (ll i = 0; i < mod.size(); i++) {
				mod[i] += val;
				sum += val;
				if (sum == 0) {
					break;
				}
			}
		}
		else if(sum > 0){
			std::sort(mod.begin(), mod.end(), std::greater<ll>());
			for (ll i = 0; i < mod.size(); i++) {
				mod[i] -= val;
				sum -= val;
				if (sum == 0) {
					break;
				}
			}
		}

		ll dbl = 0;
		for (auto m : mod) {
			dbl += abs(m);
		}

		if (dbl / 2 <= K) {
			result = val;
		}
	}

	printf("%lld\n", result);
}
*/

//AtCoder Grand Contest 024-C
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

	ll height = 0;
	ll last = 0;
	ll result = 0;
	queue<LLPair> lastQ;

	for (ll i = N - 1; i >= 0; i--) {
		height--;
		if (height < 0) {
			height = 0;
		}

		//last�̍X�V
		if (lastQ.empty() == false) {
			LLPair p = lastQ.front();
			if (p.a - i == p.b) {
				lastQ.pop();
				last--;
			}
		}

		result += last;

		if (A[i] < height) {
			result = -1;
			break;
		}

		if (A[i] > height) {
			result++;
			height = A[i];

			//last�̍X�V
			lastQ.push(LLPair(i, height));
			last++;
		}

	}

	if (height > 0) {
		result = -1;
	}

	printf("%lld\n", result);
}
*/

//AtCoder Regular Contest 092-C
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
	vector<LLPair> red(N);
	for (ll i = 0; i < N; i++) {
		scanf("%lld %lld", &red[i].a, &red[i].b);
	}
	vector<LLPair> blue(N);
	for (ll i = 0; i < N; i++) {
		scanf("%lld %lld", &blue[i].a, &blue[i].b);
	}

	std::sort(blue.begin(), blue.end(), [](const LLPair &a, const LLPair &b) {
		return a.a < b.a;
	});

	ll result = 0;
	vector<bool> redFinish(N, false);
	for (auto item : blue) {
		ll maxY = -1;
		ll hold = -1;

		for (ll i = 0; i < N; i++) {
			if (redFinish[i] == true) {
				continue;
			}

			if (red[i].a >= item.a) {
				continue;
			}

			if (red[i].b >= item.b) {
				continue;
			}

			if (red[i].b > maxY) {
				maxY = red[i].b;
				hold = i;
			}
		}

		if (hold >= 0) {
			redFinish[hold] = true;
			result++;
		}
	}

	printf("%lld\n", result);
}
*/

//AtCoder Beginner Contest 106-D
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
	ll M;
	scanf("%lld", &M);
	ll Q;
	scanf("%lld", &Q);
	vector<LLPair> lr(M);
	for (ll i = 0; i < M; i++) {
		scanf("%lld %lld", &lr[i].a, &lr[i].b);
	}
	vector<LLPair> query(Q);
	for (ll i = 0; i < Q; i++) {
		scanf("%lld %lld", &query[i].a, &query[i].b);
	}

	vector<vector<ll>> arr(N + 1, vector<ll>(0));
	for (ll i = 0; i < M; i++) {
		arr[lr[i].a].push_back(lr[i].b - lr[i].a);
	}
	for (ll i = 1; i <= N; i++) {
		std::sort(arr[i].begin(), arr[i].end());
	}

	for (ll i = 0; i < Q; i++) {
		ll result = 0;

		for (ll j = query[i].a; j <= query[i].b; j++) {
			ll len = query[i].b - j;
			auto it = std::upper_bound(arr[j].begin(), arr[j].end(), len);
			result += it - arr[j].begin();
		}

		printf("%lld\n", result);
	}
}
*/

//AtCoder Regular Contest 092-C
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
	vector<LLPair> red(N);
	for (ll i = 0; i < N; i++) {
		scanf("%lld %lld", &red[i].a, &red[i].b);
	}
	vector<LLPair> blue(N);
	for (ll i = 0; i < N; i++) {
		scanf("%lld %lld", &blue[i].a, &blue[i].b);
	}

	vector<vector<ll>> r2b(N, vector<ll>(0));
	vector<vector<ll>> b2r(N, vector<ll>(0));
	for (ll i = 0; i < N; i++) {
		for (ll j = 0; j < N; j++) {
			if (red[i].a < blue[j].a && red[i].b < blue[j].b)
			{
				r2b[i].push_back(j);
				b2r[j].push_back(i);
			}
		}
	}

	ll result = 0;

	while (true) {
		ll minCount = INF;
		bool redSelect = true;
		ll hold = -1;

		for (ll i = 0; i < N; i++) {
			if (r2b[i].size() > 0) {
				if ((ll)r2b[i].size() < minCount)
				{
					minCount = (ll)r2b[i].size();
					hold = i;
					if (minCount == 1) {
						break;
					}
				}
			}
		}

		if (minCount > 1ll) {
			for (ll i = 0; i < N; i++) {
				if (b2r[i].size() > 0) {
					if ((ll)b2r[i].size() < minCount)
					{
						minCount = (ll)b2r[i].size();
						redSelect = false;
						hold = i;
						if (minCount == 1) {
							break;
						}
					}
				}
			}
		}

		if (hold < 0) {
			break;
		}

		if (redSelect) {
			ll blueIndex = -1;
			ll maxReverse = 0;

			for (auto index : r2b[hold]) {
				if ((ll)b2r[index].size() > maxReverse) {
					maxReverse = (ll)b2r[index].size();
					blueIndex = index;
				}
			}

			r2b[hold].clear();
			for (ll i = 0; i < N; i++) {
				auto f = find(r2b[i].begin(), r2b[i].end(), blueIndex);
				if (f != r2b[i].end()) {
					r2b[i].erase(f);
				}
			}

			b2r[blueIndex].clear();
			for (ll i = 0; i < N; i++) {
				auto f = find(b2r[i].begin(), b2r[i].end(), hold);
				if (f != b2r[i].end()) {
					b2r[i].erase(f);
				}
			}

			result++;
		}
		else {
			ll redIndex = -1;
			ll maxReverse = 0;

			for (auto index : b2r[hold]) {
				if ((ll)r2b[index].size() > maxReverse) {
					maxReverse = (ll)r2b[index].size();
					redIndex = index;
				}
			}

			b2r[hold].clear();
			for (ll i = 0; i < N; i++) {
				auto f = find(b2r[i].begin(), b2r[i].end(), redIndex);
				if (f != b2r[i].end()) {
					b2r[i].erase(f);
				}
			}

			r2b[redIndex].clear();
			for (ll i = 0; i < N; i++) {
				auto f = find(r2b[i].begin(), r2b[i].end(), hold);
				if (f != r2b[i].end()) {
					r2b[i].erase(f);
				}
			}

			result++;
		}
	}

	printf("%lld\n", result);
}
*/

//AtCoder Beginner Contest 096-D
/*
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

int main() {
	ll N;
	scanf("%lld", &N);

	ll count = 0;
	ll num = 6;
	while (true)
	{
		if (Prime(num)) {
			printf("%lld ", num);
			count++;
		}

		if (count == N) {
			break;
		}

		num += 5;
	}

	printf("\n");
}
*/

//AtCoder Grand Contest 024-B
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
	vector<ll> P(N);
	for (ll i = 0; i < N; i++) {
		scanf("%lld", &P[i]);
	}

	vector<LLPair> pair;
	for (ll i = 0; i < N; i++) {
		pair.push_back(LLPair(P[i], i));
	}

	std::sort(pair.begin(), pair.end(), [](const LLPair &a, const LLPair &b) {
		return a.a < b.a;
	});

	ll cont = 0;
	ll longest = 0;
	ll prevIndex = -1;

	for (ll i = 0; i < N; i++) {
		if (pair[i].b > prevIndex) {
			cont++;
		}
		else {
			longest = max(cont, longest);
			cont = 1;
		}
		prevIndex = pair[i].b;
	}
	longest = max(cont, longest);

	printf("%lld\n", N - longest);
}
*/

//AtCoder Grand Contest 032-B
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

	ll group = N % 2 == 0 ? N / 2 : (N + 1) / 2;

	vector<LLPair> pair;
	if (N % 2 == 0) {
		for (ll i = 1; i <= N / 2; i++) {
			pair.push_back(LLPair(i, N - i + 1));
		}
	}
	else {
		pair.push_back(LLPair(N, -1));
		for (ll i = 1; i <= N / 2; i++) {
			pair.push_back(LLPair(i, N - i));
		}
	}
	
	vector<LLPair> result;
	for (ll i = 0; i < pair.size(); i++) {
		for (ll j = i + 1; j < pair.size(); j++) {
			result.push_back(LLPair(pair[i].a, pair[j].a));
			if (pair[j].b >= 0) {
				result.push_back(LLPair(pair[i].a, pair[j].b));
			}

			if (pair[i].b >= 0) {
				result.push_back(LLPair(pair[i].b, pair[j].a));
				if (pair[j].b >= 0) {
					result.push_back(LLPair(pair[i].b, pair[j].b));
				}
			}
		}
	}

	printf("%d\n", (int)result.size());
	for (auto p : result) {
		printf("%lld %lld\n", p.a, p.b);
	}

}
*/

//AtCoder Beginner Contest 054-C
/*

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
*/

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