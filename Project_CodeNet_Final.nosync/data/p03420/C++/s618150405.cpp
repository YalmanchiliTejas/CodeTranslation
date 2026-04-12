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

using namespace std;

using ll = long long;
using ui = unsigned int;
const ll MOD = 1000000007;
const ll INF = 9223372036854775807;


//AtCoder Regular Contest 091-D
int main() {
	ll N;
	scanf("%lld", &N);
	ll K;
	scanf("%lld", &K);

	ll result = 0;

	for (ll b = K + 1; b <= N; b++) {
		ll loop = (N / b) * (b - K);

		ll mod = 0;

		if ((N % b) > 0 && (N % b) + 1 >= max(K, 1ll)) {
			mod = (N % b) + 1 - max(K, 1ll);
		}

		result += loop + mod;
	}

	printf("%lld\n", result);
}


//AtCoder Grand Contest 038-A
/*
int main() {
	ll H;
	scanf("%lld", &H);
	ll W;
	scanf("%lld", &W);
	ll A;
	scanf("%lld", &A);
	ll B;
	scanf("%lld", &B);

	for (ll j = 0; j < H; j++) {
		for (ll i = 0; i < W; i++) {
			if (j < B) {
				if (i < A) {
					printf("0");
				}
				else {
					printf("1");
				}
			}
			else {
				if (i < A) {
					printf("1");
				}
				else {
					printf("0");
				}
			}
		}
		printf("\n");
	}

}
*/

//AtCoder Regular Contest 068-D
/*
int main() {
	ll N;
	scanf("%lld", &N);
	vector<ll> A(N);
	for (ll i = 0; i < N; i++) {
		scanf("%lld", &A[i]);
	}

	map<int, int> mp;
	for (int i = 0; i < N; i++) {
		mp[A[i]]++;
	}

	priority_queue<ll> pq;
	auto begin = mp.begin(), end = mp.end();
	for (auto iter = begin; iter != end; iter++) {
		// iter->first: key, iter->second: value
		pq.push(iter->second);
	}

	while (true) {
		ll count = pq.top();

		if (count <= 1) {
			break;
		}

		pq.pop();

		if (count >= 3) {
			pq.push(count - 2);
		}
		else if (count == 2) {
			ll second_count = pq.top();
			pq.pop();

			pq.push(1); //2->1
			if (second_count >= 2) {
				pq.push(second_count - 1);
			}
		}
	}

	ll result = pq.size();

	printf("%lld\n", result);
}
*/

//AtCoder Beginner Contest 075-C
/*
struct LLPair {
	ll a = 0;
	ll b = 0;
};

//Union Find
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

	vector<LLPair> E;
	for (ll i = 0; i < M; i++) {
		LLPair edge;
		scanf("%lld", &edge.a);
		scanf("%lld", &edge.b);

		E.push_back(edge);
	}

	ll result = 0;

	for (ll i = 0; i < M; i++) {
		UnionFindTree uf(N);

		for (ll j = 0; j < M; j++) {
			if (j == i) {
				continue;
			}

			uf.Unite(E[j].a - 1, E[j].b - 1);
		}

		//���ׂĂ��Ȃ����Ă�����J�E���g��N�ɂȂ�
		//�Ȃ����Ă��Ȃ�=E[i]�����ƂȂ��Ă���
		if (uf.Count(0) < N) {
			result++;
		}
	}

	printf("%lld\n", result);
}
*/


//AtCoder Regular Contest 084-C
/*
int main() {
	ll N;
	scanf("%lld", &N);
	vector<ll> A(N);
	for (ll i = 0; i < N; i++) {
		scanf("%lld", &A[i]);
	}
	vector<ll> B(N);
	for (ll i = 0; i < N; i++) {
		scanf("%lld", &B[i]);
	}
	vector<ll> C(N);
	for (ll i = 0; i < N; i++) {
		scanf("%lld", &C[i]);
	}

	std::sort(A.begin(), A.end());
	std::sort(B.begin(), B.end());
	std::sort(C.begin(), C.end());

	ll result = 0;

	for (auto val : B) {
		auto itA = std::lower_bound(A.begin(), A.end(), val);
		ll abobe = itA - A.begin();

		auto itC = std::upper_bound(C.begin(), C.end(), val);
		ll bottom = C.end() - itC;

		result += abobe * bottom;
	}

	printf("%lld\n", result);
}
*/

