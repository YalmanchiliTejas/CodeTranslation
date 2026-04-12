#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
 
/* attention
    long longのシフト演算には気をつけよう
    タイポした時のデバッグが死ぬほどきつくなるので変数名は最低3字くらい使った方がいいかも
    sizeは(int)とキャストしよう
    ごちゃごちゃ場合分けを考える前に全探索は考えましたか？
*/

class UnionFind{
public:
    //親の番号を格納する。親だった場合はー（その集合のサイズ）
    vector<int> parents;

    //作る時はparentsを-1で初期化する
    //こうすることで全部ばらばらになる
    UnionFind(int n){
        parents = vector<int>(n, -1);
    }

    //Aがどのグループにいるか調べる
    int root(int A){
        if(parents[A]<0) return A;
        return parents[A] = root(parents[A]);
    }

    //自分のいるグループの大きさを調べる
    int size(int A){
        return -parents[root(A)];
    }

    //AとBをくっつける
    bool connect(int A, int B){
        //AとBを直接ではなく親同士をくっつける
        A=root(A);
        B=root(B);
        if(A==B){
            return false;
        }

        //大きい方（A)に小さい方（B)をくっつけたい
        if(size(A)<size(B)) swap(A, B);

        parents[A] += parents[B];
        parents[B] = A;

        return true;
    }
};


int main(){
    int N; cin >> N;
    
    cout << 800*N - 200*(N/15) << endl;
    return 0;
}