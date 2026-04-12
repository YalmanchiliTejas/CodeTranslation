#pragma warning( disable : 6031)

#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <math.h>
int minimum(int a, int b) { return a < b ? a : b; }
int maximum(int a, int b) { return a > b ? a : b; }
const long long mod = 1000000007;
//const long long mod = 998244353;
using std::vector;
using std::pair;
using std::string;
using std::map;
int main() {
	int N;
	scanf("%d", &N);
	auto res = new unsigned long long* [N];
	auto bitres = new long long* [N];
	for (int i = 0; i < N; i++) {
		res[i] = new unsigned long long[N] {};
		bitres[i] = new long long[N];
	}
	auto S = new unsigned long long[N];
	auto T = new unsigned long long[N];
	auto U = new unsigned long long[N];
	auto V = new unsigned long long[N];
	for (int i = 0; i < N; i++)scanf("%llu", S + i);
	for (int i = 0; i < N; i++)scanf("%llu", T + i);
	for (int i = 0; i < N; i++)scanf("%llu", U + i);
	for (int i = 0; i < N; i++)scanf("%llu", V + i);
	//for (int i = 0; i < N; i++)S[i] = 1 - S[i];
	//for (int i = 0; i < N; i++)T[i] = 1 - T[i];
	for (int b = 0; b < 64; b++) {
		for (int i = 0; i < N; i++)for (int j = 0; j < N; j++)bitres[i][j] = -1;
		bool r0 = false;
		bool r1 = false;
		bool c0 = false;
		bool c1 = false;
		vector<int> fr;
		vector<int> fc;
		for (int i = 0; i < N; i++) {
			if (!S[i] && (U[i] & (1LL << b))) {
				for (int j = 0; j < N; j++) {
					bitres[i][j] = 1;
				}
				r1 = true;
				//printf("a- %d %d %lld %lld\n", b, i, S[i], (U[i] & (1LL << i)));
			}
			else if (S[i] && !(U[i] & (1LL << b))) {
				for (int j = 0; j < N; j++) {
					bitres[i][j] = 0;
				}
				r0 = true;
				//printf("b- %d %d %lld %lld\n", b, i, S[i], U[i]);
			}
			else {
				fr.push_back(i);
			}
		}
		for (int i = 0; i < N; i++) {
			if (!T[i] && (V[i] & (1LL << b))) {
				for (int j = 0; j < N; j++) {
					if (bitres[j][i] == 0) {
						printf("-1");
						return 0;
					}
					bitres[j][i] = 1;
				}
				//printf("c- %d %d %lld %lld\n", b, i, T[i], V[i]);
				c1 = true;
			}
			else if (T[i] && !(V[i] & (1LL << b))) {
				for (int j = 0; j < N; j++) {
					if (bitres[j][i] == 1) {
						printf("-1");
						return 0;
					}
					bitres[j][i] = 0;
				}
				c0 = true;
				//printf("d- %d %d %lld %lld\n", b, i, T[i], V[i]);
			}
			else {
				fc.push_back(i);
			}
		}
		//for (int i = 0; i < N; i++)printf("%d ", (bool)(U[i] & (1LL << b))); printf("\n");
		//for (int i = 0; i < N; i++)printf("%d ", (bool)(V[i] & (1LL << b))); printf("\n");
		if (fr.size() == 0 || fc.size() == 0) {
			for (int i = 0; i < fr.size(); i++) {
				int r = fr[i];
				if (S[r]) {
					if (!c1) {
						printf("-1");
						return 0;
					}
				}
				else {
					if (!c0) {
						printf("-1");
						return 0;
					}
				}
			}
			for (int i = 0; i < fc.size(); i++) {
				int c = fc[i];
				if (T[c]) {
					if (!r1) {
						printf("-1");
						return 0;
					}
				}
				else {
					if (!r0) {
						printf("-1");
						return 0;
					}
				}
			}
		}
		else if (fr.size() == 1) {
			bool g = false;
			int r = fr[0];
			for (int i = 0; i < fc.size(); i++) {
				int c = fc[i];
				if (T[c]) {
					if (r1) {
						bitres[r][c] = S[r];
						g = true;
					}
					else {
						bitres[r][c] = T[c];
						if (T[c] == S[r])g = true;
					}
				}
				else {
					if (r0) {
						bitres[r][c] = S[r];
						g = true;
					}
					else {
						bitres[r][c] = T[c];
						if (T[c] == S[r])g = true;
					}
				}
			}
			if (!g) {
				if (S[r]) {
					if (!c1) {
						printf("-1");
						//printf("a %d\n", b);
						return 0;
					}
				}
				else {
					if (!c0) {
						printf("-1");
						//printf("b %d\n", b);
						return 0;
					}
				}
			}
		}
		else if (fc.size() == 1) {
			bool g = false;
			int c = fc[0];
			for (int i = 0; i < fr.size(); i++) {
				int r = fr[i];
				if (S[r]) {
					if (c1) {
						bitres[r][c] = T[c];
						g = true;
					}
					else {
						bitres[r][c] = S[r];
						if (T[c] == S[r])g = true;
					}
				}
				else {
					if (c0) {
						bitres[r][c] = T[c];
						g = true;
					}
					else {
						bitres[r][c] = S[r];
						if (T[c] == S[r])g = true;
					}
				}
			}
			if (!g) {
				if (T[c]) {
					if (!r1) {
						printf("-1");
						//printf("c %d\n", b);
						return 0;
					}
				}
				else {
					if (!r0) {
						printf("-1");
						//printf("d %d\n", b);
						return 0;
					}
				}
			}
		}
		else {
			for (int i = 0; i < fr.size(); i++) {
				for (int j = 0; j < fc.size(); j++) {
					int k;
					if (i == 0 && j == 0) {
						k = 0;
					}
					else if(i == 0 || j == 0){
						k = 1;
					}
					else {
						k = 0;
					}
					bitres[fr[i]][fc[j]] = k;
				}
			}
		}
		for (int i = 0; i < N; i++)for (int j = 0; j < N; j++)res[i][j] |= (bitres[i][j] << b);
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%llu ", res[i][j]);
		}
		printf("\n");
	}
	return 0;
}