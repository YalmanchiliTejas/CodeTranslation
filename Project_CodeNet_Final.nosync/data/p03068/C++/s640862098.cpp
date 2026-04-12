#include<bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define RREP(i, n) for (int i = n - 1; i >= 0; --i)
#define INF 100000000
#define pb push_back
#define all(x) (x).begin(),(x).end()

typedef long long ll;

int main() {
	int N; cin >> N;
	string S; cin >> S;
	int B; cin >> B;

	char t = S[B-1];
	
	REP(i, N){
		if (S[i] == t){
			cout << S[i];
		} else {
			cout << '*';
		}
	}

	cout << endl;


	return 0;
}