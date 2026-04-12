// https://twitter.com/tanakh/status/1152575899306323968
// https://atcoder.jp/contests/abc134/submissions/6466342

#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <tuple>
#include <cmath>
#include <cstring>
#include <cstdio>

using namespace std;

#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;

int N;
int A[100001];

void print(std::multiset<int> &s, int x) {
    cout << "s = {";
    for (auto y : s) { cout << y << ", "; }
    cout << "}, x = " << x << endl;
}

int main() {
    std::multiset<int> s;
    scanf("%d", &N);
    rep(i, N) scanf("%d", &A[i]);
    
    rep(i, N) {
        int x = A[i];
        auto it = s.upper_bound(-x);
        if (it == s.end()) {
            s.insert(-x);
        } else {
            s.erase(it);
            s.insert(-x);
        }
    }
    cout << s.size() << endl;
    return 0;
}