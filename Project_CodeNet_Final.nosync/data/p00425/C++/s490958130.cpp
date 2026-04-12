// ?????¬???????????¬??????

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

// Dice library
//         ???????????????
//         ??? back ???
//         ???  (5) ???
// ??????????????????????????????????????¬????????????
// ??? left ??? top  ???right ???bottom???
// ???  (4) ???  (1) ???  (2) ???  (3) ???
// ??????????????????????????????????????´????????????
//         ???front ???
//         ???  (0) ???
//         ???????????????
enum Direction {
    NORTH = 0, SOUTH = 1, EAST = 2, WEST = 3, ROT_R = 4, ROT_L = 5,
};

enum View {
    FRONT = 0, TOP = 1, RIGHT = 2, BOTTOM = 3, LEFT = 4, BACK = 5,
};

struct Dice {
    vector<int> value;
    Dice(int front, int top, int right) {
        int sum = 7;
        assert(front + top   != sum);
        assert(top   + right != sum);
        assert(front + right != sum);
        value = {front, top, right, sum-top, sum-right, sum-front};
    }

    void rotate(int dir) {
        vector<int> fnc, swp(6);
        if(dir == NORTH) fnc = {1, 5, 2, 0, 4, 3};
        if(dir == SOUTH) fnc = {3, 0, 2, 5, 4, 1};
        if(dir == EAST ) fnc = {0, 2, 3, 4, 1, 5};
        if(dir == WEST ) fnc = {0, 4, 1, 2, 3, 5};
        if(dir == ROT_R) fnc = {4, 1, 0, 3, 5, 2};
        if(dir == ROT_L) fnc = {2, 1, 5, 3, 0, 4};

        for(int i=0; i<6; i++) swp[ fnc[i] ] = value[i];
        swap(value, swp);
    }

    int get_value(int view) {
        return value[view];
    }
};

signed main() {
    int N;
    vector<string> pat = {"North", "South", "East", "West", "Right", "Left"};
    while(cin >> N, N) {
        Dice dice(2, 1, 3);
        int ans = 1;
        rep(i,0,N) {
            string s; cin >> s;
            int c = 0;
            while(pat[c] != s) c++;
            dice.rotate(c);
            ans += dice.get_value(TOP);
        }
        cout << ans << endl;
    }
    return 0;
}