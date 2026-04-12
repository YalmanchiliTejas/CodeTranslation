#include <bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define allv(V) ((V).begin()),((V).end())
#define sorv(V) sort(allv(V))
#define univ(V) (V).erase(unique(allv(V)),(V).end())
#define revv(V) reverse(allv(V))
#define sz(V) ((int)(V).size())
#define upmin(a,b) (a)=min((a),(b))
#define upmax(a,b) (a)=max((a),(b))
#define rb(x) ((x)&(-(x)))
#define INF (0x3f3f3f3f)
#define INFLL (0x3f3f3f3f3f3f3f3fll)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 205;

int A[MAXN];

vector<int> Ans;

int N;

int main() {
	ios::sync_with_stdio(false);

	cin >> N;
	for(int i = 1; i <= N; i++) cin >> A[i];
	
	for(int t = 0; t <= N; t++) {
		vector<int> V;
		for(int i = 2; i <= N; i++) {
			if(A[i-1] > A[i]) {
				swap(A[i-1], A[i]);
				V.eb(i-1);
			}
		}
		if(V.empty()) break;

		for(int t = 0; t < V[0]; t++) Ans.eb(1);
		Ans.eb(N-1);
		for(int i = 1; i < sz(V); i++) {
			for(int t = 0; t < V[i]-V[i-1]; t++) Ans.eb(1);
			Ans.eb(N-1);
		}
		for(int t = 0; t < N-V.back(); t++) Ans.eb(1);
	}

	printf("%d\n", sz(Ans));
	for(int v : Ans) printf("%d\n", v);
	return 0;
}