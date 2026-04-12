#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

#define REP(i, m, n) for(int i=int(m);i<int(n);i++)
#define EACH(i, c) for (auto &(i): c)
#define all(c) begin(c),end(c)
#define EXIST(s, e) ((s).find(e)!=(s).end())
#define SORT(c) sort(begin(c),end(c))
#define pb emplace_back
#define MP make_pair
#define SZ(a) int((a).size())

//#define LOCAL 1
#ifdef LOCAL
#define DEBUG(s) cout << (s) << endl
#define dump(x)  cerr << #x << " = " << (x) << endl
#define BR cout << endl;
#else
#define DEBUG(s) do{}while(0)
#define dump(x) do{}while(0)
#define BR
#endif


//改造
typedef long long int ll;
using namespace std;


//ここから編集する
ll mod = 1000000007;


int main() {
    //入力
    int h, w;
    cin >> h >> w;
    vector<vector<char> > v(h, vector<char>(w));
    int cnt = 0;
    REP(i, 0, h) {
        REP(j, 0, w) {
            char inp;
            cin >> inp;
            v[i][j] = inp;
            if (inp == '#') {
//                v[i][j] = 1;
                cnt++;
            }
//            } else {
//                v[i][j] = 0;
//            }

        }
    }
    //#の数がH+W-1でなければだめ
    int x, y;
    x = y = 0;
    if (cnt != h + w - 1) {
        cout << "Impossible" << endl;
        return 0;
    }
    while (true) {
        //右か下に#があるかを調べる
        //両方に#があればだめ
        if ((x + 1 < h && v[x + 1][y] == '#') && (y + 1 < w && v[x][y + 1] == '#')) {
            cout << "Impossible" << endl;
            return 0;
        }
        //#が右か下になければだめ
        if ((x + 1 < h && v[x + 1][y] != '#') && (y + 1 < w && v[x][y + 1] != '#')) {
            cout << "Impossible" << endl;
            return 0;
        }
        //#がある方に進む
        if ((x + 1 < h && v[x + 1][y] == '#') && !(y + 1 < w && v[x][y + 1] == '#')) {
            x++;
//            y++;
        } else if (!(x + 1 < h && v[x + 1][y] == '#') && (y + 1 < w && v[x][y + 1] == '#')) {
            y++;
//            x++;
        }
        //今いる地点が右下ならゴール
        if (x == h - 1 && y == w - 1) {
            cout << "Possible" << endl;
            return 0;
        }
    }
}
