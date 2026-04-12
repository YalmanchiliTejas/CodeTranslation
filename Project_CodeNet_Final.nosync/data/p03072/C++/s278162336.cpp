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
using vll = std::vector<ll>;
using vvll = std::vector<vll>;
using vvvll = std::vector<vvll>;
#define reps(i, S, E) for (ll i = (S); i <= (E); i++)
#define rep(i, N) reps(i, 0, N-1)
#define deps(i, E, S) for (ll i = (E); i >= (S); i--)
#define dep(i, N) deps(i, N-1, 0)
const ll MOD = 1000000007;
const ll INF = 1LL << 60;

//AtCoder Beginner Contest 124 - 125 - A / B
int main() {
	ll N;
	scanf("%lld", &N);
	vector<ll> H(N);
	for (ll i = 0; i < N; i++) {
		scanf("%lld", &H[i]);
	}

	ll result = 1;
	ll maxH = H[0];

	reps(i, 1, N - 1) {
		if (maxH <= H[i]) {
			result++;
		}

		maxH = max(maxH, H[i]);
	}

	printf("%lld\n", result);
}

/*
int main() {
	ll A;
	scanf("%lld", &A);
	ll B;
	scanf("%lld", &B);

	ll result = 0;

	if (A > B) {
		result += A;
		A--;
	}
	else {
		result += B;
		B--;
	}


	if (A > B) {
		result += A;
		A--;
	}
	else {
		result += B;
		B--;
	}

	printf("%lld\n", result);
}
*/

/*
int main() {
	ll N;
	scanf("%lld", &N);
	vector<ll> V(N);
	for (ll i = 0; i < N; i++) {
		scanf("%lld", &V[i]);
	}
	vector<ll> C(N);
	for (ll i = 0; i < N; i++) {
		scanf("%lld", &C[i]);
	}

	ll result = 0;

	rep(i, N) {
		if (V[i] - C[i] > 0) {
			result += V[i] - C[i];
		}
	}

	printf("%lld\n", result);
}
*/

/*
int main() {
	ll A;
	scanf("%lld", &A);
	ll B;
	scanf("%lld", &B);
	ll T;
	scanf("%lld", &T);

	ll result = (ll)(T / A) * B;

	printf("%lld\n", result);
}
*/

//AtCoder Beginner Contest 131 - 127 - A
/*
int main() {
	ll A;
	scanf("%lld", &A);
	ll B;
	scanf("%lld", &B);

	ll result = 0;

	if (A >= 13) {
		result = B;
	}
	else if (A >= 6) {
		result = B / 2;
	}

	printf("%lld\n", result);
}
*/

/*
int main() {
	ll A;
	scanf("%lld", &A);
	ll P;
	scanf("%lld", &P);

	ll bit = A * 3 + P;

	ll result = bit / 2;

	printf("%lld\n", result);
}
*/

/*
int main() {
	vector<ll> A(3);
	for (ll i = 0; i < 3; i++) {
		scanf("%lld", &A[i]);
	}

	ll result = INF;

	rep(i, 3) {
		reps(j, i + 1, 2) {
			result = min(result, A[i] + A[j]);
		}
	}

	printf("%lld\n", result);
}
*/

/*
int main() {
	ll X;
	scanf("%lld", &X);
	ll A;
	scanf("%lld", &A);

	if (X < A) {
		printf("0\n");
	}
	else {
		printf("10\n");
	}
}
*/

/*
int main() {
	char S[101010];
	scanf("%s", S);
	ll len = strlen(S);
	
	rep(i, len - 1) {
		if (S[i] == S[i + 1]) {
			printf("Bad\n");
			return 0;
		}
	}
	printf("Good\n");

}
*/

//AtCoder Beginner Contest 131 - 127 - B
/*
int main() {
	ll r;
	scanf("%lld", &r);
	ll d;
	scanf("%lld", &d);
	ll x;
	scanf("%lld", &x);

	ll result = x;
	rep(i, 10) {
		result = max(0ll, result * r - d);
		printf("%lld\n", result);
	}
}
*/

