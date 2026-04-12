#include<bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
typedef long long ll;
#define rep(i,n) for(ll i=0, i##_len=(n); i<i##_len; ++i)
using namespace std;
#define sz(x) ((int)(x).size())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
#define MEMSET(v, h) memset((v), h, sizeof(v))
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
#define pb push_back
#define mp make_pair
#define y0 y3487465
#define y1 y8687969
#define j0 j1347829
#define j1 j234892
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
const ll INF = 1LL<<60;
 
int main() {
	int h,w;
	cin >> h >> w;
  	int count = 0;
	vector<vector<char>> map(h, (vector<char>(w)));
    rep(i,h){
      rep(j, w){
        cin >> map[i][j];
      }
    }
	rep(i,h){
      rep(j, w){
        if(map[i][j] == '#') count++;
      }
    }
    if(count == h + w - 1) cout << "Possible" << endl;
	else cout << "Impossible" << endl;
}