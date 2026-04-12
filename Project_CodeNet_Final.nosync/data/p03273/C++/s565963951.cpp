#include <iostream>
#include <cstdio>
#include <queue>
#include <cmath>
#include <random>
#include <fstream>
#include <string>
#include <tuple>
#include <deque>
#include <set>
#include <map>
#include <stack>

#define REP(i, N) for(int i = 0; i< N; i++)
using namespace std;
#define ll long long
const int INF = 1 << 29;
const ll llINF = 10000000000000000;

const int MOD = 1000000007;

#define MAX_N 100100
typedef pair<int, int> P;
typedef pair<ll, ll> llP;

class UnionFindTree{
private:
    int par[MAX_N];
    int urank[MAX_N];
    int size[MAX_N];
public:
    int init(int n);
    int find(int x);
    int unite(int x, int y);
    int same(int x, int y);
    int parnum(int x){return par[x];}
    int ranknum(int x){return urank[x];}
    int sizenum(int x){return size[find(x)];}
};

int UnionFindTree::init(int n){
    REP(i, n){
        par[i] = i;
        urank[i] = 0;
        size[i] = 1;
    }
    return 0;
}

int UnionFindTree::find(int x){
    if(par[x] == x)return x;
    else return par[x] = find(par[x]);
}

int UnionFindTree::unite(int x, int y){
    x = find(x);
    y = find(y);
    
    if(x == y)return 0;
    if(urank[x] < urank[y]){
        par[x] = y;
        size[y] += size[x];
    }else{
        par[y] = x;
        size[x] += size[y];
        if(urank[x] == urank[y])urank[x] ++;
    }
    return 0;
}

int UnionFindTree::same(int x, int y){
    return find(x) == find(y);
}


int main(){
    int W, H;
    cin >> H >> W;
    bool tate[110] = {false};
    bool yoko[110] = {false};
    char masu[110][110];
    REP(i, H){
        REP(j,W){
            cin >> masu[i][j];
            if(masu[i][j] == '#'){
                tate[j] = true;
                yoko[i] = true;
            }
        }
    }
    
    REP(i, H){
        REP(j, W){
            if(tate[j] && yoko[i])printf("%c", masu[i][j]);
        }
        if(yoko[i])printf("\n");
    }
}
