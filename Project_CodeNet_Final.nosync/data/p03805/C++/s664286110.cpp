#include <map>
#include <set>
#include <list>
#include <cmath>
#include <queue>
#include <stack>
#include <cstdio>
#include <string>
#include <vector>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <functional>
  
#define mp       make_pair
#define pb       push_back
#define all(x)   (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
  
using namespace std;
  
typedef    long long          ll;
typedef    unsigned long long ull;
typedef    vector<bool>       vb;
typedef    vector<int>        vi;
typedef    vector<vb>         vvb;
typedef    vector<vi>         vvi;
typedef    pair<int,int>      pii;
  
const int INF=1<<29;
const double EPS=1e-9;
  
const int dx[]={1,0,-1,0,1,1,-1,-1},dy[]={0,-1,0,1,1,-1,-1,1};



int main() {
    int N, M;
    cin >> N >> M;
    int G[8][8] = {{0}};
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        G[a][b] = G[b][a] = 1;
    }

    vector<int> p;
    for (int i = 0; i < N; i++) {
        p.push_back(i);
    }

    int ans = 0;
    do {
        if (p[0] != 0) continue;
        bool flag = true;
        for (int i = 0; i < N - 1; i++) {
            if (!G[p[i]][p[i + 1]]) {
                flag = false;
            }
        }
        if (flag) ans++;
    } while(next_permutation(p.begin(), p.end()));
    cout << ans << endl;
    return 0;
}