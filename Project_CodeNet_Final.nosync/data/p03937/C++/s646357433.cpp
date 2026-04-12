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
#define IINF (int)(1e9+10)
#define LLINF (lint)(1e18+10)

using namespace std;

int main(){
    int h, w;
    cin >> h >> w;
    vector< vector<char> > a(h+2);
    rep(i, h+2){
        a[i].resize(w+2, '.');
    }
    REP(i, 1, h+1){
        REP(j, 1, w+1){
            cin >> a[i][j];
        }
    }
    int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
    queue< pair<int, int> > que;
    que.push(make_pair(1, 1));
    string ans = "Possible";
    while(!que.empty()){
        pair<int, int> tmp = que.front();
        que.pop();
        int cnt = 0;
        rep(i, 2){
            if(a[tmp.first+dy[i]][tmp.second+dx[i]] == '#'){
                que.push(make_pair(tmp.first+dy[i], tmp.second+dx[i]));
                cnt++;
            }
        }
        REP(i, 2, 4){
            if(a[tmp.first+dy[i]][tmp.second+dx[i]] == '#'){
                cnt = 2;
            }
        }
        if(cnt >= 2){
            ans = "Impossible";
            break;
        }
        a[tmp.first][tmp.second] = '.';
    }
    cout << ans << endl;
    return 0;
}