//AtCoder Beginner Contest 097-A(��o����ԈႦ��WA�ɂȂ����̂�)
/*
int main() {
	ll a;
	scanf("%lld", &a);
	ll b;
	scanf("%lld", &b);
	ll c;
	scanf("%lld", &c);
	ll d;
	scanf("%lld", &d);

	ll distAB = abs(b - a);
	ll distAC = abs(c - a);
	ll distBC = abs(c - b);

	if (distAC <= d || (distAB <= d && distBC <= d)) {
		printf("Yes\n");
	}
	else {
		printf("No\n");
	}
}
*/

//AtCoder Beginner Contest 042-C
/*
int main() {
	ll N;
	scanf("%lld", &N);
	ll K;
	scanf("%lld", &K);
	vector<ll> D(K);
	for (ll i = 0; i < K; i++) {
		scanf("%lld", &D[i]);
	}

	vector<ll> A;
	for (ll i = 0; i <= 9; i++) {
		if (std::find(D.begin(), D.end(), i) == D.end()) {
			A.push_back(i);
		}
	}

	ll result = 0;

	vector<ll> numIndex(5, -1);
	while (true) {
		numIndex[0]++;
		for (ll i = 0; i < (ll)numIndex.size(); i++) {
			if (numIndex[i] >= (ll)A.size()) {
				numIndex[i] = 0;
				numIndex[i + 1]++;
			}
		}

		ll num = 0;
		ll keta = 1;
		for (ll i = 0; i < (ll)numIndex.size(); i++) {
			if (numIndex[i] >= 0) {
				num += A[numIndex[i]] * keta;
				keta *= 10;
			}
		}

		if (num >= N) {
			result = num;
			break;
		}
	}

	printf("%lld\n", result);
}
*/

//AtCoder Beginner Contest 138-E
/*
int main() {
	char s[100010];
	char t[100010];
	scanf("%s", s);
	scanf("%s", t);
	ll len_s = strlen(s);
	ll len_t = strlen(t);

	vector<int> appear[26];

	for (int i = 0; i < len_s; i++) {
		appear[s[i] - 'a'].push_back(i);
	}

	ll loop = 0;
	ll index = -1;
	vector<int> appear_index(26, -1);

	for (int i = 0; i < len_t; i++) {
		char c = t[i] - 'a';
		int size = (int)appear[c].size();

		if (size == 0) {
			printf("-1\n");
			return 0;
		}

		while (true)
		{
			appear_index[c]++;

			if (appear_index[c] >= size)
			{
				loop++;

				for (int i = 0; i < 26; i++) {
					appear_index[i] = -1;
				}
				appear_index[c] = 0;

				index = appear[c][0];
				break;
			}

			if (appear[c][appear_index[c]] > index)
			{
				index = appear[c][appear_index[c]];
				break;
			}
		}
	}

	ll result = (ll)loop * len_s + (ll)index + 1ll;

	printf("%lld\n", result);
}
*/

//AtCoder Grand Contest 034-B
/*
int main() {
	char s[200010];
	scanf("%s", s);
	ll len = strlen(s);

	ll result = 0;

	ll a_continue = 0;
	bool prev_b = false;
	for (ll i = 0; i < len; i++) {
		if (s[i] == 'A') {
			if (prev_b == true) {
				a_continue = 1;
			}
			else {
				a_continue++;
			}

			prev_b = false;
		}
		else if (s[i] == 'B') {
			if (prev_b == true) {
				a_continue = 0;
			}
			else {
				prev_b = true;
			}
		}
		else if (s[i] == 'C') {
			if (prev_b == true) {
				result += a_continue;
			}
			else {
				a_continue = 0;
			}
			prev_b = false;
		}
	}

	printf("%lld\n", result);
}
*/

