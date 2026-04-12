#include <bits/stdc++.h>
#include <algorithm>
#include <numeric>
using namespace std;
 
//グラフを隣接行列で管理する
bool G[10][10];
 
int main(){
    int n,m; cin >> n >> m;
    for(int i=0; i<m; i++){
        int a,b; cin >> a >> b; a--; b--;
        G[a][b] = G[b][a] = true;
    }
 
    //順列
    vector<int> ord(n);
    for(int i=0; i<n; i++) ord[i] = i;
    //n=5ならord={0,1,2,3,4} 
 
    //順列を全部試す
    //next_permutation
    int ans = 0;
    do{
        //スタート地点が0ではない場合break
        if(ord[0] != 0) break;
 
        //全列挙した並び順に道があるか確認
        bool ok = true;
        //最後の要素は確認しなくていいから、i<n-1
        for(int i=0; i<n-1; i++){
            int from = ord[i];
            int to = ord[i+1];
            if(!G[from][to]) ok = false;
        }
        if(ok) ans++;
    }while(next_permutation(ord.begin(),ord.end()));
        
    cout << ans << endl;
}