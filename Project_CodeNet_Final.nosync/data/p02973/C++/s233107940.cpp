#include <bits/stdc++.h>
using namespace std;

/*
vector.push_back()
vector<int> hoge(3,-1); {-1,-1,-1}
vector<vector<int>> hogehoge(2,vector<int>(2,-1)); {{-1,-1},{-1,-1}} 
cin >>temp;
scanf("%d %d %d",&A,&B,&Q);
sort(a.begin(),a.end());
a.push_back(4000000000000);
a.insert(a.begin(),-1000000000000);
upper_bound(a.begin(),a.end(),x); // list[i] > x のイテレータ取得. *itrで数値化 
*/

int checkpoint_num=0;
void pcheck(){
    cout << "----------------" << endl << checkpoint_num << endl << "----------------" << endl;
    checkpoint_num +=1;
}

template <typename T> void debug(T arr){
    for (auto col:arr){
        cout << col << " ";
    }
    cout <<endl;
}

template <typename T> void debug (T arr, int dim){
    for (auto raw:arr){
        for(auto col:raw){
            cout << col << " ";
        }
        cout << endl;
    }
}

class UnionFind {
    public:
    vector<int> par; // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2

    UnionFind(int N) : par(N+1) { //最初は全てが根であるとして初期化
        for(int i = 0; i < N+1; i++) par[i] = i;
    }

    int root(int x) { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
        if (par[x] == x) return x;
        return par[x] = root(par[x]);
    }

    void unite(int x, int y) { // xとyの木を併合
        int rx = root(x); //xの根をrx
        int ry = root(y); //yの根をry
        if (rx == ry) return; //xとyの根が同じ(=同じ木にある)時はそのまま
        par[rx] = ry; //xとyの根が同じでない(=同じ木にない)時：xの根rxをyの根ryにつける
    }

    bool same(int x, int y) { // 2つのデータx, yが属する木が同じならtrueを返す
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }
};



int main(void){
    int n,a;
    scanf("%lld",&n);
    vector<long long> arr(n,0);
    vector<long long> buf(n,-1);
    long long col = 0;
    for (int i = 0; i < n; ++i){
        cin >> a;
        arr[i] = a;
    }

    for (int i = 0; i < n; ++i){
        long long temp = arr[i];
        if (buf[n-1] < temp){
            buf[n-1] = temp;
        }else{
            auto key = lower_bound(buf.begin(),buf.end(),temp);
            --key;
            *key = temp;
        }
    }
    int c = 0;
    for (int i =0; i < n; ++ i){
        if (buf[i] != -1){
            c += 1;
        }
    }
    cout << c << endl;
};
