#define _CRT_SECURE_NO_WARNINGS
// #define POJ
#ifdef POJ
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <cfloat>
#include <cstring>
#include <climits>
#include <utility>
#include <set>
#include <map>
#else
#include <bits/stdc++.h>
#include <unordered_set>
#include <random>
#endif
using namespace std;
#define rep(i, a, n) for (int i = a; i < n; i++)
#define per(i, a, n) for (int i = n - 1; i >= a; i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define sz(x) ((int)(x).size())
typedef vector<int> vi;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef double db;
#ifndef POJ
mt19937 mrand(random_device{}());
int rnd(int x) { return mrand() % x; }
#endif
const ll mod = 1000000007;
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec){ os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }
template<typename T> ostream &operator<<(ostream &os, const deque<T> &vec){ os << "deq["; for (auto v : vec) os << v << ","; os << "]"; return os; }
template<typename T> ostream &operator<<(ostream &os, const set<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T> ostream &operator<<(ostream &os, const multiset<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
#ifndef POJ
template<typename T> ostream &operator<<(ostream &os, const unordered_set<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T> ostream &operator<<(ostream &os, const unordered_multiset<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename TK, typename TV> ostream &operator<<(ostream &os, const unordered_map<TK, TV> &mp){ os << "{"; for (auto v : mp) os << v.first << "=>" << v.second << ","; os << "}"; return os; }
template<typename T> void resize_array(vector<T> &vec, int len) { vec.resize(len); }
template<typename T, typename... Args> void resize_array(vector<T> &vec, int len, Args... args) { vec.resize(len); for (auto &v : vec) resize_array(v, args...); }
#endif
template<typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &pa){ os << "(" << pa.first << "," << pa.second << ")"; return os; }
template<typename TK, typename TV> ostream &operator<<(ostream &os, const map<TK, TV> &mp){ os << "{"; for (auto v : mp) os << v.first << "=>" << v.second << ","; os << "}"; return os; }
template<typename T> bool mmax(T &m, const T q) { if (m < q) {m = q; return true;} else return false; }
template<typename T> bool mmin(T &m, const T q) { if (q < m) {m = q; return true;} else return false; }
template<typename T1, typename T2> pair<T1, T2> operator+(const pair<T1, T2> &l, const pair<T1, T2> &r) { return make_pair(l.first + r.first, l.second + r.second); }
template<typename T1, typename T2> pair<T1, T2> operator-(const pair<T1, T2> &l, const pair<T1, T2> &r) { return make_pair(l.first - r.first, l.second - r.second); }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;
ll powmod(ll a, ll b)
{
    ll res = 1;
    a %= mod;
    assert(b >= 0);
    for (; b; b >>= 1)
    {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
    }
    return res;
}
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

#ifndef POJ
static uint MD = mod;
struct ModInt
{
    using M = ModInt;
    uint v;
    ModInt(ll _v = 0) { set_v(uint(_v % MD + MD)); }
    M &set_v(uint _v)
    {
        v = (_v < MD) ? _v : _v - MD;
        return *this;
    }
    explicit operator bool() const { return v != 0; }
    M operator-() const { return M() - *this; }
    M operator+(const M &r) const { return M().set_v(v + r.v); }
    M operator-(const M &r) const { return M().set_v(v + MD - r.v); }
    M operator*(const M &r) const { return M().set_v(uint(ull(v) * r.v % MD)); }
    M operator/(const M &r) const { return *this * r.inv(); }
    M &operator+=(const M &r) { return *this = *this + r; }
    M &operator-=(const M &r) { return *this = *this - r; }
    M &operator*=(const M &r) { return *this = *this * r; }
    M &operator/=(const M &r) { return *this = *this / r; }
    bool operator==(const M &r) const { return v == r.v; }
    M pow(ll n) const
    {
        M x = *this, r = 1;
        while (n)
        {
            if (n & 1)
                r *= x;
            x *= x;
            n >>= 1;
        }
        return r;
    }
    M inv() const { return pow(MD - 2); }
    friend ostream &operator<<(ostream &os, const M &r) { return os << r.v; }
};
using Mint = ModInt;
#endif

class Solution
{
	
public:
	void Solve()
	{
		int x;
        while(cin>>x) {
            if(x>=30) cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
        }
	}

private:
};
//head
// cin >> t;
// for (int cas = 1; cas <= t; ++cas)
// {
// 	cout << "Case #" << cas << ": ";
// }
int main()
{
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);

	Solution().Solve();

	return 0;

}
