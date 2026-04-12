#include<bits/stdc++.h>
using namespace std;
#define N 8
#define rep(i,n) for(int i=0;i<n;i++)
bool a[N][N];//本来の組み合わせ
vector<int> route;//探索済みの要素を格納
int n,m;
int ct = 0;
int ans = 0;

void search(int t1){
    route.push_back(t1);
    //cout << t1+1 << " " << ct << endl;
    ct++;
    rep(i,n){
        if(a[t1][i] == 1||a[i][t1] == 1){
            if(count(route.begin(),route.end(),i) == 0){//次に行こうとしている場所がまだ訪れていない
                search(i);
            }
        }
    }
    if(ct == n)ans++;
    ct--;
    route.pop_back();
    return;
}

int main(void){
    cin >> n >> m;
    rep(i,n) rep(j,n) a[i][j] = 0;
    rep(i,m){
        int x,y;
        cin >> x >> y;
        a[x-1][y-1] = 1;
        a[y-1][x-1] = 1;
    }//入力ここまで
    search(0);
    cout << ans << endl;
    return 0;
}
