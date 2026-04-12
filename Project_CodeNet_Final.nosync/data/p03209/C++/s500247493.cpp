#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <set>
#include <iomanip>
#include <stack>
#include <array>
#include <fstream>
#include <cstdint>
#include <cmath>
#include <algorithm>
#include <utility>
#include <numeric>
#include <functional>
using namespace std;
typedef int64_t ll;
typedef uint64_t ull;
constexpr uint64_t L1 = 1ull;
constexpr ull bit(int n){ return 1ull << n;}

constexpr ll INF       = 1000000000;/* 1e+9a */

array<ll, 51> bag_size, pat;

ll eat(ll N, ll X){
    ll ans = 0;
    X -= 1;
    if(X <= 0){
        return 0;
    }
    if(X < bag_size[N-1]){
        return eat(N-1, X);
    }
    X -= bag_size[N-1];
    ans += pat[N-1];
    if(X == 0) return ans;
    ans++;
    X--;
    if(X < bag_size[N-1]){
        return eat(N-1, X) + ans;
    }
    return pat[N];
    
}


void solve(istream& cin) {
    bag_size[0] = 1;
    pat[0] = 1;
    for (int i = 1; i < bag_size.size(); ++i) {
        bag_size[i]  = 3 + 2*bag_size[i-1];
        pat[i] = 1 + 2 * pat[i-1];
    }// i
    ll N, X;
    while(cin >> N >> X){
        cout << eat(N, X) << endl;
        
    }
}

int main(int argc, char *argv[]) {
    string FileName("D"), Modifier("_MEPH");
    string ExecutionName = FileName + Modifier;
    string sub(argv[0]);
    // pass消去
    if(sub.size() > ExecutionName.size())
        sub = sub.substr(sub.size()-ExecutionName.size(), ExecutionName.size());

	// 数値計算もの用
    cout << setprecision(16) << scientific;
    if (sub != ExecutionName) {
        cin.tie(0);
        ios::sync_with_stdio(false);
        solve(cin);
    }
    else {    
	    cerr << sub << endl;
        string inFile = "D_sample.txt";
        auto fs = fstream(inFile, fstream::in);
        solve(fs);
    }
}
