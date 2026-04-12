#include <stdio.h>
#include <bits/stdc++.h>			

#define pb push_back
#define pf push_front
#define pp pop_back
#define sz(a) (int)(a.size())
#define mp make_pair
#define F first
#define S second
#define next _next
#define prev _prev
#define left _left
#define right _right
#define y1 _y1
#define all(x) x.begin(), x.end()
#define what_is(x) #x << " is " << (x)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int N = (int)1e6 + 123;
const ll INF = (ll)1e18 + 123;
const int inf = (int)1e9 + 123;
const int MOD = (int)1e9 + 7;

void megaRandom() {
	unsigned int FOR;
 	asm("rdtsc" : "=A"(FOR));
  srand(FOR);
}

int n, m;
char ch[10][10];

void no() {
	cout << "Impossible";
	exit(0);
}

bool u[10][10];

int main() {
	megaRandom();
	cin >> n >> m;
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= m; j ++)
			cin >> ch[i][j];
	int x = 1, y = 1;
	while(x != n || y != m) {
		u[x][y] = 1;
		bool ok1 = 0, ok2 = 0;
		if(x + 1 <= n && ch[x + 1][y] == '#')
			ok1 = 1;
		if(y + 1 <= m && ch[x][y + 1] == '#')
			ok2 = 1;
		if(ok1 + ok2 != 1)	
			no();
		if(ok1) x++;
		else    y ++;
	}
	u[x][y] = 1;
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= m; j ++)
			if(!u[i][j] && ch[i][j] == '#')
				no();
	cout << "Possible";
	return 0;  
}
