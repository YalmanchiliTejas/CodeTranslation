/// Containers Start
#include <algorithm>
#include <bitset>
#include <cstdlib>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>
/// C Header Files
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <math.h>
#include <stdio.h>
/// Containers End

using namespace std;

/// Math Start
#define PI acos(-1.0)
#define Pi 3.141592653589793
#define EPS (1e-7)
#define INF (0x3f3f3f3f)
#define MAX_V 100100
/// Math End

/// Extra Start
#define nn '\n'
#define pb push_back
#define SS stringstream
#define ull unsigned long long
#define mod 1000000007
#define SIZE 2000001
#define _cin                                                                   \
    ios_base::sync_with_stdio(0);                                              \
    cin.tie(0);
#define sz(a) int((a).size())
#define space " "
#define All(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define Ignore cin.ignore()
#define StringToInt                                                            \
    if (!(istringstream(s) >> n))                                              \
        n = 0;
#define SORT(c) sort(All((c)))
#define RSORT(c) sort(rall((c)))
/// Extra End

/// Functions Start
template <class T> T gcd(T a, T b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

template <class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }

template <class T> string converter(T n) {
    SS x;
    x << n;
    return x.str();
}

string itos(int a) {
    string s = to_string(a);
    return s;
}
string itos(long long a) {
    string s = to_string(a);
    return s;
}

template <class T> T mod_pow(T x, T n) {
    T res = 1;
    while (n > 0) {
        if (n & 1)
            res = res * x % mod;
        x = x * x % mod;
        n >>= 1;
    }
    return res;
}

std::vector<std::string> split(const std::string &str, char sep) {
    std::vector<std::string> v;
    std::stringstream ss(str);
    std::string buffer;
    while (std::getline(ss, buffer, sep)) {
        v.push_back(buffer);
    }
    return v;
}

#define rep(i, n) for (int i = 0; i < n; i++)
#define repr(i, n) for (int i = n - 1; i >= 0; i++)
#define for_arr(array) for (auto &i : array)
#define Cini(a)                                                                \
    int a;                                                                     \
    cin >> a;
#define Cinii(a, b)                                                            \
    int a, b;                                                                  \
    cin >> a >> b;
#define Ciniii(a, b, c)                                                        \
    int a, b, c;                                                               \
    cin >> a >> b >> c;
#define Cins(s)                                                                \
    string s;                                                                  \
    cin >> s;
#define Cinss(s1, s2)                                                          \
    string s1, s2;                                                             \
    cin >> s1 >> s2;
#define Cinc(c)                                                                \
    char c;                                                                    \
    cin >> c;
/// Functions End

/// Array Start
#define SET(a) memset(a, -1, sizeof a)
#define CLR(a) memset(a, 0, sizeof a)
#define MEM(a, val) memset(a, val, sizeof a)
/// Array End

/// Graph Start
struct edge {
    int from, to;
    long long cost;
};
/// Graph End

/// Debug Start
#define deb(x) cout << #x << ": " << x << endl
#define deb2(x, y) cout << #x << ": " << x << '\t' << #y << ": " << y << endl
#define deb3(x, y, z)                                                          \
    cout << #x << ": " << x << '\t' << #y << ": " << y << '\t' << #z << ": "   \
         << z << endl
/// Debug End

/// TypeDef Start
typedef long long int ll;
typedef map<string, int> msi;
typedef map<int, int> mii;
typedef map<ll, ll> mll;
typedef map<char, int> mci;
typedef map<int, string> mis;
typedef pair<int, int> pii;
typedef pair<string, int> psi;
typedef pair<string, string> pss;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<char> vc;
typedef vector<bool> vb;
typedef vector<pii> vii;
/// TypeDef End

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

/**>>>>>>>>>>>>>>>>>>> END <<<<<<<<<<<<<<<<<<**/

/// topcoder template

bool mysort(pair<int, int> a, pair<int, int> b) { return a.second < b.second; }
bool _mysort(pair<char, int> a, pair<char, int> b) {
    if (a.second != b.second)
        return a.second < b.second;
    else {
        return a.first < b.first;
    }
}

int main(void) {
    cin.sync_with_stdio(false);
    cin.tie(0);

    Cini(n);
    if(n==3 or n==5 or n==7){
        cout << "YES" << nn;
        return 0;
    }else{
        cout << "NO" << nn;
        return 0;
    }

    return 0;
}