#include <bits/stdc++.h> // PLEASE

using namespace std;
typedef long long ll;
typedef pair <int, int> pp;
#define MAXN 300005
#define MAXM 1005
#define MAXP 25
#define INF 2000000000
#define A first
#define B second
#define MP make_pair
#define PB push_back
#define FOR(i, a, b) for(int i =(a); i <=(b); ++i)
#define re(i, n) FOR(i, 1, n)
#define rep(i, n) for(int i = 0;i <(n); ++i)
#define fore(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)

const ll MOD = 1e9+7;
int N;
int ar[MAXN];
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for(int i=1; i<=N; i++) cin >> ar[i];
	if((N%2) == 0) {
		for(int i=N; i>=2; i-=2) printf("%d ", ar[i]);
		for(int i=1; i<=N; i+=2) printf("%d ", ar[i]);
		printf("\n");
	}
	else {
		for(int i=N; i>=1; i-=2) printf("%d ", ar[i]);
		for(int j=2; j<=N; j+=2) printf("%d ", ar[j]);
		printf("\n");
	}
	
}