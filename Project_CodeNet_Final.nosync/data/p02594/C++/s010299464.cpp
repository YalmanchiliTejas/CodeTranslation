#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <set>
#include <stack>
#include <bitset>
#include <map>
#include <ctime>
#include <numeric>


#ifndef M_PI
#define M_PI 3.141592653589
#endif
#define int long long
#define double long double

#ifdef TIME
#define start cin.tie(NULL); cout.tie(NULL); cout.setf(ios::fixed); cout.precision(10); ios_base::sync_with_stdio(false);int32_t START = clock()
#define finish cout << "\ntime: " << (clock() - START) / (CLOCKS_PER_SEC * 1.0); return 0
#endif

#ifndef TIME
#define start cin.tie(NULL); cout.tie(NULL); cout.setf(ios::fixed); cout.precision(10); ios_base::sync_with_stdio(false)
#define finish return 0
#endif

using namespace std;


//vector input
template<typename T>
istream &operator>>(istream &is, vector<T> &vec) {
    for (auto &i : vec) {
        cin >> i;
    }
    return is;
}

//pair output
template<typename E>
ostream &operator<<(ostream &os, pair<E, E> &t) {
    os << t.first << ' ' << t.second;
    return os;
}

//"map" pair output
template<typename E>
ostream &operator<<(ostream &os, pair<const E, E> &t) {
    os << t.first << ' ' << t.second;
    return os;
}

//vector output
template<typename T>
ostream &operator<<(ostream &os, vector<T> &vec) {
    for (T i : vec) {
        os << i << ' ';
    }
    return os;
}

//2 dimensional vector output
template<typename T>
ostream &operator<<(ostream &os, vector<vector<T> > &vec) {
    for (vector<T> i : vec) {
        os << i << '\n';
    }
    return os;
}


int32_t main() {
    start;

    int n;
    cin >> n;
    if (n >= 30) {
        cout << "Yes" << '\n';
    } else {
        cout << "No" << '\n';
    }

    finish;
}