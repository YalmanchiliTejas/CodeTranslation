#include <iostream>
#include <vector>

using namespace std;
vector<int> G[100010];
int d[3][100010] = {};
int dfs(int s, int p,int k){
    for(int v:G[s]){
        if(v==p) continue;
        d[k][v] = d[k][s] + 1;
        dfs(v,s,k);
    }
}

int mx[100010] = {};
void dfs2(int s,int p,int dia,int par){
    for(int v:G[s]){
        if(v==p) continue;
        if(d[0][v] + d[1][v]==dia) continue;
        d[2][v] = d[2][s] + 1;
        mx[par] = max(mx[par],d[2][v]);
        dfs2(v,s,dia,par);
    }
}

int n,seg[2][200010];
void init(int n,int x){
    for(int i=n - 1;i>0;i--){
        seg[x][i] = max(seg[x][i<<1],seg[x][i<<1|1]);
    }
}

void update(int val,int p,int x){
    for(seg[x][p += n] = val;p>1;p>>=1){
        seg[x][p>>1] = max(seg[x][p],seg[x][p^1]);
    }
}

int query(int l,int r,int x){
    int res = 0;
    for(l += n,r += n; l<r;l>>=1,r>>=1){
        if(l&1) res = max(res,seg[x][l++]);
        if(r&1) res = max(res,seg[x][--r]);
    }
    return res;
}

int ans[100010];
int main(){
    int i;
    cin >> n;
    for(i=0;i<n - 1;i++){
        int a,b; cin >> a >> b;
        a--; b--;
        G[a].push_back(b); G[b].push_back(a);
    }
    dfs(0,-1,0);
    int j = -1,x = -1;
    for(i=0;i<n;i++){
        if(d[0][i]>x){
            j = i; x = d[0][i];
        }
    }
    for(i=0;i<n;i++){
        d[0][i] = 0;
    }
    dfs(j,-1,0);
    int jj = -1; x = -1;
    for(i=0;i<n;i++){
        if(d[0][i]>x){
            x = d[0][i];
            jj = i;
        }
    }
    int dia = x;
    dfs(jj,-1,1);
    vector<int> choku;
    ans[1] = 1; ans[2] = 1;
    for(i=dia + 1;i<=n;i++){
        ans[i] = 1;
    }
    for(i=0;i<n;i++){
        if(d[0][i] + d[1][i]==dia){
            dfs2(i,-1,dia,i);
            choku.push_back(i);
        }
    }
    for(i=0;i<choku.size();i++){
        int v = choku[i];
        if(mx[v]) update(mx[v] + d[0][v],d[0][v],0);
        if(mx[v]) update(mx[v] + d[1][v],d[1][v],1);
    }
    for(i=3;i<=dia;i++){
        if(i&1){
            if(query(0,n,0)>=i || query(0,n,1)>=i) ans[i] = 0;
            else ans[i] = 1;
        }else{
            int k = i/2;
            if(max(query(0,n,0),query(0,n,1))<i){
                ans[i] = 1;
            }else if(max(query(0,k,0),query(k + 1,n,0))>=i || max(query(0,k,1),query(k + 1,n,1))>=i){
                ans[i] = 0;
            }else if(max(query(k,k + 1,0),query(k,k + 1,1))==i){
                ans[i] = 1;
            }else{
                ans[i] = 0;
            }
        }
    }
    for(i=1;i<=n;i++){
        cout << ans[i];
    }
    cout << endl;
}
