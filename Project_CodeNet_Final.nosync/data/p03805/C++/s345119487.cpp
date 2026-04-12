#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

typedef long long ll;
typedef pair<int, int> P;

const ll mod =  1000000007;
const int inf = 1e9;
const long long INF = 1LL << 60;   // INFの値は1152921504606846976

int dx[8] = {-1,-1,-1,0,0,1,1,1};
int dy[8] = {-1,0,1,-1,1,-1,0,1};


int main()
{
    int n,m;
    cin >> n >> m;
    int g[n][n];
    rep(i,n) rep(j,n) g[i][j] = -1;
    rep(i,m){
        int a,b;
        cin >> a >> b;
        a--; b--;
        g[a][b] = 1;
        g[b][a] = 1;
    }
    vector<int> node;
    rep(i,n) node.push_back(i);
    int ans = 0;
    do{
        if(node[0] != 0) break;
        bool path = true;
        rep(i,n-1){
            if(g[node[i+1]][node[i]] == -1) path = false;
        }
        if(path) ans++;
    }while(next_permutation(node.begin(),node.end()));

    cout << ans << endl;
}
