#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <utility>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <map>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int n, k;
    string s;
    cin >> n >> s >> k;
    k--;

    rep(i, n) {
        if(s[i] != s[k]) {
            s[i] = '*';
        }
    }

    cout << s << endl;
    return 0;
}