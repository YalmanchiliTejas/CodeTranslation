#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <bitset>
#include <sstream>
#include <iomanip>

using namespace std;

typedef long long ll;

void to_pray() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cerr << "Ready\n";
}

const int N = 4e6 + 10;
const int MOD = 1e9 - 7;
const int INF = 1e9 + 7;

char a[101][101];

bool h[N], w[N];

int main () {
    to_pray();
    
    int n, m;
    cin >> n >> m;
    
    for (int i = 1; i <= n; ++ i) {
    	for (int j = 1; j <= m; ++ j) {
    		cin >> a[i][j];
    		if (a[i][j] == '#') {
    			h[i] = true;
    			w[j] = true;
    		}	
    	}
    }
    
    for (int i = 1; i <= n; ++ i) {
   		if (!h[i])
   			continue;
   		for (int j = 1; j <= m; ++ j) {
   			if (!w[j])
   				continue;
   			cout << a[i][j];
   		}
   		cout << '\n';
    }
    
    cerr << '\n';
    return 0;
}