#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <sstream>
#include <typeinfo>
#include <fstream>
#include <limits>

using namespace std;

template<class T = int,T divided_by = 10>
constexpr T PINF(){ return std::numeric_limits<T>::max()/divided_by; }
template<class T = int,T divided_by = 10>
constexpr T MINF(){ return std::numeric_limits<T>::lowest()/divided_by; }

template<class T = int> T gcd(T a, T b){ return b ? gcd(b,a%b) : a; }
template<class T = int> T lcm(T a, T b){ return a / gcd(a,b) * b; }
template<class T = int> T lcm_safe(T a, T b){ T p = a/gcd(a,b); return (b <= PINF<T>()/p) ? p*b:PINF<T>(); }
//オーバーフローするとき+INFを返す
//
int main() {
	cin.tie(nullptr); ios::sync_with_stdio(false);
	int n,m;
	cin >> n >> m;

	vector<set<int>> v(n);
	for(int i = 0; i < m; ++i){
		int a,b;
		cin >> a >> b;
		a--;
		b--;
		v[a].insert(b);
		v[b].insert(a);
	}

	vector<vector<int>> seqs(100000, vector<int>());

	vector<int> nodes(n-1);
	for(int i = 0; i < nodes.size(); ++i){
		nodes[i] = i+1;
	}
    int ans = 0;
    do {
    	// for(auto nextNode : nodes) cout << nextNode << " "; cout << "\n";    // v の要素を表示
    	int curNode = 0;
    	bool isOk = true;
        for(auto nextNode : nodes) {
        	bool hasNextNode = v[curNode].find(nextNode) != v[curNode].end();
        	isOk = isOk && hasNextNode;

        	curNode = nextNode;
        }
        if(isOk) ans++;
    } while( next_permutation(nodes.begin(), nodes.end()) );     // 次の順列を生成

    cout << ans << endl;
	return 0;
}