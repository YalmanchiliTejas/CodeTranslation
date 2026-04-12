#include <bits/stdc++.h>
#define s second
#define f first
#define pb push_back
#define endl '\n'
using namespace std;


typedef long long ll;
typedef pair<int,int> pii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;
const ll MOD = 1e9 + 7;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int N;
	cin >> N;

	vector<ll> V(N);

	for(auto &a : V) cin >> a;

	vector<ll> S(N);

	S[N-1] = V[N-1];

	for(int i = N - 2; i >= 0; i--) S[i] = (V[i] + S[i+1]) % MOD;

	ll ans = 0;

//	for(int i = 0; i < N; i++) cout << S[i] << " "; cout << endl;

	vector<int> F(N - 1);

	for(int i = 0; i < N - 1; i++) F[i] = (V[i]*S[i+1]) % MOD;

	for(int i = 0; i < N - 1; i++){
		ans = (ans + F[i]) % MOD;
	}

	cout << ans << endl;

	return 0;
}
