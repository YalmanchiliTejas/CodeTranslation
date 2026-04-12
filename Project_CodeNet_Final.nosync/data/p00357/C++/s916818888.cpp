#include <bits/stdc++.h>

using namespace std;

#define int long long
#define INF 1e9
#define LINF 1e18

typedef unsigned long long ull;
typedef pair<int, int> P;
typedef pair<int, P> Pi;

typedef pair<P, P> PP;

const int MOD = 1e9 + 7;
const int dy[] = { 0, 0, 1, -1 };
const int dx[] = { 1, -1, 0, 0 };

template <class T> void chmin(T& a, const T& b) { a = min(a, b); }
template <class T> void chmax(T& a, const T& b) { a = max(a, b); }

int N, d[300000];

signed main() {
	cin.tie(0);
    ios::sync_with_stdio(false);
    
    cin >> N;
    for(int i = 0; i < N; ++i) cin >> d[i];
   	int maxi = d[0] - 10;
    for(int i = 1; i < N; ++i) {
    	if(maxi < 0) {
    		cout << "no" << "\n";
    		return 0;
    	}
    	if(maxi < d[i]) maxi = d[i] - 10;
        else maxi -= 10;
    }
    reverse(d, d + N);
    maxi = d[0] - 10;
    for(int i = 1; i < N; ++i) {
    	if(maxi < 0) {
    		cout << "no" << "\n";
    		return 0;
    	}
    	if(maxi < d[i]) maxi = d[i] - 10;
        else maxi -= 10;
    }
    cout << "yes" << "\n";
	return 0;
}

