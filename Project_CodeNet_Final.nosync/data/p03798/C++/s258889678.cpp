#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <queue>
#include <stack>
#include <list>
#include <utility>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
#include <climits>
#include <map>
#include <unordered_map>
#include <string.h>
#include<iomanip>
#include <iterator>

#define all(a) a.begin(),a.end()
#define VV(T) vector<vector< T > >
#define rep(i,N) for(int i = 0; i <N; i++)
#define repsg(i,s,g) for(int i = s; i <g; i++)
#define name(x) #x
using namespace std;


const int INF = 10000000;
const long long INFL = (1LL<<40);
const int MOD = pow(10,9)+7;
int dy[]={0, 0, 1, -1, 0};
int dx[]={1, -1, 0, 0, 0};

typedef long long ll,LL;
typedef vector<int> vint;
typedef vector<vector<int> > vvint;
typedef vector<long long> vll, vLL;
typedef vector<vector<long long> > vvll, vvLL;
typedef pair<int,int> pii;
typedef pair<LL, LL> pLL;


// vector入力
template<typename T>
istream& operator >> (istream& is, vector<T>& vec){
    for(T& x: vec) is >> x;
    return is;
}
// vector出力
template<typename T>
ostream& operator << (ostream& os, vector<T>& vec){
    for(int i=0; i<vec.size(); i++){
        os << vec[i] << ( i+1 == vec.size() ? "" : " " );
    }
    return os;
}

template< typename T >
struct edge{
    int src, to;T cost;
    edge(int to,T cost) :src(-1),to(to),cost(cost){}
    edge(int src, int to, T cost) :src(src),to(to),cost(cost){}edge
    &operator=(const int &x){
        to =x;
        return *this;
    }
    operator int() const{ return to;}
};


struct UnionFind {
    // UnionFind u(n) 宣言
    // u.unionSet(x,y) 併合
    // u.findSet(x,y) -> {true, false}
    // u.root(x) xのroot. data[x]を参照。併合前はxそのもの、併合後は同一union
    vector<int> data;
    UnionFind(int size) : data(size, -1) { }
    bool unionSet(int x, int y) {
        x = root(x); y = root(y);
        if (x != y) {
            if (data[y] > data[x]) swap(x, y);
            data[y] += data[x];
            data[x] = y;
        }
        return x != y;
    }
    bool findSet(int x, int y) {
        return root(x) == root(y);
    }
    int root(int x) {
        return data[x] < 0 ? x : data[x] = root(data[x]);
    }
    int size(int x) {
        return -data[root(x)];
    }
    
    void clear(int size) {
        data.clear();
        data.resize(size,-1);
    }
};



int N;
string s;

int main() {

    cin >> N;
    cin >> s;
    
    UnionFind u(N+2);
    
    int a1[] = {N, N, N+1,N+1};
    int b1[] = {N, N+1, N, N+1};
    
    // Nを羊、N+1 を狼とする。

    bool found = false;
    
    for(auto i = 0; i<4; i++){
    
        u.unionSet(N-1,a1[i]);
        u.unionSet(0,b1[i]);
    
        for(auto j = 0; j<N; j++){
            
            if((s[j] == 'o' && u.root(j) == N) || (s[j] == 'x' && u.root(j) == N+1)){
                
                u.unionSet((j+1)%N,u.root((N+j-1)%N));
                
            }else{
                if(u.root((N+j-1)%N) == N){
                    
                    u.unionSet((j+1)%N, N+1);
                }else{
                   u.unionSet((j+1)%N, N);
                }
            }

        }
    
        if (u.size(0) == N+2){
            u.clear(N+2);
            continue;
        }
        
        found = true;
        break;
    }
    
    if (!found){
        cout << -1<< endl;
        return 0;
    }
    
    for(auto i = 0; i<N; i++){
        
        if (u.root(i) == u.root(N)) cout << "S";
        else cout << "W";
        
    }
    cout << endl;
    
    
    return 0;
}







