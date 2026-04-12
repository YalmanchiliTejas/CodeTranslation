#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define REP(i,n) FOR(i,0,n)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using mii = map<int, int>;
using msi = map<string, int>;
using pii = pair<int, int>;

struct Edge {
    int to;     // 辺の行き先
    int weight; // 辺の重み
    Edge(int t, int w) : to(t), weight(w) { }
};
using Graph = vector<vector<Edge>>;

int main()
{
 int a, b;
 cin>> a>>b;
 if(a == b) {
     cout << "Yes" << endl;
 } else {
     cout << "No" << endl;
 }
}