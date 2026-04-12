// #define _GLIBCXX_DEBUG // for STL debug (optional)
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
#include <bitset>
using namespace std;
using ll = long long int;
using int64 = long long int;
 
template<typename T> void chmax(T &a, T b) {a = max(a, b);}
template<typename T> void chmin(T &a, T b) {a = min(a, b);}
template<typename T> void chadd(T &a, T b) {a = a + b;}
 
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
const int INF = 1LL << 29;
const ll LONGINF = 1LL << 60;
const ll MOD = 1000000007LL;
 
int main() {
    int N; scanf("%d", &N);
    string s; cin >> s;
    vector<int> P(1 << N);
    for(int i=0; i<(1<<N); i++) scanf("%d", &P[i]);

    vector<int> ans(1 << N);
    auto dfs = [&](auto&& self, vector<int> &idx, vector<int> &match) -> void {
        int M = match.size();

        /*
        cerr << "# dfs" << endl;
        for(auto e : idx) cerr << e << " ";
        cerr << endl;
        for(auto e : match) cerr << e << " ";
        cerr << endl;
        */        

        if(M == 1) {
            // fprintf(stderr, "idx = %d, match = %d\n", idx[0], match[0]);
            ans[idx[0]] = match[0];
            return;
        }
        
        for(int p=0; p<2; p++) {
            vector<int> n_match;
            for(int i=0; i<M/2; i++) {
                int u = (p + 2*i + 0) % M;
                int v = (p + 2*i + 1) % M;
                int x = match[u], y = match[v];
                if(x > y) swap(x, y);
                if(s[y-x-1] == '0') n_match.emplace_back(x);
                else n_match.emplace_back(y);
            }
            vector<int> n_idx;
            for(int i=p; i<M; i+=2) {
                n_idx.emplace_back(idx[i]);
            }
            self(self, n_idx, n_match);
        }
    };

    vector<int> all(1 << N), mat = P;
    iota(all.begin(), all.end(), 0);
    dfs(dfs, all, mat);

    for(auto e : ans) printf("%d\n", e);
    return 0;
}

