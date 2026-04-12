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

using namespace std;

using ll = long long;
using ui = unsigned int;
const ll MOD = 1000000007;
const ll INF = 9223372036854775807;


//115
ll numLevelOfLevel[51];
ll numPattyOfLevel[51];
bool calcNumPattyOfLevel[51];

ll numLevel(ll level) {
	if (level == 0) {
		return 1;
	}
	else {
		return 3 + 2 * numLevel(level - 1);
	}
}

ll numPatty(ll level, ll numEat) {
	ll result = 0;

	if (level == 0) {
		return 1;
	}

	if (numEat == numLevelOfLevel[level] && calcNumPattyOfLevel[level] == true) {
		return numPattyOfLevel[level];
	}

	//ban1枚
	numEat -= 1;
	if (numEat <= 0) {
		return result;
	}

	//lebel-1バーガーの層の数
	ll numLevel_Lv1 = numLevelOfLevel[level - 1];

	//lebel-1バーガー
	result += numPatty(level - 1, min(numEat, numLevel_Lv1));
	numEat -= numLevel_Lv1;
	if (numEat <= 0) {
		return result;
	}

	//patty1枚
	result += 1;
	numEat -= 1;
	if (numEat <= 0) {
		return result;
	}

	//lebel-1バーガー
	result += numPatty(level - 1, min(numEat, numLevel_Lv1));
	numEat -= numLevel_Lv1;
	if (numEat <= 0) {
		return result;
	}

	//ban1枚
	numEat -= 1;
	//if (numEat <= 0) {
	//	return result;
	//}

	//メモ
	numPattyOfLevel[level] = result;
	calcNumPattyOfLevel[level] = true;

	return result;
}

int main() {
	ll N;
	scanf("%lld", &N);
	ll X;
	scanf("%lld", &X);

	memset(calcNumPattyOfLevel, 0, sizeof(calcNumPattyOfLevel));
	for (ll i = 0; i <= N; i++) {
		numLevelOfLevel[i] = numLevel(i);
	}

	ll result = 0;
	result = numPatty(N, X);
	printf("%lld\n", result);
}

//119
/*
//10^12 = 40bit
int main() {
	ll N, K;
	scanf("%lld %lld", &N, &K);

	vector<ll> A(N);
	for (ll i = 0; i < N; i++) {
		scanf("%lld", &A[i]);
	}

	const ll max_bit = 42;

	vector<ll> bit_count(max_bit, 0);
	for (ll i = 0; i < N; i++) {
		for (int iBit = 0; iBit < max_bit; iBit++) {
			if ((A[i] & (1LL << iBit)) > 0) {
				bit_count[iBit]++;
			}
		}		
	}

	vector<ll> bit_recomend(max_bit, 0);
	for (ll i = 0; i < max_bit; i++) {
		if (bit_count[i] <= N / 2) {
			bit_recomend[i] = 1;
		}
	}

	ll X = 0;
	ll Kcopy = K;
	for (ll i = max_bit - 1; i >= 0; i--) {
		if (bit_recomend[i] > 0 && Kcopy >= (1LL << i)) {
			X |= (1LL << i);
			Kcopy -= (1LL << i);
		}
	}

	ll result = 0;
	for (ll i = 0; i < N; i++) {
		result += X ^ A[i];
	}

	printf("%lld\n", result);
	
	return 0;
}
*/


//118
/*
struct LLPair {
	int num;
	int prev_last_match;
};

int main() {
	const int use[10] = { 0, 2, 5, 5, 4, 5, 6, 3, 7, 6 };

	int N, M;
	scanf("%d %d", &N, &M);

	vector<int> A(M);
	for (int i = 0; i < M; i++) {
		scanf("%d", &A[i]);
	}

	//[����][�c��}�b�`��] = �쐬�\�ȍł��傫�Ȑ�
	static LLPair dp[5010][10010];
	memset(dp, 0, sizeof(dp));

	for (int iM = 0; iM < M; iM++) {
		if (N < use[A[iM]]) {
			continue;
		}

		if (A[iM] > dp[1][N - use[A[iM]]].num) {
			dp[1][N - use[A[iM]]].num = A[iM];
			dp[1][N - use[A[iM]]].prev_last_match = 0;
		}
	}

	for (int iKeta = 1; iKeta <= N / 2; iKeta++) {
		for (int iLast = 2; iLast <= N; iLast++) {
			if (dp[iKeta][iLast].num == 0) {
				continue;
			}
			
			for (int iM = 0; iM < M; iM++) {
				if (iLast < use[A[iM]]) {
					continue;
				}

				if (A[iM] > dp[iKeta + 1][iLast - use[A[iM]]].num) {
					dp[iKeta + 1][iLast - use[A[iM]]].num = A[iM];
					dp[iKeta + 1][iLast - use[A[iM]]].prev_last_match = iLast;
				}
			}
		}
	}

	int next_index = 0;
	int next_keta = 0;
	for (int iKeta = N / 2; iKeta > 0; iKeta--) {
		if (dp[iKeta][0].num > 0) {
			next_keta = iKeta;
			break;
		}
	}

	while (next_keta > 0) {
		printf("%d", dp[next_keta][next_index].num);
		next_index = dp[next_keta][next_index].prev_last_match;
		next_keta--;
	}

	printf("\n");

	return 0;
}
*/


