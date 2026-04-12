#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(v) (v).begin(),(v).end()
using ll = long long;
using P = pair<int, int>;

int main(){
    string s;
    cin >> s;
    int cnt = 0;
    rep(i, 3) {
        if (s[i]=='A') cnt++;
    }
    if (cnt==0 || cnt==3) puts("No");
    else puts("Yes");
    return 0;
}