#include <ios>
#include <iomanip>
#include <iostream>
#include <functional>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <climits>

using namespace std;
typedef long long int ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define MOD 1000000007
#define INF (1e9)
#define PI (acos(-1))
#define print(x) cout << x << endl
#define yes cout << "Yes" << endl
#define YES cout << "YES" << endl
#define no cout << "No" << endl
#define NO cout << "NO" << endl

ll gcd(ll a, ll b) { return b ? gcd(b,a%b) : a;}
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
typedef pair <ll,ll> P;

int main()
{
    ll H, W;
    cin >> H >> W;
    ll mat[H][W];
    rep(i, H) {
        string s;
        cin >> s;
        rep(j, W) {
            if (s[j] == '.') mat[i][j] = 0;
            else mat[i][j] = 1;
        }
    }
    rep(i, H) {
        bool flag = false;
        rep(j, W) {
            if (mat[i][j] > 0) flag = true;
        }
        if (!flag) {
            rep(j, W) {
                mat[i][j] = -1;
            }
        }
    }
    rep(j, W) {
        bool flag = false;
        rep(i, H) {
            if (mat[i][j] > 0) flag = true;
        }
        if (!flag) {
            rep(i, H) {
                mat[i][j] = -1;
            }
        }
    }
    rep(i, H) {
        bool flag = false;
        rep(j, W) {
            if (mat[i][j] == 0) cout << ".";
            else if (mat[i][j] == 1) cout << "#"; 
            
            if (mat[i][j] != -1) flag = true;
        }
        if (flag) cout << endl;
    }
    return 0;
}
