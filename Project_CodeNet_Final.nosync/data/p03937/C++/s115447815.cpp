#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(n) begin(n),end(n)
using ll = long long;
using P = pair<int,int>;

int main() {
    int h, w,cnt = 0;
    cin >> h >> w;
    rep(i,h){
        string s;
        cin >> s;
        rep(j,w) if(s[j]=='#') cnt++;
    }
    if(cnt==(h+w-1)) cout << "Possible" << endl;
    else cout << "Impossible" << endl;
    return 0;
}