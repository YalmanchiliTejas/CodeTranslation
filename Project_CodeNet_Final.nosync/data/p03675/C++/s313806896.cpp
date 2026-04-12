#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define sz(x) (int)(x).size()
#define li long long
#define ld long double
#define x first
#define y second
#define pt pair<int, int>
#define pll pair<li, li>
#define forn(i, t) for(int i = 0; i < (t); i++)
#define fore(i, f, t) for(int i = (f); i < (t); i++)
#define forr(i, f, t) for(int i = (f) - 1; i >= (t); i--)
#define all(x) (x).begin(), (x).end()
#define ins insert

using namespace std;


const int INF = 1e9;
const int MOD = 1e9 + 7;
const li INF64 = 1e18;
const ld EPS = 1e-7;

mt19937 myrand(time(NULL));

const int N = 200 * 1000 + 13;

int n;
int a[N];


bool read(){
	if(scanf("%d", &n) != 1)
		return 0;
	forn(i, n)
		scanf("%d", &a[i]);
	return 1;
}


deque<int> b;


void solve(){
	b = deque<int>();
	forn(i, n)
		if (i % 2 == 0)
			b.pb(a[i]);
		else
			b.push_front(a[i]);
	
	if (n % 2 == 0){
		for (auto it = b.begin(); it != b.end(); ++it)
			printf("%d ", *it);
	}
	else{
		for (auto it = b.rbegin(); it != b.rend(); ++it)
			printf("%d ", *it);
	}
	printf("\n");
}


int main(){
	#ifdef _DEBUG
		freopen("input.txt", "r", stdin);
	#endif
	while(read())
		solve();
	return 0;
}