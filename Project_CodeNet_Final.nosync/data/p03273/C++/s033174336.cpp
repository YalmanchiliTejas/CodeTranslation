#include <iostream>
#include <vector>
#include <string>
#include <bitset>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
#define REP(i,n) for(int i=0;i<n;i++)
#define pb push_back


// vectorの中身をcout << vs;で表示
template <class T>
ostream &operator<<(ostream &o, const vector<T> &v)
{
    o << "{";
    for (int i = 0; i < (int)v.size(); i++) o << (i > 0 ? ", " : "") << v[i];
    o << "}";
    return o;
}

int main(void) {
	// cin, coutの結びつきを解除し、速くする
	cin.tie(0);
   	ios::sync_with_stdio(false);

	int h, w; cin >> h >> w;

	vector<string> vs;
	REP(i, h) {
		string str;
		cin >> str;
		vs.pb(str);
	}


	bitset<100> bsh; // bitsetは〇〇コンテナないので、固定長
	bitset<100> bsw;

	REP(i, h) {
		REP(j ,w) {
			if (vs.at(i).at(j) == '#') {
				bsh[i] = 1;
				break;
			}
		}
	}

	
	REP(j, w) {
		REP(i, h) {
			if (vs.at(i).at(j) == '#') {
				bsw[j] = 1;
				break;
			}
		}
	}

	
	REP(i, h) {
		REP(j ,w) {
			if (bsh[i] == 0) {
				break;
			}
			if (bsw[j] == 1) {
				cout << vs.at(i).at(j);
				if (j == w - 1) cout << endl;
			} else {
				if (j == w - 1) cout << endl;
			}
		}
	}
	cout << endl;


}

