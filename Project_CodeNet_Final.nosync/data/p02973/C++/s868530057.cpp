#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef long long int lli;
using namespace std;
typedef pair<int, int> ii;
typedef priority_queue<int, vector<int>, greater<int> > heapq;
// #define int long long int

inline void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

signed main() {
    int N; cin >> N;
    vector<int> A(N);
    for (auto&& a: A) cin >> a;

    vector<int> stock;
    stock.push_back(A[0]);
    for (int i = 1; i < N; i++) {
        auto it = lower_bound(stock.begin(), stock.end(), A[i]);
        if (it == stock.end()) { // はじめ
            stock[stock.size() - 1] = A[i];
        } else if (it == stock.begin()) { // A[i]が最小
            stock.insert(stock.begin(), A[i]);
        } else {
            --it;
            *it = A[i];
        }
    }

    cout << stock.size() << endl;
}
