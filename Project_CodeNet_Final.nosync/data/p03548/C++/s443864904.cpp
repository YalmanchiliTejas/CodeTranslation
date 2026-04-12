#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <math.h>
#include <algorithm>
#include <deque>
#include <queue>
#include <climits>
#include <set>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ve vector
#define umap unordered_map
#define iter iterator

void solve() {
    int x,y,z;cin>>x>>y>>z;
    cout << (x-z)/(y+z) << endl;
}

int main() {
    solve();
    return 0;
}