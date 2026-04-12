#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <stack>
#include <math.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
using namespace std;
template<class T> inline bool chmax(T& a, T b){ if(a < b) { a=b; return 1; }return 0;}
template<class T> inline bool chmin(T& a, T b){ if(a > b) { a=b; return 1; }return 0;}
const long long INF = 1LL << 60;

// --------write my code!!!!!----------//

int main(){
    int n; cin >> n;
    if(n==3 || n==5 || n==7) cout << "YES" << endl;
    else cout << "NO" << endl;
}
