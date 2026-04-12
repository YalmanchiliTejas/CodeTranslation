#include <iostream>
#include <string>
#include <complex>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
#include <stack>
#include <algorithm>
#include <list>
#include <ctime> 
#include <memory.h>
#include <assert.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;
const int INF = 1e9 + 1;
const ll LLINF = 1e18 + 1;

int main() {
    int N;
    cin >> N;
    string s;
    cin >> s;
    int K;
    cin >> K; 
    K--;

    for(int i = 0; i < s.size(); i++) {
        if(s[K] == s[i]) continue;
        s[i] = '*';
    }

    cout << s << endl;

    return 0;
}