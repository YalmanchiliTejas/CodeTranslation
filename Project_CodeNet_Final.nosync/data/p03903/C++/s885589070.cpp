#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

class UnionFind{
    public:
    //親の番号を格納する。親だった場合は-(その集合のサイズ)
    vector<int> parent;

    //-1で初期化。最初はすべてバラバラ
    UnionFind(int N){
        parent = vector<int>(N,-1);
    }

    //Aがどのグループに属しているか(Aの根)を調べる
    int root(int A){
        if(parent[A] < 0) return A;
        return parent[A]=root(parent[A]);
    }

    //自分のいるグループの頂点数を調べる
    int size(int A){
        return -parent[root(A)];
    }

    //AとBをくっつける
    bool unite(int A, int B) {
    //AとBを直接つなぐのではなく、root(A)にroot(B)をくっつける
        A = root(A);
        B = root(B);
        //既にくっついているからくっつけない
        if(A == B) return false; 

        //大きいほう(A)に小さいほう(B)をくっつける
        //大小が逆ならひっくり返す
        if(size(A) < size(B)) swap(A,B);

        //Aのサイズを更新する
        parent[A] += parent[B];
        //Bの親をAに変更する
        parent[B] = A;

        return true;
    }

    //AとBが同じグループならtrueを返す
    bool same(int A, int B){
        return root(A)==root(B);
    } 
};

vector<vector<array<ll,2>>> v(4444);
ll sum = 0;
bool used[4444];
ll ans[4040][4040];

void dfs(int r,int p, ll dist){
    used[p]=1;
    ans[r][p] = dist;
    for(auto i:v[p]){
        if(!used[i[0]]){
            dfs(r,i[0],max(dist,i[1]));
        }
    }
}


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);
    
    ll n,m;
    cin>>n>>m;
    UnionFind uni(n);
    array<ll,3> a[m];
    for(int i=0;i<m;i++){
        ll e,b,c;
        cin>>e>>b>>c;
        e--,b--;
        a[i] = {c,e,b};
    }
    sort(a,a+m);

    for(int i=0;i<m;i++){
        if(!uni.same(a[i][1],a[i][2])){
            sum += a[i][0];
            uni.unite(a[i][1],a[i][2]);
            v[a[i][1]].push_back({a[i][2],a[i][0]});
            v[a[i][2]].push_back({a[i][1],a[i][0]});
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) used[j]=0;
        dfs(i,i,0);
    }
    int q;
    cin>>q;
    while(q--){
        int s,t;
        cin>>s>>t;
        s--,t--;
        cout << sum - ans[s][t] << "\n";
    }
    
}