//AtCoder Beginner Contest 125
/*
void DecompositPrime(int n, map<int, int> &result) {
	result.clear();

	int a = 2;
	while (n >= a * a) {
		if (n % a == 0) {
			result[a]++;
			n /= a;
		}
		else {
			a++;
		}
	}

	result[n]++;
}

//�f���������̊e�f�����̗v�f����min���Ƃ邱�Ƃōő���񐔂����߂�
map<int, int> PrimeMin(map<int, int> m1, map<int, int> m2) {
	map<int, int> result;

	auto begin = m1.begin(), end = m1.end();
	for (auto iter = begin; iter != end; iter++) {
		// iter->first: key, iter->second: value
		if (iter->second > 0)
		{
			if (m2[iter->first] > 0) {
				result[iter->first] = min(iter->second, m2[iter->first]);
			}
		}
	}

	return result;
}

int LLpow(int x, int n) {
	int ret = 1;
	while (n > 0) {
		if (n & 1) {
			ret *= x;
		}
		x *= x;
		n >>= 1;
	}
	return ret;
}

int NumFromPrime(map<int, int> m)
{
	int result = 1;

	auto begin = m.begin(), end = m.end();
	for (auto iter = begin; iter != end; iter++) {
		// iter->first: key, iter->second: value
		if (iter->second > 0)
		{
			result *= LLpow(iter->first, iter->second);
		}
	}

	return result;
}

int main() {
	int N;
	scanf("%d", &N);
	vector<int> A(N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}

	vector<map<int, int>> P(N, map<int, int>());
	for (int i = 0; i < N; i++) {
		DecompositPrime(A[i], P[i]);
	}

	vector<map<int, int>> minFromHead(N, map<int, int>());
	minFromHead[0] = P[0];
	for (int i = 1; i < N; i++) {
		minFromHead[i] = PrimeMin(minFromHead[i - 1], P[i]);
	}

	vector<map<int, int>> minFromTail(N, map<int, int>());
	minFromTail[N - 1] = P[N - 1];
	for (int i = N - 2; i >= 0; i--) {
		minFromTail[i] = PrimeMin(minFromTail[i + 1], P[i]);
	}

	int result = 0;

	for (int i = 0; i < N; i++) {
		int val = 0;

		if (i == 0) {
			val = NumFromPrime(minFromTail[i + 1]);
		}
		else if (i == N - 1) {
			val = NumFromPrime(minFromHead[i - 1]);
		}
		else {
			val = NumFromPrime(PrimeMin(minFromHead[i - 1], minFromTail[i + 1]));
		}
		
		result = max(result, val);
	}

	printf("%d\n", result);
}


//AtCoder Beginner Contest 074
/*
int main() {
	ll A;
	scanf("%lld", &A);
	ll B;
	scanf("%lld", &B);
	ll C;
	scanf("%lld", &C);
	ll D;
	scanf("%lld", &D);
	ll E;
	scanf("%lld", &E);
	ll F;
	scanf("%lld", &F);

	double maxRate = -1.0;
	ll holdWater = 0;
	ll holdSugar = 0;

	for (ll iA = 0; iA * A * 100 <= F; iA++) {
		for (ll iB = 0; iB * B * 100 + iA * A * 100 <= F; iB++) {
			ll water = iB * B * 100 + iA * A * 100;
			ll maxSugar = min(water / 100 * E, F - water);

			for (ll iC = 0; iC * C <= maxSugar; iC++) {
				for (ll iD = 0; iC * C + iD * D <= maxSugar; iD++) {
					ll sugar = iC * C + iD * D;
					double rate = (double)sugar / (double)(water + sugar);
					if (rate > maxRate) {
						maxRate = rate;
						holdWater = water;
						holdSugar = sugar;
					}
				}
			}
		}
	}

	printf("%lld %lld\n", holdWater + holdSugar, holdSugar);
}
*/


//AtCoder Beginner Contest 114
/*
int main() {
	ll N;
	scanf("%lld", &N);

	vector<ll> val(10, 0); //value = 0:- 1:3 2:5 3:7

	ll result = 0;

	while (true) {
		//next 753
		val[0]++;
		for (ll i = 0; i < 9; i++) {
			if (val[i] >= 4) {
				val[i + 1]++;
				val[i] = 1;
			}
			else {
				break;
			}
		}

		//judge
		vector<int> count(4, 0);
		for (ll i = 0; i < 9; i++) {
			count[val[i]]++;
		}

		if (count[1] == 0 || count[2] == 0 || count[3] == 0) {
			continue;
		}

		ll sum = 0;
		ll keta = 1;
		for (ll i = 0; i < 10; i++) {
			if (val[i] == 1) {
				sum += 3 * keta;
			}
			else if(val[i] == 2){
				sum += 5 * keta;
			}
			else if (val[i] == 3) {
				sum += 7 * keta;
			}

			keta *= 10;
		}

		if (sum <= N) {
			result++;
		}
		else {
			break;
		}
	}

	printf("%lld\n", result);
}
*/

