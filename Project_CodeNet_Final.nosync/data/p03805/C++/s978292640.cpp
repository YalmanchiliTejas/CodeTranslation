#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
#define vv(T) vector<vector<T>>
using namespace std;
using ll = long long;
using vint = vector<int>;
using vvint = vector<vector<int>>;
using vll = vector<long long>;
using vvll = vector<vector<long long>>;
using vbool = vector<bool>;
using vvbool = vector<vector<bool>>;
using qint = queue<int>;
using sint = stack<int>;
using pii = pair<int, int>;


int main(){
    int n, m;
    cin >> n >> m;
    vvint path(n);
    rep(i, m){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        path[a].push_back(b);
        path[b].push_back(a);
    }

    vint route(n);
    rep(i, n) route[i] = i;
    int ans = 0;
    do{
        bool flag = true;
        rep(i, n - 1){
            int dep = route[i];
            int arr = route[i + 1];
            auto result = find(path[dep].begin(), path[dep].end(), arr);
            if(result == path[dep].end()){
                flag = false;
                break;
            }
        }
        if(flag) ans++;
    }while(next_permutation(route.begin() + 1, route.end()));

    cout << ans << endl;
    return 0;
}
