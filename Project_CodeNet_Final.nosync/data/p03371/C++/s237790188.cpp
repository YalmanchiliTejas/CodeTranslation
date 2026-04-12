#include <bits/stdc++.h>
using namespace std;
void print() {
    cout << endl;
}
template <class Head, class... Tail>
void print(Head &&head, Tail &&... tail) {
    cout << head;
    if (sizeof...(tail) != 0)
        cout << " ";
    print(forward<Tail>(tail)...);
}
template <class T>
void print(vector<T> &vec) {
    for (auto &a : vec) {
        cout << a;
        if (&a != &vec.back())
            cout << " ";
    }
    cout << endl;
}
template <class T>
void print(vector<vector<T>> &df) {
    for (auto &vec : df) {
        print(vec);
    }
}
#define rep(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define xrep(i, a, b) for (int i = int(a); i < int(b); ++i)
using ll = long long;
const int INF = 1001001001;

int main() {
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;
    int min_cost = INF;
    for(int z=0; z<=300000; z+=2) {
        if (X-z/2<0 || Y-z/2<0) continue;
        int cost = A*(X-z/2)+B*(Y-z/2)+C*z;
        min_cost = min(cost, min_cost);
        if (cost==110000000) {
        }
    }
    int c = C*(max(X, Y))*2;

    print(min(min_cost, c));

    return 0;
}