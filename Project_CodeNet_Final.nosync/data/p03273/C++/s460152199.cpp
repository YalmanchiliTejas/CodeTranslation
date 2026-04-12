#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vb = vector<bool>;
using vs = vector<string>;
using msi = map<string, int>;
using mii = map<int, int>;
using psi = pair<string, int>;
using pii = pair<int, int>;
using vlai = valarray<int>;
#define rep(i,n) for(int i=0;i<n;i++)
#define range(i,s,n) for(int i=s;i<n;i++)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define fs first
#define sc second
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define INF 1E9
#define EPS 1E-9
#define MOD 1000000007
#define PI 3.1415926535897932384

template<class S, class T>ostream& operator<<(ostream&os, pair<S, T>p) { os << "[" << p.first << ", " << p.second << "]"; return os; };
template<class S>auto&operator<<(ostream&os, vector<S>t) { bool a = 1; for (auto s : t) { os << (a ? "" : " ") << s; a = 0; } return os; }

//int dx[]={1,1,1,0,-1,-1,-1,0},dy[8]={1,0,-1,-1,-1,0,1,1,1};
//
constexpr ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }


int main() {
	int h, w;
	vvi vv;
	char c;
	cin >> h >> w;
	vb vbb(w);
	rep(i, h) {
		vi v;
		bool b=false;
		rep(j, w) {
			cin >> c;
			if (c == '#') {
				b = true;
				v.push_back(1);
				vbb[j] = true;
			}
			else v.push_back(0);
		}
		if (b)vv.push_back(v);
	}
	rep(i,vv.size()) {
		rep(j, w) {
			if(vbb[j])cout << (vv[i][j] == 1 ? "#" : ".");
		}
		cout << endl;
	}
	
}