//119
/*
int main() {
	ll A, B, Q;
	scanf("%lld %lld %lld", &A, &B, &Q);

	vector<ll> s(A);
	for (ll i = 0; i < A; i++) {
		scanf("%lld", &s[i]);
	}

	vector<ll> t(B);
	for (ll i = 0; i < B; i++) {
		scanf("%lld", &t[i]);
	}

	vector<ll> x(Q);
	for (ll i = 0; i < Q; i++) {
		scanf("%lld", &x[i]);
	}

	std::sort(s.begin(), s.end());
	std::sort(t.begin(), t.end());

	for (ll i = 0; i < Q; i++) {
		auto it_s_east = std::lower_bound(s.begin(), s.end(), x[i]);
		auto it_t_east = std::lower_bound(t.begin(), t.end(), x[i]);
		
		ll dist_s_east = INF / 4;
		ll dist_s_west = INF / 4;
		ll dist_t_east = INF / 4;
		ll dist_t_west = INF / 4;

		if (it_s_east != s.begin()) {
			dist_s_west = x[i] - *(it_s_east - 1);
		}

		if (it_t_east != t.begin()) {
			dist_t_west = x[i] - *(it_t_east - 1);
		}

		if (it_s_east != s.end()) {
			dist_s_east = *it_s_east - x[i];
		}

		if (it_t_east != t.end()) {
			dist_t_east = *it_t_east - x[i];
		}

		ll min_dist = INF;

		min_dist = std::min(min_dist, std::max(dist_s_west, dist_t_west)); //WW
		min_dist = std::min(min_dist, std::max(dist_s_east, dist_t_east)); //EE
		min_dist = std::min(min_dist, dist_s_west * 2 + dist_t_east); //WE
		min_dist = std::min(min_dist, dist_s_east * 2 + dist_t_west); //EW
		min_dist = std::min(min_dist, dist_s_west + dist_t_east * 2); //EW
		min_dist = std::min(min_dist, dist_s_east + dist_t_west * 2); //WE

		printf("%lld\n", min_dist);
	}


	return 0;
}
*/

//120
/*
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
	ll N, M;
	scanf("%lld %lld", &N, &M);

	vector<ll> A(M);
	vector<ll> B(M);
	for (ll i = 0; i < M; i++) {
		scanf("%lld %lld", &A[i], &B[i]);
		A[i]--; //index started 0
		B[i]--;
	}

	UnionFindTree uf(N);

	stack<ll> result;
	ll unconfort = N * (N - 1) / 2;
	result.push(unconfort);

	for (ll i = M - 1; i > 0; i--) {
		ll countA = uf.Count(A[i]);
		ll countB = uf.Count(B[i]);
		bool success = uf.Unite(A[i], B[i]);

		if (success) {
			unconfort -= countA * countB;
		}

		result.push(unconfort);
	}

	while (result.empty() == false) {
		printf("%lld\n", result.top());
		result.pop();
	}

	return 0;
}
*/

//121
/*
ll XOR0toX(ll X) {
	ll result = ((X + 1) / 2) % 2;

	ll bit = 1;
	ll frec = 4;
	while (frec <= 9000000000000)
	{
		ll bit_val = 0;

		if (X < frec / 2) {
			bit_val = 0;
		}
		else if((X % frec) < frec / 2) {
			bit_val = 0;
		}
		else {
			bit_val = X % 2 == 0 ? 1 : 0;
		}

		result |= (bit_val << bit);

		frec *= 2;
		bit++;
	}

	return result;
}

int main() {
	ll A, B;
	scanf("%lld %lld", &A, &B);

	ll result = XOR0toX(B);

	if (A > 0) {
		result ^= XOR0toX(A - 1);
	}

	printf("%lld\n", result);

	return 0;
}
*/


