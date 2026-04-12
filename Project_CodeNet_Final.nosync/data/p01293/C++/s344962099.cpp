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

string cvt = "TJQKA";
string sts = "SHDC";
int board[5][15];
int kind[5][15];

string detail[] = {"North", "East", "South", "West"};

signed main() {
    string trump;
    while(cin >> trump, trump != "#") {
        int target = sts.find(trump);
        rep(i,0,4) rep(j,0,13) {
            string inp; cin >> inp;
            string val  = inp.substr(0, 1);
            string suit = inp.substr(1, 1);

            int f = cvt.find(val);
            if(f == string::npos) board[i][j] = val[0] - '0';
            else board[i][j] = f + 15;

            kind[i][j] = sts.find(suit);
        }

        int leader = 1;
        int pns = 0, pew = 0;
        rep(i,0,13) {
            int ma = -1, winner = 0;
            rep(j,0,4) {
                int k = (j+leader) % 4;
                int temp = 0;
                if(kind[k][i] == target) temp += 100;
                else if(kind[k][i] != kind[leader][i]) continue;
                temp += board[k][i];

                if(ma < temp) {
                    ma = temp;
                    winner = k;
                }
            }
            if(winner == 0 || winner == 2) pns++;
            else pew++;

            // cout << "winner: " << detail[winner] << endl;
            leader = winner;
        }
        if(pns < pew) {
            cout << "EW " << pew - 6 << endl;
        }
        else cout << "NS " << pns - 6 << endl;
    }
    return 0;
}