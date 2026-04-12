#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define srep(i,s,t) for (int i = s; i < t; ++i)
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
#define yn {puts("First");}else{puts("Second");}

const int MAX_N = 200100;
int par[MAX_N]; // 親
int rank_[MAX_N]; // 木の深さ
int cnt_[MAX_N]; // 属する頂点の個数(親のみ正しい)

// n要素で初期化
void UFinit(){
    for(int i=0;i<MAX_N;i++){
        par[i] = i;
        rank_[i] = 0;
        cnt_[i] = 1;
    }
}

// 木の根を求める
int find(int x){
    if(par[x] == x){
        return x;
    }else{
        return par[x] = find(par[x]);
    }
}

// xとyの属する集合を併合
void unite(int x, int y){
    x = find(x);
    y = find(y);
    if(x == y) return;

    if(rank_[x] < rank_[y]){
        par[x] = y;
        cnt_[y] += cnt_[x];
    }else{
        par[y] = x;
        cnt_[x] += cnt_[y];
        if(rank_[x] == rank_[y]) rank_[x]++;
    }
}

// xとyが同じ集合に属するか否か
bool same(int x, int y){
    return find(x) == find(y);
}

vector<int> G[MAX_N];
int aa[110000], bb[110000];
int main() {
    int n;
    string fileNameIfs = "hogehoge.txt";
    const char* cstrIfs = fileNameIfs.c_str();
    ifstream ifs(cstrIfs);
    
    if(!ifs.is_open()){ // 標準入力する
        cin >> n;
        rep(i,n-1){
            int a, b;
            cin >> a >> b;
            a--; b--;
            aa[i] = a;
            bb[i] = b;
            G[a].push_back(b);
            G[b].push_back(a);
        }
    }else{ // ファイル入力する
        ifs >> n;
        rep(i,n-1){
            int a, b;
            ifs >> a >> b;
            a--; b--;
            aa[i] = a;
            bb[i] = b;
            G[a].push_back(b);
            G[b].push_back(a);
        }
    }
        

    int jisuu[MAX_N] = {};
    rep(i,n){
        jisuu[i] = G[i].size();
    }

    int del[n] = {};
    queue<int> qu;
    rep(i,n){
        if(jisuu[i] == 1){
            qu.push(i);
        }
    }
    int nn = n;
    while(qu.size()){
        int x = qu.front();
        qu.pop();
        if(del[x])continue;
        rep(i,G[x].size()){
            int y = G[x][i];
            if(del[y])continue;
            if(jisuu[y] == 1){
                cout << "Second" << endl;
                return 0;
            }
            if(jisuu[y] == 2){
                del[x] = 1;
                del[y] = 1;
                nn -= 2;
                if(nn == 1){
                    cout << "First" << endl;
                    return 0;
                }
                rep(j,G[y].size()){
                    int z = G[y][j];
                    if(del[z])continue;
                    jisuu[z]--;
                    if(jisuu[z] == 1){
                        qu.push(z);
                        break;
                    }
                    if(jisuu[z] == 2){
                        rep(k,G[z].size()){
                            int w = G[z][k];
                            if(del[w])continue;
                            if(jisuu[w]==1){
                                qu.push(w);
                            }
                        }
                    }
                    break;
                }
            }
            break;
        }
    }

    // 木を二部グラフにする
    int f[n] = {};
    int start = -1;
    rep(i,n){
        if(del[i]==0){
            start = i;
            break;
        }
    }
    queue<P> que;
    que.push(P(start,-1));
    while(que.size()>0){
        int x = que.front().first;
        int oya = que.front().second;
        que.pop();
        rep(i,G[x].size()){
            if(G[x][i] == oya) continue;
            int y = G[x][i];
            if(del[y])continue;
            f[y] = (f[x]+1)%2;
            que.push(P(y,x));
        }
    }
    
    int flag = 0;

    UFinit();
    rep(i,n-1){
        if(del[aa[i]]||del[bb[i]])continue;
        if(f[aa[i]] == 0 && jisuu[aa[i]] > 2)continue;
        if(f[bb[i]] == 0 && jisuu[bb[i]] > 2)continue;   
        unite(aa[i],bb[i]);
    }
    int cnt[n] = {};
    rep(i,n){
        if(del[i])continue;
        if(f[i]==0&&jisuu[i]==1) cnt[find(i)]++;
        if(cnt[find(i)] >= 2) flag = 1;
    }

    rep(i,n) f[i] = (f[i]+1)%2;
    UFinit();
    rep(i,n-1){
        if(del[aa[i]]||del[bb[i]])continue;
        if(f[aa[i]] == 0 && jisuu[aa[i]] > 2)continue;
        if(f[bb[i]] == 0 && jisuu[bb[i]] > 2)continue;   
        unite(aa[i],bb[i]);
    }
    rep(i,n) cnt[i] = 0;
    rep(i,n){
        if(del[i])continue;
        if(f[i]==0&&jisuu[i]==1) cnt[find(i)]++;
        if(cnt[find(i)] >= 2) flag = 1;
    }
    int leafcolor[2] = {};
    rep(i,n){
        if(del[i])continue;
        if(jisuu[i] == 1){
            leafcolor[f[i]]++;
        }
    }
    if(min(leafcolor[0],leafcolor[1])==0) flag = 1;

    rep(i,2){
        // cout << leafcolor[i] << endl;
    }

    if(flag)yn;
    return 0;
}
 
 
