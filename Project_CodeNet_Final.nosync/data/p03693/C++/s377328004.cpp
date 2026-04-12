#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

template<typename T>
void printmatrix(vector<vector<T> > ar){
    for (int i = 0; i < (int)ar.size(); i++) {
        for (int j = 0; j < (int)ar.size(); j++) {
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


int main(int argc, char const* argv[])
{
    string r,g,b;
    cin >> r >> g >> b;
    int x = stoi(g+b);
    if (x % 4 == 0) {
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }


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
