#include <stdio.h>
#include <algorithm>
#include <vector>

#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:336777216")
using namespace std;

#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define ldb ldouble

typedef tuple<int, int, int> t3;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <db, db> pdd;

int IT_MAX = 1 << 18;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x1f3f3f3f3f3f3f3f;
const db ERR = 1e-10;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<n;i++)

const int MX = 200005;

int A[MX];

int main()
{
	int N;
	scanf("%d", &N);
	vector<int> L;
	for(int i = 1; i <= N; i++) scanf("%d", A+i), L.push_back(A[i]);
	sort(L.begin(), L.end());
	int med = L[N/2-1], nxt = L[N/2];

	for(int i = 1; i <= N; i++){
		if(med >= A[i]) printf("%d\n", nxt);
		else printf("%d\n", med);
	}
}
