#include<bits/stdc++.h>
using namespace std;

int next_combination(int sub) {
    int x = sub & -sub, y = sub + x;
    return (((sub & ~y) / x) >> 1) | y;
}
class UnionFind{
    public:
    //親の番号を格納する。親だった場合は-(その集合のサイズ)
    vector<int> parent;

    //-1で初期化
    //最初はすべてバラバラ
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
    bool connect(int A, int B) {
    //AとBを直接つなぐのではなく、root(A)にroot(B)をくっつける
        A = root(A);
        B = root(B);
        //既にくっついているからくっつけない
        if(A == B) return false; 

        //大きいほう(A)に小さいほう(B)をくっつける
        //大証が逆ならひっくり返す
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

int main(){
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>> v(m);
    for(int i=0;i<m;i++){
        cin>>v[i].first>>v[i].second;
    }
    int ans=0;

    // {0, 1, ..., n-1} の部分集合の全探索
    for (int bit = (1<<n-1)-1; bit < (1<<m); bit=next_combination(bit))
    {
        UnionFind uni(n);
        int cnt=0;
        int a[n+1]={};
        for(int i=0;i<m;i++){
            if((bit>>i&1)) {
                a[v[i].first]++;
                a[v[i].second]++;
                uni.connect(v[i].first-1,v[i].second-1);
            } 

        }

        bool ok=true;

  
            if(a[1]!=1) ok=false;

            int t=1;

            for(int i=2;i<n+1;i++){
                if(a[i]==1 && t==1) t=0;
                else if(a[i]!=2) ok=false;
                if(!uni.same(0,i-1)) ok=false;
            }
        

        if(ok) ans++;
    }

    cout<<ans;

}