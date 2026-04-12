//
//AtCoder Beginner Contest 107
//B
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cmath>
#include <ctime>
#include <queue>
#include <map>
#include <set>
#include <tuple>
#include <functional>
#include <cassert>
#include <bitset>
#include <numeric>

using namespace std;

#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=(ll)(b);i--)
#define ALL(x) (x).begin(),(x).end()
#define RALL(x) (x).rbegin(),(x).rend()
#define SIZE(x) (int)(x).size()
#define SIZEL(x) (ll)(x).size()
#define MSG(a) cout << #a << " " << a << endl;

using ll = long long;
using ld = long double;
using Graph = vector<vector<int>>;

const double PI = 3.14159265358979323846;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

ll gcd(ll x, ll y) { return (x % y)? gcd(y, x % y): y; }    //最大公約数
ll lcm(ll x, ll y) { return x / gcd(x, y) * y; }            //最小公倍数

int main()
{
    int H,W;
    cin >> H >> W;

    vector<string> a;
    REP(h, H) {
        string tmp;
        cin >> tmp;
        if (count(tmp.begin(), tmp.end(), '#') > 0){
            a.push_back(tmp);
        }
    }
    vector<int> wSkip(W,1);
    REP(w, W){
        REP(h, a.size()){
            if (a[h][w]=='#') wSkip[w]=0;
        }
    }

    REP(h, a.size()){
        REP(w, W){
            if (wSkip[w]==1) continue; 
            cout << a[h][w];
        }
        cout << endl;
    }
    return 0;
}
