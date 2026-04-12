#include <iostream>
#include <map>
#include <algorithm>

#define rep(i, n) for(int i = 0; i < (n); ++i)

using namespace std;

typedef pair<int, int> P;

const int t[6][4] = {
	{1, 2, 4, 3},
	{0, 3, 5, 2},
	{0, 1, 5, 4},
	{0, 4, 5, 1},
	{0, 2, 5, 3},
	{1, 3, 4, 2},
};

P north(const P& p){
	int a = p.first;
	int b = p.second;
	int c = t[a][b];
	int d = find(t[c], t[c] + 4, 5 - a) - t[c];
	return P(c, d);
}

P east(const P& p){
	int a = p.first;
	int b = p.second;
	int c = t[a][(b + 3) % 4];
	int d = find(t[c], t[c] + 4, t[a][b]) - t[c];
	return P(c, d);
}

P west(const P& p){
	int a = p.first;
	int b = p.second;
	int c = t[a][(b + 1) % 4];
	int d = find(t[c], t[c] + 4, t[a][b]) - t[c];
	return P(c, d);
}

P south(const P& p){
	int a = p.first;
	int b = p.second;
	int c = t[a][(b + 2) % 4];
	int d = find(t[c], t[c] + 4, a) - t[c];
	return P(c, d);
}

P right(const P& p){
	int a = p.first;
	int b = p.second;
	return P(a, (b + 1) % 4);
}

P left(const P& p){
	int a = p.first;
	int b = p.second;
	return P(a, (b + 3) % 4);
}

map<char, P (*)(const P&)> f = {
	{'N', north},
	{'E', east},
	{'W', west},
	{'S', south},
	{'R', right},
	{'L', left}
};

int n;

int main(){
	while(1){
		cin >> n;
		if(!n){
			break;
		}

		P p(0, 0);
		int ans = 1;
		rep(i, n){
			string s;
			cin >> s;
			p = f[s[0]](p);
			ans += p.first + 1;
		}
		cout << ans << endl;
	}
	return 0;
}