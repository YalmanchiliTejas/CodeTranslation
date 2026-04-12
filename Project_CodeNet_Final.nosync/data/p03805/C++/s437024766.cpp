#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define rep(i, N) for(int (i) = 0; (i) < (N); (i) ++)
typedef long long ll;
using namespace std;

vector<bool> visited(8, false);
vector<vector<bool>> edges;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int>  p;
    rep(i, N){
        p.push_back(i);
        edges.push_back(vector<bool>(8, false));
    }
    rep(i, M) {
        int a, b;
        cin >> a >> b;
        a --;
        b --;
        edges[a][b] = edges[b][a] = true;
    }
    int ans = 0;
    do{
        bool flag = true;
        for(int i = 0; i < p.size() - 1; i++){
            int next = p[i + 1];
            int now = p[i];
            if(! edges[now][next]){
                flag = false;
                break;
            }
        }
        if(flag){
            ans ++;
        }
    }while (next_permutation(p.begin() + 1, p.end()));

    cout << ans << endl;
    return 0;
}
