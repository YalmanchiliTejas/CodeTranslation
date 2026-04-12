#include <iostream>
#include <vector>
//#include <string>
//#include <algorithm>
//#include <math.h>
//#include <queue>
//#include <stack>
//#include <iomanip>

// sometimes used
//#include <set>
//#include <map>
//#include <numeric>
//#include <list>
//#include <deque>
//#include <unordered_map>

typedef long long LL;
//typedef long double LD;
using namespace std;
 
//#define MOD 1000000007
//#define MAX 100100
//#define NIL -1

vector<vector<LL>> ab(10);
vector<LL> color(10, 0);
LL n;
LL ans=0;
LL depth;

void dfs(LL s){
    //cout << s+1 << " " << depth << endl;
    if(depth==n){
        ans++;
        return;
    }

    for(int i=0; i<ab[s].size(); i++){
        if(color[ab[s][i]]==1){
            continue;
        }
        color[ab[s][i]]=1;
        depth++;
        dfs(ab[s][i]);
        color[ab[s][i]]=0;
        depth--;
    }
    return;
}

int main() {
    LL m;
    cin >> n >> m;
    LL tmp_a;
    LL tmp_b;
    for(int i=0; i<m; i++){
        cin >> tmp_a >> tmp_b;
        tmp_a--;
        tmp_b--;
        ab[tmp_a].push_back(tmp_b);
        ab[tmp_b].push_back(tmp_a);
    }

    color[0]=1;
    depth=1;
    dfs(0);

    cout << ans << endl;

    return 0;
}