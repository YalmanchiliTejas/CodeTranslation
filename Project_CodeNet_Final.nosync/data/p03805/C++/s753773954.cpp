#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
#include <iomanip>
#include <set>
using namespace std;

#define rep(i, s) for (int i = 0; i < s; ++i)
#define all(v) (v.begin(), v.end())
#define COUT(x) cout << #x << " = " << (x) << " (L" << __LINE__ << ")" << endl
#define EACH(i, s) for (__typeof__((s).begin()) i = (s).begin(); i != (s).end(); ++i)
#define VEC(a, n) vector<int>a(n)
#define PQ(a) priority_queue<int>a
#define PQmin(a) priority_queue< int, :vector<int>, greater<int> >a
#define PAIR pair<int, int>
/*
sort(sp.begin(), sp.end(), [](PAIR l, PAIR r){
        return l.first<r.first || (l.first==r.first && l.second > r.second);
        });
*/

typedef long long  ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
int cnt=0;

void dfs(vector<vector<int> >&G, vector<bool>&used, int v){
    used.at(v)=true;
    bool flag=false;
    for(int i=0;i<used.size();i++){
        if(used.at(i)==false){
            flag=true;
            break;
        }
    }

    if(!flag)cnt++;

    for(auto next_v : G.at(v)){
        if(used.at(next_v)==false){
            dfs(G,used,next_v);
        }
    }
    used.at(v)=false;
}


int main() {
    int n,m;
    cin>>n>>m;
    vector<vector<int> >G(n);
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        x--,y--;
        G.at(x).push_back(y);
        G.at(y).push_back(x);
    }
    vector<bool>used(n,false);
    dfs(G, used, 0);
    cout<<cnt<<endl;



    return 0;
}