/*
struct LLPair {
	string s;
	ll a = 0;
	ll b = 0;
	LLPair() {}
	LLPair(string s, ll a, ll b) {
		this->s = s;
		this->a = a;
		this->b = b;
	}
};

int main() {
	ll N;
	cin >> N;
	vector<LLPair> P(N);
	rep(i, N) {
		cin >> P[i].s >> P[i].b;
		P[i].a = i + 1;
	}

	std::sort(P.begin(), P.end(), [](const LLPair &a, const LLPair &b) {
		if (a.s == b.s) {
			return a.b > b.b; //�~���ɂ���ɂ� > �Ƃ���
		}
		else {
			return a.s < b.s;
		}
	});

	rep(i, N) {
		printf("%lld\n", P[i].a);
	}
}
*/

/*
int main() {
	ll N;
	scanf("%lld", &N);
	vector<ll> W(N);
	for (ll i = 0; i < N; i++) {
		scanf("%lld", &W[i]);
	}

	ll result = INF;

	rep(i, N - 1) {
		ll S1 = 0;
		ll S2 = 0;
		rep(j, N) {
			if (j <= i) {
				S1 += W[j];
			}
			else {
				S2 += W[j];
			}
		}
		result = min(result, abs(S1 - S2));
	}

	printf("%lld\n", result);
}
*/

/*
int main() {
	ll N;
	scanf("%lld", &N);
	ll X;
	scanf("%lld", &X);
	vector<ll> L(N);
	for (ll i = 0; i < N; i++) {
		scanf("%lld", &L[i]);
	}

	ll bound = 0;
	ll result = 1;

	rep(i, N) {
		bound += L[i];
		if (bound <= X) {
			result++;
		}
	}

	printf("%lld\n", result);
}
*/

/*
int main() {
	ll N;
	scanf("%lld", &N);
	ll L;
	scanf("%lld", &L);

	ll result = 0;

	if (L > 0) {
		//��ԍŏ��̂�񂲂𖳎�
		reps(i, L + 1, L + N - 1) {
			result += i;
		}
	}
	else if (L + N <= 0) {
		//��ԍŌ�̂�񂲂𖳎�
		reps(i, L, L + N - 2) {
			result += i;
		}
	}
	else {
		//�[���̂�񂲂𖳎�
		reps(i, L, L + N - 1) {
			result += i;
		}
	}

	printf("%lld\n", result);
}
*/

//AtCoder Beginner Contest 123 - CBA
/*
int main() {
	vector<ll> A(5);
	for (ll i = 0; i < 5; i++) {
		scanf("%lld", &A[i]);
	}
	ll k;
	scanf("%lld", &k);
	
	rep(i, 5) {
		reps(j, i + 1, 5 - 1) {
			if (A[j] - A[i] > k) {
				printf(":(\n");
				return 0;
			}
		}
	}

	printf("Yay!\n");
}
*/

/*
int main() {
	vector<ll> A(5);
	for (ll i = 0; i < 5; i++) {
		scanf("%lld", &A[i]);
	}

	ll lastIndex = 0;
	ll minMod = INF;
	rep(i, 5) {
		if (A[i] % 10 < minMod && A[i] % 10 > 0) {
			minMod = A[i] % 10;
			lastIndex = i;
		}
	}

	ll result = A[lastIndex];
	rep(i, 5) {
		if (i == lastIndex) {
			continue;
		}

		result += (ll)ceil((double)A[i] / 10.0) * 10;
	}

	printf("%lld\n", result);
}
*/

/*
int main() {
	ll N;
	scanf("%lld", &N);
	vector<ll> A(5);
	for (ll i = 0; i < 5; i++) {
		scanf("%lld", &A[i]);
	}

	ll bottleNeck = INF;
	rep(i, 5) {
		bottleNeck = min(bottleNeck, A[i]);
	}

	ll result = 5 + (ll)ceil((double)N / (double)bottleNeck) - 1;

	printf("%lld\n", result);
}
*/

