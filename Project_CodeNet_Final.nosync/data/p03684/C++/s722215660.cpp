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

signed main(){
    ios::sync_with_stdio(false);
	cin.tie(0);
    cout << fixed << setprecision(20);

    int n;
    cin>>n;
    vector<pair<int,int>> x(n),y(n);
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        x[i] = make_pair(a,i);
        y[i] = make_pair(b,i);
    }
    sort(x.begin(),x.end());
    sort(y.begin(),y.end());

    UnionFind uni(n);

    vector<pair<int,pair<int,int>>> v;
    for(int i=1;i<n;i++){
        v.push_back(make_pair(x[i].first - x[i-1].first , make_pair(x[i].second,x[i-1].second)));
        v.push_back(make_pair(y[i].first - y[i-1].first, make_pair(y[i].second,y[i-1].second)));
    }
    sort(v.begin(),v.end());

    ll ans = 0;
    for(auto i:v){
        if(!uni.same(i.second.first,i.second.second)){
            uni.unite(i.second.first,i.second.second);
            ans += i.first;
        }
    }
    cout<<ans<<endl;


    

}