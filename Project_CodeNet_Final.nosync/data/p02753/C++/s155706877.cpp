#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using ll = long long;
using VI = vector<int>;
using VVI = vector<vector<int>>;
using P = pair<int, int>;

int main(){
    string s;
    cin >> s;
    if(s[0]==s[1] && s[1]==s[2]) cout << "No" << endl;
    else cout << "Yes" << endl;
    return 0;
}