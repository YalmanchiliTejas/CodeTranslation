// テ・ツ淞コテヲツ慊ャテ」ツδ?」ツδウテ」ツδ療」ツδャテ」ツδシテ」ツδ?

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
#include <functional>
using namespace std;

#define rep(i,a,n) for(int (i)=(a); (i)<(n); (i)++)
#define repq(i,a,n) for(int (i)=(a); (i)<=(n); (i)++)
#define repr(i,a,n) for(int (i)=(a); (i)>=(n); (i)--)
#define int long long int

template<typename T> void chmax(T &a, T b) {a = max(a, b);}
template<typename T> void chmin(T &a, T b) {a = min(a, b);}
template<typename T> void chadd(T &a, T b) {a = a + b;}

typedef pair<int, int> pii;
typedef long long ll;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
constexpr ll INF = 1001001001001001LL;
constexpr ll MOD = 1000000007LL;

int N;
int H[20], W[20];
int dp[1 << 16];
vector<string> board;
const string alph = "RGB";

int solve() {
    queue<int> q; q.push(0);
    while(!q.empty()) {
        int bit = q.front(); q.pop();
        if(bit == (1 << 16) - 1) return dp[bit];
        // i テァツ閉ェテァツ崢ョテ」ツ?ョテ」ツつケテ」ツつソテ」ツδウテ」ツδ療」ツ?ョテ・ツキツヲテ、ツクツ甘」ツつ?(j, k) テ」ツ?ォテ・ツ青暗」ツつ湘」ツ?崚」ツ?ヲティツ可イ s テ」ツ?ァテヲツ環シテ」ツ??
        rep(i,0,N) rep(j,-H[i]+1,4) rep(k,-W[i]+1,4) rep(s,0,3) {
            int nbit = bit;
            rep(x, max(j,0LL), min(j+H[i],4LL)) rep(y, max(k,0LL), min(k+W[i],4LL)) {
                int idx = x * 4 + y;
                if(board[x][y] == alph[s]) nbit |= (1 << idx);
                else if(nbit >> idx & 1) nbit ^= (1 << idx);
            }
            if(dp[nbit] < 0) {
                dp[nbit] = dp[bit] + 1;
                q.push(nbit);
            }
        }
    }
    return 0;
}

signed main() {
    memset(dp, -1, sizeof(dp));
    dp[0] = 0;

    cin >> N;
    rep(i,0,N) cin >> H[i] >> W[i];
    rep(i,0,4) {
        string s; cin >> s;
        board.push_back(s);
    }
    cout << solve() << endl;
    return 0;
}