// 2:50
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <utility>
#include <vector>
#include <set>
#include <map>
#include <deque>
#include <tuple>
using namespace std;
using ll = long long;
#define for1(i,n) for (ll i=0;i<(n);(i)++)
#define for2(i,m,n) for (ll (i)=(m);(i)<(n);(i)++)
#define for3(i,m,n,d) for (ll (i)=(m);(i)<(n);(i)+=(d))
#define INF (1LL << 60)
#define STRING(str) #str
#define DEBUG 0
#if DEBUG
    #define dump(var) dump2(STRING(var), var)
#else
    #define dump(var)
#endif

template <typename T>
void dump2(const string& name, const T& value)
{
    cerr << name << ": " << value << endl;
}
void dump2(const string& name, const tuple<ll,ll,ll>& value)
{
    ll a,b,c;
    tie(a,b,c) = value;
    cerr << name << ": (" << a << ", " << b << ", " << c << ")" << endl;
}

template <typename T>
void print(const T& value)
{
    cout << value << endl;
}


void solve()
{
    char c;
    cin >> c;
    string s = "aeiou";
    for (auto c1 : s) {
        if (c == c1) {
            print("vowel");
            return;
        }
    }
    print("consonant");
}

int main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    solve();
}
