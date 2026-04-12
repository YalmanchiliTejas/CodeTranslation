#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
 
/*深さ優先探索。pathの軌跡をvectorの形で表し、スタックに保存する。*/
int main(void){
    int N, M;
    cin >> N >> M;
    bool relation[N][N];
    int ans = 0;
    rep(i,N)rep(j,N)relation[i][j] = false;
    rep(i,M){
        int x,y;
        cin >> x >> y;
        relation[x-1][y-1] = true;
        relation[y-1][x-1] = true;
    }
    deque<vector<int>> will_search;
    vector<int> start = {0};
    will_search.emplace_back(start);
    while(!will_search.empty()){
        vector<int> locus = will_search.back();
        will_search.pop_back();
        int now_search = locus.back();
        rep(i,N){
            if(!relation[now_search][i] || count(locus.begin(),locus.end(),i) != 0)continue;
            locus.emplace_back(i);
            if((int)locus.size() == N)ans++;
            else will_search.emplace_back(locus);
            locus.pop_back();
        }
    }
    cout << ans << endl;
    return 0;
}