//122
/*
int main() {
	ll N;
	scanf("%lld", &N);

	static ll dp[110][130];
	memset(dp, 0, sizeof(dp));
	dp[0][0] = 1;

	for (ll j = 0; j < N; j++) {
		for (ll i = 0; i < 125; i++) {
			if (dp[j][i] == 0) {
				continue;
			}

			for (int c = 1; c < 5; c++) { //���̕������
				//*AG
				if (i == 0 * 25 + 1 * 5 + 3 || 
					i == 1 * 25 + 1 * 5 + 3 ||
					i == 2 * 25 + 1 * 5 + 3 ||
					i == 3 * 25 + 1 * 5 + 3 ||
					i == 4 * 25 + 1 * 5 + 3) {
					//*AG+C
					if (c == 2) {
						continue;
					}
				}

				//*AC
				if (i == 0 * 25 + 1 * 5 + 2 ||
					i == 1 * 25 + 1 * 5 + 2 ||
					i == 2 * 25 + 1 * 5 + 2 ||
					i == 3 * 25 + 1 * 5 + 2 ||
					i == 4 * 25 + 1 * 5 + 2) {
					//*AC+G
					if (c == 3) {
						continue;
					}
				}

				//*GA
				if (i == 0 * 25 + 3 * 5 + 1 ||
					i == 1 * 25 + 3 * 5 + 1 ||
					i == 2 * 25 + 3 * 5 + 1 ||
					i == 3 * 25 + 3 * 5 + 1 ||
					i == 4 * 25 + 3 * 5 + 1) {
					//*GA+C
					if (c == 2) {
						continue;
					}
				}

				//A*G
				if (i == 1 * 25 + 0 * 5 + 3 ||
					i == 1 * 25 + 1 * 5 + 3 ||
					i == 1 * 25 + 2 * 5 + 3 ||
					i == 1 * 25 + 3 * 5 + 3 ||
					i == 1 * 25 + 4 * 5 + 3) {
					//A*G+C
					if (c == 2) {
						continue;
					}
				}

				//AG*
				if (i == 1 * 25 + 3 * 5 + 0 ||
					i == 1 * 25 + 3 * 5 + 1 ||
					i == 1 * 25 + 3 * 5 + 2 ||
					i == 1 * 25 + 3 * 5 + 3 ||
					i == 1 * 25 + 3 * 5 + 4) {
					//AG*+C
					if (c == 2) {
						continue;
					}
				}

				//���̕�������
				ll nextStr = ((i * 5) % 125) + c;

				//�z��DP
				dp[j + 1][nextStr] += dp[j][i];
				dp[j + 1][nextStr] %= MOD;
			}
		}
	}

	ll result = 0;
	for (ll i = 0; i < 125; i++) {
		result += dp[N][i];
		result %= MOD;
	}
	printf("%lld\n", result);
}
*/


