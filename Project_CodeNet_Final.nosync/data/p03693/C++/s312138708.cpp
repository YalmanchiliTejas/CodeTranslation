#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b){if(a < b){ a = b; return 1;} return 0;}
template<class T> inline bool chmin(T& a, T b){if(a > b){ a = b; return 1;} return 0;}

const int INF = 100000; 

int main(){
    int r, g, b;
    cin >> r >> g >> b;

    int ans =  r * 100 + g * 10 + b;

    if(ans % 4 == 0) cout << "YES" << endl;
    else cout << "NO" << endl;
    
    return 0;
}
