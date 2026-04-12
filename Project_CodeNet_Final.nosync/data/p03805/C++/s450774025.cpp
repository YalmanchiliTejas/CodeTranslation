#include<algorithm>
#include<climits>
#include<cmath>
#include<iomanip>
#include<iostream>
#include<list>
#include<map>
#include<numeric>
#include<queue>
#include<set>
#include<stack>
#include<utility>
#include<vector>
 
#define lint long long
#define REP(i, x, n) for(int i = x ; i < n ; i++)
#define rep(i, n) REP(i, 0, n)
#define repr(i, n) for(int i = n - 1 ; i >= 0 ; i--)
#define SORT(c) sort((c).begin(), (c).end())
#define SORT_INV(c) sort((c).begin(), (c).end(), greater<int>())
#define IINF INT_MAX
#define LLINF LLONG_MAX

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector< vector<int> > dis(n);
    rep(i, n){
        dis[i].resize(n, 1e8);
        dis[i][i] = 0;
    }
    rep(i, m){
        int a, b;
        cin >> a >> b;
        a--;    b--;
        dis[a][b] = 1;
        dis[b][a] = 1;
    }
    rep(k, n){
        rep(i, n){
            rep(j, n){
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
    vector<int> path;
    for(int i = 1 ; i < n ; i++){
        path.push_back(i);
    }
    int ans = 0;
    do{
        int cnt = dis[0][path[0]];
        rep(i, n-2){
            cnt += dis[path[i]][path[i+1]];
        }
        if(cnt == n-1){
            ans++;
        }
    }while(next_permutation(path.begin(), path.end()));
    cout << ans << endl;
    return 0;
}