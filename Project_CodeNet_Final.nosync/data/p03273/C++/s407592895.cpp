/*
    Author:zeke
    
    pass System Test!
    GET AC!!
*/
#include <iostream>
#include <queue>
#include <vector>
#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <algorithm>
#include <functional>
#include <cmath>
#include <queue>
#include <set>
#include <stack>
#include <deque>
#include <map>
#include <iomanip>
#include <math.h>
#include <utility>
#include <stack>
#include <bitset>
using ll = long long;
using ld = long double;
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define rep3(var, min, max) for (ll(var) = (min); (var) < (max); ++(var))
#define repi3(var, min, max) for (ll(var) = (max)-1; (var) + 1 > (min); --(var))
#define Mp(a, b) make_pair((a), (b))
#define F first
#define S second
#define Icin(s) \
    ll(s);      \
    cin >> (s);
#define Scin(s) \
    ll(s);      \
    cin >> (s);
template <class T>
bool chmax(T &a, const T &b)
{
    if (a < b)
    {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
bool chmin(T &a, const T &b)
{
    if (b < a)
    {
        a = b;
        return 1;
    }
    return 0;
}
typedef pair<ll, ll> P;
typedef vector<ll> V;
typedef vector<V> VV;
typedef vector<P> VP;
ll mod = 1e9 + 7;
unsigned long long MOD = 1e9 + 7;
ll INF = 1e18;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll h,w;
    cin >> h>>w;
    vector<vector<char>> vec(h, vector<char>(w));
    rep(i,h){
        string s;
        cin >> s;
        rep(j,w){
            vec[i][j] = s[j];
        }
    }
    V H;
    V W;
    rep(i,h){
        bool Ha = true;
        rep(j,w){
            if(vec[i][j]=='#'){
                Ha = false;
              
            }
        }
        if(Ha)
            H.push_back(i);
    }
    rep(i, w)
    {
        bool Ha = true;
        rep(j, h)
        {
         
            if (vec[j][i] == '#')
            {
              
                Ha= false;
            }
        }
        if (Ha)W.push_back(i);
    }
    
    rep(i,h){
        rep(j,w){
            if(binary_search(all(H),i)||binary_search(all(W),j)){
                continue;
            }
            cout << vec[i][j];
        }
        if (i!=h && !binary_search(all(H), i+1))
            cout << endl;
    }
}
