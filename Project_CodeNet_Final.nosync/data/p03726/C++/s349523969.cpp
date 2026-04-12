#include<iostream>
#include<iomanip>
#include<map>
#include<unordered_map>
#include<set>
#include<unordered_set>
#include<vector>
#include<array>
#include<string>
#include<stack>
#include<queue>
#include<algorithm>
#include<cassert>
#include<functional>
#include<random>
#include<complex>
#include<bitset>
#include<chrono>
//#include<boost/multiprecision/cpp_int.hpp>
#define int int64_t
#define uint uint64_t
#define REP(i, a, b) for (int64_t i = (int64_t)(a); i < (int64_t)(b); i++)
#define rep(i, a) REP(i, 0, a)
#define SZ(X) ((int64_t)((X).size()))
#define ITR(x, a) for (auto x = a.begin(); x != a.end(); x++)
#define ALL(a) (a.begin()), (a.end())
#define HAS(a, x) (a.find(x) != a.end())
#define Min(x) *min_element(ALL(x))
#define Max(x) *max_element(ALL(x))
#define Unique(L) (L.erase(unique(ALL(L)), L.end()))
#define intmax (std::numeric_limits<int64_t>::max() / 4)
#define doublemax (std::numeric_limits<double>::max() / 4)
using namespace std;
//typedef boost::multiprecision::cpp_int bigint;
//const double EPS = 1e-9;
//const double PI = acos(-1.0);


vector<vector<int>>tree;
int dfs(int now, int prev) {
    if(prev!=-1&&tree[now].size()==1){//leaf
        return 2;
    }
    int count = 0;
    for (int i : tree[now])if (i != prev) {
        int c = dfs(i, now);
        if (c == -2)return -2;
        if(c == 2){
            if(count==0)count=1;
            else return -2;
        }
    }
    if(count==0)return 2;
    return 1;
}

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;
    cin >> N;
    if (N == 1) {
        cout << "First" << endl;
        return 0;
    }
    if (N == 2) {
        cout << "Second" << endl;
        return 0;
    }
    tree = vector<vector<int>>(N);
    rep(i, N - 1) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    
    int ans = dfs(0,-1);
    if(ans==-2||ans==2){
        cout<<"First"<<endl;
    }
    else cout<<"Second"<<endl;
    
    
    return 0;
}