//123
/*
struct ValueCombi{
	ll sumValue = 0;
	ll indexX = 0;
	ll indexY = 0;
	ll indexZ = 0;
	ll combiIndex() {
		return indexX * 1000000 + indexY * 1000 + indexZ;
	}
};

// "<" �̃I�[�o�[���[�h num����ɑ召��r���s��
bool operator< (const ValueCombi &a, const ValueCombi &b) {
	return a.sumValue < b.sumValue;
};

int main() {
	ll X, Y, Z, K;
	scanf("%lld %lld %lld %lld", &X, &Y, &Z, &K);

	vector<ll> valX(X);
	for (ll i = 0; i < X; i++) {
		scanf("%lld", &valX[i]);
	}

	vector<ll> valY(Y);
	for (ll i = 0; i < Y; i++) {
		scanf("%lld", &valY[i]);
	}

	vector<ll> valZ(Z);
	for (ll i = 0; i < Z; i++) {
		scanf("%lld", &valZ[i]);
	}

	std::sort(valX.begin(), valX.end(), std::greater<ll>());
	std::sort(valY.begin(), valY.end(), std::greater<ll>());
	std::sort(valZ.begin(), valZ.end(), std::greater<ll>());

	map<ll, int> inQ; //X*1000000+Y*1000+Z
	priority_queue<ValueCombi> pQ;

	//�܂�0,0,0������
	ValueCombi c;
	c.indexX = 0;
	c.indexY = 0;
	c.indexZ = 0;
	c.sumValue = valX[0] + valY[0] + valZ[0];
	pQ.push(c);
	inQ[c.combiIndex()] = 1;

	int output_count = 0;

	while (pQ.empty() == false) {
		//�ő�l�ƂȂ�g�ݍ��킹�����o��
		c = pQ.top();
		pQ.pop();

		inQ[c.combiIndex()] = 2;
		printf("%lld\n", c.sumValue);
		output_count++;
		if (output_count >= K) {
			break;
		}

		ValueCombi next;
		ValueCombi temp;

		//X�̎�
		if (c.indexX <= X - 2) {
			next = c;
			next.indexX++;
			
			temp = next;
			temp.indexY--;
			if (temp.indexY < 0 || inQ[temp.combiIndex()] == 2) {
				temp = next;
				temp.indexZ--;
				if (temp.indexZ < 0 || inQ[temp.combiIndex()] == 2) {
					next.sumValue = valX[next.indexX] + valY[next.indexY] + valZ[next.indexZ];
					pQ.push(next);
					inQ[next.combiIndex()] = 1;
				}
			}
		}

		//Y�̎�
		if (c.indexY <= Y - 2) {
			next = c;
			next.indexY++;

			temp = next;
			temp.indexX--;
			if (temp.indexX < 0 || inQ[temp.combiIndex()] == 2) {
				temp = next;
				temp.indexZ--;
				if (temp.indexZ < 0 || inQ[temp.combiIndex()] == 2) {
					next.sumValue = valX[next.indexX] + valY[next.indexY] + valZ[next.indexZ];
					pQ.push(next);
					inQ[next.combiIndex()] = 1;
				}
			}
		}

		//Z�̎�
		if (c.indexZ <= Z - 2) {
			next = c;
			next.indexZ++;

			temp = next;
			temp.indexX--;
			if (temp.indexX < 0 || inQ[temp.combiIndex()] == 2) {
				temp = next;
				temp.indexY--;
				if (temp.indexY < 0 || inQ[temp.combiIndex()] == 2) {
					next.sumValue = valX[next.indexX] + valY[next.indexY] + valZ[next.indexZ];
					pQ.push(next);
					inQ[next.combiIndex()] = 1;
				}
			}
		}

	}
}
*/


//125
/*
int main() {
	ll N;
	scanf("%lld", &N);

	ll abs_min = 100000000000;
	ll sum = 0;
	ll count_negative = 0;
	ll count_zero = 0;
	for (ll i = 0; i < N; i++) {
		ll num;
		scanf("%lld", &num);
		abs_min = std::min(std::abs(num), abs_min);

		if (num < 0) {
			count_negative++;
		}
		else if (num == 0) {
			count_zero++;
		}

		sum += std::abs(num);
	}

	ll result = 0;
	if (count_zero > 0) {
		result = sum;
	}
	else if (count_negative % 2 == 0) {
		result = sum;
	}
	else {
		result = sum - abs_min * 2;
	}

	printf("%lld\n", result);

	return 0;
}
*/

//124
/*
int main() {
	ll N, K;
	scanf("%lld %lld", &N, &K);

	char s[100010];
	scanf("%s", &s);

	vector<ll> state_length; //index0,2,4,...�͋t����

	int prev_state = 1; //�ŏ��������Ƃ�����index0��0������悤��
	ll length = 0;
	for (ll i = 0; i < N; i++) {
		char c = s[i];
		if (c == '0') {
			//��
			if (prev_state == 0) {
				length++;
			}
			else {
				state_length.push_back(length);
				length = 1;
				prev_state = 0;
			}
		}
		else {
			//�t
			if (prev_state == 1) {
				length++;
			}
			else {
				state_length.push_back(length);
				length = 1;
				prev_state = 1;
			}
		}
	}
	state_length.push_back(length);
	if (prev_state == 1) {
		state_length.push_back(0); //�Ō�͐��ŏI���悤��
	}
	else {
		state_length.push_back(0);
		state_length.push_back(0); //�Ō�͐��ŏI���悤��
	}

	ll state_length_size = (ll)state_length.size();
	ll window = std::min(state_length_size, 1 + K * 2);
	ll start = 0;
	ll end = window;
	ll sum = 0;
	for (int i = start; i < end; i++) {
		sum += state_length[i];
	}
	ll max = sum;

	while (true) {
		start += 2;
		end += 2;
		if (end >= state_length_size) {
			break;
		}

		sum -= state_length[start - 2];
		sum -= state_length[start - 1];
		sum += state_length[end - 2];
		sum += state_length[end - 1];

		if (sum > max) {
			max = sum;
		}
	}

	printf("%lld\n", max);

	return 0;
}
*/
