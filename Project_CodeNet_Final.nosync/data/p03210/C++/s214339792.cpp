#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const ll INF=(1LL<<60);
const int mod=1000000007;

int main(void){
    int x; cin >> x;
    if(x==3 || x==5 || x==7) cout << "YES" << endl;
    else cout << "NO" << endl;
}