//AtCoder Grand Contest 023-A
/*
int main() {
	ll N;
	scanf("%lld", &N);
	vector<ll> A(N + 1);
	A[0] = 0;
	for (ll i = 1; i <= N; i++) {
		scanf("%lld", &A[i]);
	}

	vector<ll> T(N + 1, 0);
	T[0] = A[0];
	for (ll i = 1; i <= N; i++) {
		T[i] = T[i - 1] + A[i];
	}

	ll result = 0;

	map<ll, ll> mp;
	for (ll i = 0; i <= N; i++) {
		mp[T[i]]++;
	}

	auto begin = mp.begin(), end = mp.end();
	for (auto iter = begin; iter != end; iter++) {
		// iter->first: key, iter->second: value
		ll var = iter->second;
		result += var * (var - 1) / 2;
	}

	//TLE
	//for (ll i = 1; i <= N; i++) {
	//	for (ll j = i; j <= N; j++) {
	//		if (T[j] - T[i - 1] == 0) {
	//			result++;
	//		}
	//	}
	//}

	printf("%lld\n", result);
}
*/


//AtCoder Regular Contest 074-C
/*
int main() {
	ll H;
	scanf("%lld", &H);
	ll W;
	scanf("%lld", &W);

	ll result = INF;

	//holizontal cut
	for (ll i = 1; i < H; i++) {
		vector<ll> s;
		s.push_back(W * i);
		ll lastH = H - i;

		if (W * lastH % 2 == 0) {
			s.push_back(W * lastH / 2);
			s.push_back(W * lastH / 2);
		}
		else {
			if (lastH > W) {
				//holizontal cut
				ll cutIndex = lastH / 2;
				s.push_back(W * cutIndex);
				s.push_back(W * (lastH - cutIndex));
			}
			else {
				//vartical cut
				ll cutIndex = W / 2;
				s.push_back(cutIndex * lastH);
				s.push_back((W - cutIndex) * lastH);
			}
		}

		sort(s.begin(), s.end());
		result = min(result, s[2] - s[0]);
	}

	//vartical cut
	for (ll i = 1; i < W; i++) {
		vector<ll> s;
		s.push_back(H * i);
		ll lastW = W - i;

		if (lastW * H % 2 == 0) {
			s.push_back(lastW * H / 2);
			s.push_back(lastW * H / 2);
		}
		else {
			if (lastW > H) {
				//vartical cut
				ll cutIndex = lastW / 2;
				s.push_back(H * cutIndex);
				s.push_back(H * (lastW - cutIndex));
			}
			else {
				//holizontal cut
				ll cutIndex = H / 2;
				s.push_back(cutIndex * lastW);
				s.push_back((H - cutIndex) * lastW);
			}
		}

		sort(s.begin(), s.end());
		result = min(result, s[2] - s[0]);
	}

	printf("%lld\n", result);
}
*/

//AtCoder Beginner Contest 045-C
/*
int main() {
	char S[11];
	scanf("%s", S);
	int len = (int)strlen(S);

	ll result = 0;

	for (int i = 0; i < (1 << (len - 1)); i++) {
		ll keta = 1;

		for (int j = 0; j < len; j++) {
			result += (ll)(S[len - j - 1] - '0') * keta;
			if ((i & (1 << j)) == 0) {
				keta *= 10;
			}
			else {
				keta = 1;
			}
		}
	}


	printf("%lld\n", result);
}
*/

//AtCoder Regular Contest 067-D
/*
int main() {
	ll N;
	scanf("%lld", &N);
	ll A;
	scanf("%lld", &A);
	ll B;
	scanf("%lld", &B);

	vector<ll> X(N);
	for (ll i = 0; i < N; i++) {
		scanf("%lld", &X[i]);
	}

	ll result = 0;

	for (ll i = 0; i < N - 1; i++) {
		ll dist = X[i + 1] - X[i];
		result += min(A * dist, B);
	}

	printf("%lld\n", result);
}
*/