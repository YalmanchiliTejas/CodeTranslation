#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#define llong long long
#define INF (__INT32_MAX__ / 2)
#define EPS 10e-8

using namespace std;
typedef pair<int, int> ipair;
llong modulo(llong left, llong right) { return (left % right + right) % right; }

int main(int argc, char **argv) {
    int N, A[100000];
    cin >> N;
    for(int i = 0; i < N; ++i)
        cin >> A[i];

    multiset<int> iset;
    for(int i = 0; i < N; ++i) {
        auto it = iset.lower_bound(A[i]);

        if(it == iset.begin()) {
            iset.insert(A[i]);
        } else {
            iset.erase(--it);
            iset.insert(A[i]);
        }
    }
    
    cout << iset.size() << endl;
}