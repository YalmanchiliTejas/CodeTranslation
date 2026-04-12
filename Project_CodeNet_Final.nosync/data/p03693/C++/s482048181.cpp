#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long;
using P = pair<int,int>;
int main(void) {
    int r, g, b; cin >> r >> g >> b;
    int ans = 100*r + 10*g + b;
    if(ans%4==0) cout <<"YES";
    else cout << "NO";
}
