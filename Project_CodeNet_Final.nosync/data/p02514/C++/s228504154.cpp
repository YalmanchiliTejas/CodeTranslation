#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>

#define REP(i,n) for(int i=0;i<int(n);++i)
#define REV(i,n) for(int i=(n)-1;i>=0;--i)
#define ALL(c) (c).begin(), (c).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<string> vs;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef vector<ll> vl;
typedef vector<double> vd;

int dist(pii a, pii b) {
	return abs(a.first - b.first) + abs(a.second - b.second);
}

int main() {
	int w, h;
	while(cin >> w >> h && w){
		int n = 0;
		pii S, G;
		vector<vii> z(1);
		REP(i,h)REP(j,w){
			string s;
			cin >> s;
			if (s[0] == 'S') S = pii(i, j);
			else if (s[0] == 'G') G = pii(i, j);
			else if (s[0] != '.') {
				int l = atoi(s.c_str());
				n = max(n, l);
				z.resize(n+1);
				z[l].push_back(pii(i, j));
			}
		}
		z[0].assign(1, S);
		z.push_back(vii(1, G));
		vi w[2];
		w[0].assign(1, 0);
		REP(i,z.size()-1){
			w[1-i%2].assign(z[i+1].size(), 1<<29);
			REP(j,z[i+1].size())REP(k,z[i].size()){
				w[1-i%2][j] = min(w[1-i%2][j], w[i%2][k] + dist(z[i][k], z[i+1][j]));
			}
		}
		cout << w[1-z.size()%2][0] << endl;
	}

	return 0;
}