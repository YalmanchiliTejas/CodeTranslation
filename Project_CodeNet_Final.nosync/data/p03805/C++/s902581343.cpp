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
 
#define _USE_MATH_DEFINES
#define mp       make_pair
#define pb       push_back
#define fst      first
#define snd      second
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

const int dx[]={1,0,-1,0},dy[]={0,-1,0,1};

int N, M;
bool path[100][100] = {false};
bool used[100] = {false};

int cnt_path(int n, int d)
{
    if(d == N)
        return 1;

    int ret = 0;
    used[n] = true;
    rep(i, N) {
        if(!used[i] && path[n][i]) {
            ret += cnt_path(i, d+1);
        }
    }
    used[n] = false;

    return ret;
}

int main()
{
    cin >> N >> M;
    int a, b;
    rep(i, M) {
        cin >> a >> b;
        a--; b--;
        path[a][b] = path[b][a] = true;
    }

    cout << cnt_path(0, 1) << endl;
    return 0;
}
