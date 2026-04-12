#include<iostream>
#include<iomanip>
#include<vector>
#include<map>
#include<stack>
#include<queue>
#include<string>
#include<utility>
#include<numeric>
#include<algorithm>
#include<cmath>
#include<climits>
using namespace std;

using ll = long long;

class Stream{
public:
    Stream(){

    }
    //配列以外の入力を受け取る
    void read(){

    }
    template<typename First, typename... Rest>
    void read(First& first, Rest&... rest){
        cin >> first;
        read(rest...);
    }
    //配列を区切って出力する
    template<typename T>
    void write_vec(vector<T>& v, char divider){
        for(size_t i = 0; i < v.size(); i++){
            cout << v[i] << divider;
        }
    }
};

struct UF{
    const int node_num;
    vector<int> parent;
    vector<int> size;

    UF(int N) : node_num(N), parent(N), size(N, 1) {
        for(int i = 0; i < N; ++i) parent[i] = i;
    }

    //xの根を得る
    int root(int x){
        if(parent[x] == x) return x;
        return parent[x] = root(parent[x]);
    }

    //xが属する木とyが属する木を一つに合わせる
    void unite(int x, int y){
        int root_x = root(x);
        int root_y = root(y);
        if(root_x == root_y) return;
        parent[root_y] = root_x;
        size[root_x] += size[root_y];
    }

    //xとyが属する木が同じならtrueを返す
    bool same(int x, int y){
        int root_x = root(x);
        int root_y = root(y);
        return root_x == root_y;
    }

    //xと同じ木に属する要素の数を返す
    int same_size(int x){
        int root_x = root(x);
        return size[root_x];
    }
};

int main(){
    Stream io;
    
    char c;
    io.read(c);
    switch(c){
        case 'a':
        case 'i':
        case 'u':
        case 'e':
        case 'o':
        cout << "vowel";
        break;
        default:
        cout << "consonant";
    }

    return 0;
}