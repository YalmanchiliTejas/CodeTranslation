#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())

// {{{
template<typename T>
void printmatrix(vector<vector<T> > ar){
    for (int i = 0; i < (int)ar.size(); i++) {
        for (int j = 0; j < (int)ar[0].size(); j++) {
            cout << ar[i][j];
        }
        cout << endl;
    }
}

template<typename T>
void printvector(vector<T> vec){
    for (int i = 0; i < (int)vec.size(); i++) {
        cout << vec[i] << endl;
    }
}

template<typename T>
void unique(vector<T>& vec){
    sort(vec.begin(), vec.end());
    vec.erase(unique(vec.begin(), vec.end()), vec.end());
}

template<typename T>
vector<T> cumsum(vector<T> vec){
    vector<T> newvec((T)vec.size());
    int tmp = 0;
    for (int i = 0; i < (int)vec.size(); i++) {
        tmp += vec[i];
        newvec[i] = tmp;
    }

    return newvec;
}

template<typename T>
T digitsum(T x){
    T y=0;
    while(x){
        y += x % 10;
        x /= 10;
    }

    return y;
}

template<typename T>
T gcd(T x, T y){
    if (x == 0 || y == 0) {
        return 0;
    }

    while (x != y){
        if (x > y) {
            x -= y;
        }else{
            y -= x;
        }
    }
    return x;
}

// }}}

int vector_finder(std::vector<int> vec, int number) {
  auto itr = std::find(vec.begin(), vec.end(), number);
  size_t index = std::distance( vec.begin(), itr );
  if (index != vec.size()) { // 発見できたとき
    return 1;
  }
  else { // 発見できなかったとき
    return 0;
  }
}
/* vim:set foldmethod=marker: */

void solve(){
    int H, W;
    cin >> H >> W;
    vector<vector<char> > board(H, vector<char>(W, '.'));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> board[i][j];
        }
    }

    // printmatrix(board);
    vi row, col;
    for (int i = 0; i < H; i++) {
        bool truth=true;
        for (int j = 0; j < W; j++) {
            if (board[i][j] == '#') {
                truth=false;
            }
        }
        if (truth) {
            row.push_back(i);
        }
    }

    for (int j = 0; j < W; j++) {
        bool truth=true;
        for (int i = 0; i < H; i++) {
            if (board[i][j] == '#') {
                truth=false;
            }
        }
        if (truth) {
            col.push_back(j);
        }
    }



    for (int i = 0; i < H; i++) {
        bool truth=false;
        for (int j = 0; j < W; j++) {

            if (!vector_finder(row, i) && !vector_finder(col, j)) {
                cout << board[i][j];
                truth=true;
            }
        }
        if (truth){
            cout << endl;
        }
    }

    return;
}

int main(int argc, char const* argv[])
{
    solve();
    return 0;
}

// sortの仕方
// int a[N];
// array<int,N> ar;
// vector<int> v;
//
// sort(a, a+N); // 配列
// sort(ar.begin(), ar.end()); // array
// sort(v.begin(), v.end()); // vector 昇順
// sort(v.begin(), v.end(), greater<int>()); // 降順

// Template
// template <class T>
// T foomax(T x, T y){
//   if (x > y){
//     return x;
//   }else{
//     return y;
//   }
// }

// string を int に変換 stoi("1010")
// int を string に変換 to_string(1010)


// map の key, value を全て抜き出す。
// for (auto itr = mp.begin(); itr != mp.end(); itr++) {
//     cout << "key" << itr->first << " value" << itr->second << endl;
// }

// 文字列の検索
// string s="abc";
// if (s.find('d') == string::npos){
//     cout << "find" << endl;
// }else{
//     cout << "not find" << endl;
// }
