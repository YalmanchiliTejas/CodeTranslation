#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct Card {
	char suit; int rank;
	Card() : suit('.'), rank(0) {}
	Card(string s) {
		suit = s[1];
		
		if (isdigit(s[0]))    rank = s[0] - '0';
		else if (s[0] == 'T') rank = 10;
		else if (s[0] == 'J') rank = 11;
		else if (s[0] == 'Q') rank = 12;
		else if (s[0] == 'K') rank = 13;
		else if (s[0] == 'A') rank = 14;
	}
};

int main() {
	cin.sync_with_stdio(false); cin.tie(0);
	cin.exceptions(cin.failbit);

	for (;;) {
		char trump; cin >> skipws >> trump; if (trump == '#') break;
		vector<vector<Card>> v(13, vector<Card>(4));
		vector<int> w(4);
		rep(j, 0, 4) {
			rep(i, 0, 13) {
				string s; cin >> s;
				v[i][j] = Card(s);
			}
		}
		int d = 0;
		rep(i, 0, 13) {
			Card dcard = v[i][d];
			int wid = d;
			rep(j, 0, 4) if (j != wid) {
				Card ncard = v[i][j], wcard = v[i][wid];
				if (ncard.suit == trump && wcard.suit != trump || 
					ncard.suit == wcard.suit && ncard.rank > wcard.rank)
					wid = j;
			}
			w[wid]++;
			d = wid;
		}
		
		if (w[0] + w[2] > w[1] + w[3]) {
			cout << "NS " << (w[0] + w[2] - 6) << endl;
		} else {
			cout << "EW " << (w[1] + w[3] - 6) << endl;
		}
	}
}

