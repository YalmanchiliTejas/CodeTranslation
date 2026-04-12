#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <utility>
#include <iomanip>
#include <cmath>
using namespace std;
#define REP(i,n) for (int i=0;i<(n);++i)
#define rep(i,a,b) for(int i=a;i<(b);++i)
template<class T> inline bool chmin(T &a, T b){ if(a > b) { a = b; return true;} return false;}
template<class T> inline bool chmax(T &a, T b){ if(a < b) { a = b; return true;} return false;}
using ll = long long;
constexpr ll INF = 1LL << 60;
constexpr ll MOD = 1e9 + 7;


int main() {
    cin.tie(0); ios_base::sync_with_stdio(false);
    int N;cin>>N;
    cout << N*800-(N/15)*200 << endl;
    return 0;
}