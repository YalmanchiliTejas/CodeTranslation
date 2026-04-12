#include<algorithm>
#include<cmath>
#include<iomanip>
#include<iostream>
#include<map>
#include<numeric>
#include<queue>
#include<set>
#include<sstream>
#include<vector>
using namespace std;
using uint = unsigned int;
using ll = long long;
const int M = 1e9 + 7;
const ll MLL = 1e18L + 9;
#pragma unused(M)
#pragma unused(MLL)
#ifdef LOCAL
#include"rprint.hpp"
#else
template <class... T> void printl(T&&...){ }
template <class... T> void printc(T&&...){ }
template <class... T> void prints(T&&...){ }
template <class... T> void printd(T&&...){ }
#endif

int edges[8][8];
int count(int visited, int cur, int n){
    if(visited == (1 << n) - 1){ return 1; }
    int ret = 0;
    for(int i=0;i<n;i++){
        if(edges[cur][i] && i != cur && !(visited & (1 << i))){
            ret += count(visited | (1 << i), i, n);
        }
    }
    return ret;
}
int main(){
    int n, m;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        edges[a][b] = edges[b][a] = 1;
    }
    cout << count(1, 0, n) << '\n';
    return 0;
}
