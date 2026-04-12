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
#include <fstream>
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

signed main() {
    string pat = "23456789TJQKA";
    while(1) {
        char c; cin >> c;
        if(c == '#') break;

        string vs[5][15];
        rep(i,0,4) rep(j,0,13) cin >> vs[i][j];
        int EW = 0, NS = 0, flr = 0;
        rep(turn,0,13) {
            int ma = -1, ma_suit = -1, idx = -1;
            char prev_suit = 127;
            rep(i,0,4) {
                int k = (i + flr) % 4;
                char suit = vs[k][turn][1];
                int val   = pat.find(vs[k][turn][0]);
                if(prev_suit == 127) prev_suit = suit;

                if(suit == c) {
                    if(ma_suit < val) {
                        ma_suit = val;
                        idx = k;
                    }
                }
                else if(suit == prev_suit) {
                    if(ma < val && ma_suit == -1) {
                        ma = val;
                        idx = k;
                    }
                }
            }
            // printf("turn %lld: winner = %lld\n", turn+1, idx);
            if(idx % 2) EW++;
            else NS++;
            flr = idx;
        }
        if(EW < NS) printf("NS %lld\n", NS - 6);
        else printf("EW %lld\n", EW - 6);
    }
    return 0;
}