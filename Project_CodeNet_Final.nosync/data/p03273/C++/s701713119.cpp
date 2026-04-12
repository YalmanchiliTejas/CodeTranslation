#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>  // std::greater<T>()
#include <numeric>  // accumulate(ALL(vec), 0)  0 は初期値

using namespace std;

// macro
#define ALL(obj) (obj).begin(), (obj).end()
#define REP(i, n) for (int i=0; i < (int)(n); i++)  // 0 ~ n-1
#define REPN(i, n) for (int i=1; i <= (int)(n); i++)  // 1 ~ n
#define DESCEND greater<int>()  // sort 降順
#define UNIQUE(vec) (vec).erase(unique(ALL((vec))), (vec).end());  // 必ずsortを行なってから
#define SUM(vec) accumulate(ALL((vec)), 0)

// func declaration
template <class T> void printVec(vector<T>);
template <class T> void calcVec(vector<T>&, int, char);
bool checkMultiple(vector<int>&, int);
int ctoi(const char);
vector<int> searchRow(vector<string>&, int);
vector<int> searchCol(vector<string>&, int, int);
template<class T> void remove(vector<T>&, unsigned int);

// const
const int INF = 10000000;

/*MEMO
辞書順
abc < abcd, atcoder < atlas
*/

int main() {
    int H, len_str;
    cin >> H >> len_str;
    vector<string> vec(H);
    REP(i, H) cin >> vec.at(i);

    int row = 0, col = 0;

    vector<int> white_row;
    white_row = searchRow(vec, len_str);
    vector<int> white_col;
    white_col = searchCol(vec, H, len_str);
    if (white_row.size() > 0) {
        REP(i, white_row.size()) {
            remove(vec, white_row.at(i) - i);
        }
    }
    if (white_col.size() > 0) {
        string target = ".";
        string replacement = "";
        REP(i, vec.size()) {
            REP(j, white_col.size()) {
                vec.at(i).replace(white_col.at(j) - j, 1, replacement);
            }
        }
    }
    REP(i, vec.size()) cout << vec.at(i) << endl;
    
    return 0;
}


// function
template<typename T> void remove(std::vector<T>& vector, unsigned int index) {
    vector.erase(vector.begin() + index);
}


template <class T> void printVec(vector<T> vec) {
    // 1要素ずつ、空白・改行なしで出力
    REP(i, vec.size()) {
        cout << vec.at(i);
    }

    cout << endl;
}

template <class T> void calcVec(vector<T> &vec, int num, char ch) {
    // vec全体への演算
    if (ch == '+') {
        REP(i, vec.size()) {
            vec.at(i) += num;
        }
    } else if (ch == '-') {
        REP(i, vec.size()) {
            vec.at(i) -= num;
        }
    } else if (ch == '*') {
        REP(i, vec.size()) {
            vec.at(i) *= num;
        }
    } else if (ch == '/'){
        REP(i, vec.size()) {
            vec.at(i) /= num;
        }
    } else if (ch == '%') {
        REP(i, vec.size()) {
            vec.at(i) %= num;
        }
    }
}

bool checkMultiple(vector<int> &vec, int num) {
    // vecの中身が、全てnumの倍数かどうかのチェック
    int count = 0;
    REP(i, vec.size()) {
        if (vec.at(i)%num != 0) count++;
    }
    return (count == 0);
}

int ctoi(const char c) {
    if('0' <= c && c <= '9') return (c-'0');
    return -1;
}

vector<int> searchRow(vector<string> &vec, int len_str) {
    // 全てが白の行
    string all_white;
    REP(i, len_str) all_white.push_back('.');

    vector<int> res_vec;
    REP(i, vec.size()) {
        if (vec.at(i) == all_white) {
            res_vec.push_back(i);  // 全て白の行を格納
        }
    }
    return res_vec;
}

vector<int> searchCol(vector<string> &vec, int H, int str_len) {
    // 全てが白の列
    vector<int> res_vec;

    REP(j, str_len) {
        int count = 0;
        REP(i, H) if (vec.at(i).at(j) == '.') count++;
        if (count == H) res_vec.push_back(j);  // 全て白の列を格納
    }
    return res_vec;
}
