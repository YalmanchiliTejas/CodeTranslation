#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
using ll = long long;
constexpr int INF = 1e9;
constexpr int MOD = 1e9 + 7;
template<class T> inline void chmax(T &a,T b){if(a<b)a=b;}
template<class T> inline void chmin(T &a,T b){if(a>b)a=b;}


int main(){
    cin.tie(0); ios_base::sync_with_stdio(false);
    int a,b,c;cin>>a>>b>>c;
    cout << (a-c) / (b+c) << endl;
    return 0;
}