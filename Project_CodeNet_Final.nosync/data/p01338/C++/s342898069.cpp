// 基本テンプレート
 
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <cstring>
#include <deque>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#include <set>
#include <complex>
#include <cmath>
#include <limits>
#include <cfloat>
#include <climits>
#include <ctime>
#include <cassert>
#include <numeric>
#include <fstream>
#include <functional>
using namespace std;
 
#define rep(i,a,n) for(int (i)=(a); (i)<(n); (i)++)
#define repq(i,a,n) for(int (i)=(a); (i)<=(n); (i)++)
#define repr(i,a,n) for(int (i)=(a); (i)>=(n); (i)--)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define int long long int
 
template<typename T> void chmax(T &a, T b) {a = max(a, b);}
template<typename T> void chmin(T &a, T b) {a = min(a, b);}
template<typename T> void chadd(T &a, T b) {a = a + b;}
 
typedef pair<int, int> pii;
typedef long long ll;
 
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
const ll INF = 1001001001001001LL;
const ll MOD = 1000000007LL;

const int S = 4000;
const int N = 5;
using vector2D = vector< vector<int> >;

int base_x[] = {0, 0, 1, 1};
int base_y[] = {0, 1, 0, 1};
vector< vector<int> > cand;

void init_cand() {
    for(int i=0; i<4; i++) {
        for(int j=0; j<4; j++) {
            for(int k=0; k<4; k++) {
                for(int x=0; x<4; x++) {
                    vector<int> v = {i, j, k, x};
                    cand.push_back(v);
                }
            }
        }
    }
}

int get_hash(vector<int> v) {
    int ret = 0;
    for(int i=0; i<N; i++) {
        ret *= 5;
        ret += v[i];
    }
    return ret;
}

int get_point(vector<int> v) {
    int ret = 0;
    vector<int> pts = {0, 0, 60, 70, 80};
    for(int i=0; i<N; i++) {
        ret += pts[ v[i] ];
    }
    return ret;
}

int solve(vector2D board) {
    map< vector<int>, int > dp, swp;
    dp[ board[0] ] = 0;
    for(int k=0; k<4; k++) {
        for(auto e : dp) {
            vector<int> pat = e.first;
            for(auto v : cand) {
                vector< vector<int> > tmp(2, vector<int>(N));
                tmp[0] = pat;
                tmp[1] = board[k+1];

                for(int i=0; i<4; i++) {
                    int shift = v[i];
                    for(int j=0; j<4; j++) {
                        int x = base_x[j], y = base_y[j] + i;

                        if(tmp[x][y] == 0) continue;
                        tmp[x][y] = (tmp[x][y] - 1 + shift) % 4 + 1;
                    }
                }

                int score = dp[pat] + get_point(tmp[0]);
                if(k == 3) score += get_point(tmp[1]);

                vector<int> nxt = tmp[1];
                if(!swp.count(nxt) || swp[nxt] < score) {
                    swp[nxt] = score;
                }
            }
        }

        swap(dp, swp);
    }

    int ans = 0;
    for(auto x : dp) {
        chmax(ans, x.second);
    }
    return ans;
}
 
signed main() {
    init_cand();
    int T; cin >> T;
    while(T--) {
        vector2D board(N, vector<int>(N));
        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) {
                cin >> board[i][j];
            }
        }

        cout << solve(board) << endl;
    }
    return 0;
}
