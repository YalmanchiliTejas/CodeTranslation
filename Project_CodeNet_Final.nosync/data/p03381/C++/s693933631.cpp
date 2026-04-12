#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <string>
#include <utility>
#include <algorithm>
#include <functional>
#include <deque>
#define INF 1e9
#define MAX_N 200001

using namespace std;

typedef long long ll;
typedef pair<int,int> P;

int main() {
    int N;
    int X[MAX_N];
    int sorted_X[MAX_N];
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> X[i];
        sorted_X[i] = X[i];
    }
    sort(sorted_X, sorted_X + N);
    
    int l = sorted_X[N/2 - 1];
    int r = sorted_X[N/2];
    
    for (int i = 0; i < N; ++i) {
        if (X[i] <= l) {
            printf("%d\n", r);
        } else {
            printf("%d\n", l);
        }
    }
    
    return 0;
}