//AtCoder Beginner Contest 132 - A B
/*
int main() {
	ll N;
	scanf("%lld", &N);
	vector<ll> p(N);
	for (ll i = 0; i < N; i++) {
		scanf("%lld", &p[i]);
	}

	ll result = 0;

	reps(i, 0, N - 3) {
		if (p[i] < p[i + 1] && p[i + 1] < p[i + 2]) {
			result++;
		}
		else if (p[i] > p[i + 1] && p[i + 1] > p[i + 2]) {
			result++;
		}
	}

	printf("%lld\n", result);
}
*/

/*
int main() {
	char S[101010];
	scanf("%s", S);
	ll len = strlen(S);

	vll count(26);
	rep(i, len) {
		count[S[i] - 'A']++;
	}


	rep(i, 26) {
		if (count[i] != 0 && count[i] != 2) {
			printf("No\n");
			return 0;
		}
	}

	printf("Yes\n");
}
*/

//AtCoder Beginner Contest 133 - A B
/*
int main() {
	ll N;
	scanf("%lld", &N);
	ll D;
	scanf("%lld", &D);
	vvll X(N, vll(D, 0));
	rep(i, N) rep(j, D) {
		ll x;
		scanf("%lld", &x);
		X[i][j] = x;
	}

	ll result = 0;

	reps(i, 0, N - 1) {
		reps(j, i + 1, N - 1) {
			ll d2 = 0;
			rep(k, D) {
				ll sub = X[i][k] - X[j][k];
				d2 += sub * sub;
			}

			rep(k, 16000) {
				if (k * k == d2) {
					result++;
					break;
				}
			}
		}
	}

	printf("%lld\n", result);
}
*/

/*
int main() {
	ll N;
	scanf("%lld", &N);
	ll A;
	scanf("%lld", &A);
	ll B;
	scanf("%lld", &B);

	ll result = min(A * N, B);

	printf("%lld\n", result);
}
*/

//AtCoder Beginner Contest 134 - A B
/*
int main() {
	ll N;
	scanf("%lld", &N);
	ll D;
	scanf("%lld", &D);

	ll result = (ll)ceil((double)N / (1 + D * 2));

	printf("%lld\n", result);
}
*/

/*
int main() {
	ll r;
	scanf("%lld", &r);

	ll result = 3 * r * r;

	printf("%lld\n", result);
}
*/

//AtCoder Beginner Contest 135 - B
/*
int main() {
	ll N;
	scanf("%lld", &N);
	vector<ll> p(N);
	for (ll i = 0; i < N; i++) {
		scanf("%lld", &p[i]);
	}

	ll err = 0;
	rep(i, N) {
		if (p[i] != i + 1) {
			err++;
		}
	}

	if (err <= 2) {
		printf("YES\n");
	}
	else {
		printf("NO\n");
	}
}
*/

//AtCoder Beginner Contest 135 - A
/*
int main() {
	ll A;
	scanf("%lld", &A);
	ll B;
	scanf("%lld", &B);

	if (abs(A - B) % 2 == 1) {
		printf("IMPOSSIBLE\n");
		return 0;
	}

	ll ans = abs(A - B) / 2;
	ll result = min(A, B) + ans;

	printf("%lld\n", result);
}
*/

//AtCoder Beginner Contest 126 - B
/*
int main() {
	char s[101010];
	scanf("%s", s);
	ll len = strlen(s);

	ll front = (s[0] - '0') * 10 + (s[1] - '0');
	ll back = (s[2] - '0') * 10 + (s[3] - '0');

	if ((front > 12 && back > 12) || (front > 12 && back == 0) || (back > 12 && front == 0) || (back == 0 && front == 0)) {
		printf("NA\n");
	}
	else if (front > 12 || front == 0) {
		printf("YYMM\n");
	}
	else if (back > 12 || back == 0) {
		printf("MMYY\n");
	}
	else {
		printf("AMBIGUOUS\n");
	}
}
*/

//AtCoder Beginner Contest 126 - A
/*
int main() {
	ll N;
	scanf("%lld", &N);
	ll K;
	scanf("%lld", &K);
	char s[101010];
	scanf("%s", s);
	ll len = strlen(s);

	s[K - 1] = s[K - 1] - 'A' + 'a';

	printf("%s\n", s);
}
*/