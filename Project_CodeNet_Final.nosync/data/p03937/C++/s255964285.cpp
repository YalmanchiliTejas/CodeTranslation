#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()

inline int toInt(string s) {int v; istringstream sin(s);sin>>v; return v;}

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector< vector<int> > Mat;
typedef tuple<int, int, int, int> T;

const int MOD = (int)1e9+7;
const int INF = (int)1e9;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
const int ddx[] = {0, 1, 1, 1, 0, -1, -1, -1};
const int ddy[] = {1, 1, 0, -1, -1, -1, 0, 1};


int H, W, cnt = 0;
char A[9][9];

int main(){
    ios::sync_with_stdio(false);
	cin.tie(0);

    cin >> H >> W;
    rep(i, H) rep(j, W){
        char a;
        cin >> a;
        if(a == '#') cnt++;
    }

    if(cnt == H+W-1) cout << "Possible" << endl;
    else cout << "Impossible" << endl;

    return 0;
}