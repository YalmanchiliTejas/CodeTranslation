#include <iostream>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <deque>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>

#define Rep(i, b, e) for(int (i) = (b); (i) < (e); ++(i))
#define Repr(i, b, e) for(int (i) = (b) - 1; (i) >= (e); --(i))
#define Print(x) cout << (x) << endl 
#define Min2(a, b) ((a) < (b)) ? (a) : (b)
#define Max2(a, b) ((a) > (b)) ? (a) : (b)

typedef long long ll;

using namespace std;

int N, M;
vector<int> edge[8];

int solve(int node, int state){
    if((state >> node) & 1) return 0;
    else if((state | (1 << node)) == (int)pow(2, N) - 1) return 1;
    state = (state | (1 << node));
    int ret = 0;
    for(int i : edge[node]){
        ret += solve(i, state);
    }
    return ret;
}

int main(){
    int a, b, ans = 0;
    cin >> N >> M;
    Rep(i, 0, M){
        cin >> a >> b;
        edge[a - 1].push_back(b - 1);
        edge[b - 1].push_back(a - 1);
    }
    ans = solve(0, 0);
    Print(ans);
    return 0;
}