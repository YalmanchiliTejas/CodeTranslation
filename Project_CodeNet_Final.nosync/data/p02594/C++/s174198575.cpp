#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned ll
#define PI acos(-1)
#define vi vector<int>
#define pi pair<int, int>
#define pl pair<ll, ll>
template<typename T> using v2 = vector<vector<T>>;
template<typename T> using v3 = vector<vector<vector<T>>>;
template<class T> istream &operator>>(istream&is,vector<T>&v){for(auto &elemnt:v)is>>elemnt;return is;}
template<class T,class U> istream &operator>>(istream&is,pair<T,U>&p){is>>p.first>>p.second;return is;}
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const int MOD = 1e9 + 7;
const int INF = 1e9 + 200;
const ll INFLL = 2e18 + 200;

int main() {
    int X;
    cin >> X;
    cout << (X >= 30 ? "Yes" : "No") << endl;
}