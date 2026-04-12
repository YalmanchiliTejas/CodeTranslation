#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const long MOD = 1000000007;
typedef pair<int, int> P;
typedef long long ll;

vector<int> v[100];
int N, M;

long dfs(int now, int state){
    if(state == pow(2, N)-1) return 1;

    long ans = 0;
    for(int next : v[now]){
        if((state>>next)&1 == 1) continue;
        int next_state = (state | (1<<next));
        ans += dfs(next, next_state);
    }
    return ans;
}

int main(){
    cin >> N >> M;

    for(int i=0; i<M; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    cout << dfs(0, 1) << endl;

    return 0;
}
