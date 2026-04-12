#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int N, M, S, T;

int U[200005], V[200005];
long long int D[200006];

long long int MODE =1000000007;
vector<int> Adj[100005];
map<pair<int, int>, long long int> DIS;

int check[100005];
long long int D_S[100005], D_T[100005];
set<pair<long long int, int> > SET;

void DIJKSTRA_S(void) {

	for (int i = 1; i <= N; i++) { check[i] = -1; D_S[i] = 1000000030000007; }
	SET.clear();

	D_S[S] = 0; check[S] = 1;
	SET.insert(pair<long long int, int>(D_S[S], S));

	while (SET.size()) {
		pair<long long int, int> P = *SET.begin();
		long long int distance = P.first;
		int M = P.second;
		SET.erase(P);
		check[M] = 1;

		for (int h = 0; h < (int)Adj[M].size(); h++) {
			int H = Adj[M][h];
			if (check[H] != 1) {
				P.first = D_S[H];
				P.second = H;
				SET.erase(P);
				D_S[H] = min(D_S[H], distance + DIS[pair<int, int>(M, H)]);
				P.first = D_S[H];
				P.second = H;
				SET.insert(P);
				//check[H] = 1;
			}
		}
	}
}

void DIJKSTRA_T(void) {

	for (int i = 1; i <= N; i++) { check[i] = -1; D_T[i] = 1000000030000007; }
	SET.clear();

	D_T[T] = 0; check[T] = 1;
	SET.insert(pair<long long int, int>(D_T[T], T));

	while (SET.size()) {
		pair<long long int, int> P = *SET.begin();
		long long int distance = P.first;
		int M = P.second;
		SET.erase(P);
		check[M] = 1;

		for (int h = 0; h < (int)Adj[M].size(); h++) {
			int H = Adj[M][h];
			if (check[H] != 1) {
				P.first = D_T[H];
				P.second = H;
				SET.erase(P);
				D_T[H] = min(D_T[H], distance + DIS[pair<int, int>(M, H)]);
				P.first = D_T[H];
				P.second = H;
				SET.insert(P);
				//check[H] = 1;
			}
		}
	}
}

long long int NUM_S[100005], NUM_T[100005];
vector<pair<long long int, int> > Vec;

void CALC_NUM_S(void) {

	Vec.clear();

	for (int i = 1; i <= N; i++) {
		Vec.push_back(pair<long long int, int>(D_S[i], i));
	}

	sort(Vec.begin(), Vec.end());

	NUM_S[S] = 1;

	for (int i = 0; i < N; i++) {
		int M = Vec[i].second;
		long long int distance = Vec[i].first;
		for (int j = 0; j < (int)Adj[M].size(); j++) {
			int H = Adj[M][j];
			if (D_S[M] + DIS[pair<int, int>(M, H)] == D_S[H]) { NUM_S[H] += NUM_S[M]; NUM_S[H] %= MODE; }
              }
	}
}

void CALC_NUM_T(void) {

	Vec.clear();

	for (int i = 1; i <= N; i++) {
		Vec.push_back(pair<long long int, int>(D_T[i], i));
	}

	sort(Vec.begin(), Vec.end());

	NUM_T[T] = 1;

	for (int i = 0; i < N; i++) {
		int M = Vec[i].second;
		long long int distance = Vec[i].first;
		for (int j = 0; j < (int)Adj[M].size(); j++) {
			int H = Adj[M][j];
			if (D_T[M] + DIS[pair<int, int>(M, H)] == D_T[H]) { NUM_T[H] += NUM_T[M]; NUM_T[H] %= MODE; }
		}
	}
}

int main(void) {

	cin >> N >> M;
	cin >> S >> T;

	for (int i = 1; i <= M; i++) {
		cin >> U[i] >> V[i] >> D[i];
	}

	pair<int, int> P;
	for (int i = 1; i <= M; i++) {
		Adj[U[i]].push_back(V[i]);
		P.first = U[i]; P.second = V[i];  DIS[P] = D[i];
		Adj[V[i]].push_back(U[i]);
		P.first = V[i]; P.second = U[i]; DIS[P] = D[i];
	}

	//==================

	DIJKSTRA_S();

	for (int i = 1; i <= N; i++) {
		//cout << i << "  DIS_S= " << D_S[i] << endl;
	}

	DIJKSTRA_T();

	for (int i = 1; i <= N; i++) {
		//cout << i << "  DIS_T= " << D_T[i] << endl;
	}

	CALC_NUM_S(); //cout << endl;
	for (int i = 1; i <= N; i++) {
		//cout << i << "  NUM_S= " << NUM_S[i] << endl;
	}

	CALC_NUM_T();// cout << endl;
	for (int i = 1; i <= N; i++) {
		//cout << i << "  NUM_T= " << NUM_T[i] << endl;
	}

	//=======================

	long long int ans = 0;
	ans = (NUM_S[T] * NUM_T[S]) % MODE;

	long long int count = 0;

	long long int DISTANCE_ST = D_S[T];

	for (int i = 1; i <= N; i++) {
		if (D_S[i] == D_T[i] && D_S[i] + D_T[i] == DISTANCE_ST) { long long int tmp = (NUM_S[i] * NUM_T[i]) % MODE; tmp *= tmp; tmp %= MODE;  count += tmp; count %= MODE; }
	}


	for (int i = 1; i <= M; i++) {
		if (D_S[U[i]] + D[i] + D_T[V[i]] == DISTANCE_ST && D_S[U[i]]*2<DISTANCE_ST && (D_S[U[i]]+D[i])*2>DISTANCE_ST && D_T[V[i]]*2<DISTANCE_ST && (D_T[V[i]]+D[i])*2>DISTANCE_ST) { long long int tmp = (NUM_S[U[i]] * NUM_T[V[i]]) % MODE; tmp *= tmp; tmp %= MODE;  count += tmp; count %= MODE; }
		if (D_S[V[i]] + D[i] + D_T[U[i]] == DISTANCE_ST && D_S[V[i]]*2<DISTANCE_ST && (D_S[V[i]]+D[i])*2>DISTANCE_ST && D_T[U[i]]*2<DISTANCE_ST && (D_T[U[i]]+D[i])*2>DISTANCE_ST) { long long int tmp = (NUM_S[V[i]] * NUM_T[U[i]]) % MODE; tmp *= tmp; tmp %= MODE;  count += tmp; count %= MODE; }
	}

	ans = (ans + MODE - count) % MODE;

	cout << ans << endl;

	//system("pause");
	return 0;
}