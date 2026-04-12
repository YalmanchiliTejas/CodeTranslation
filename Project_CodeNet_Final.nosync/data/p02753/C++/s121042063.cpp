// AtCoder template
// sabaより胡蝶しのぶさんの方が可愛いのではないか？
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i = 0; i < n; ++i)



int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    string s; cin >> s;
    if(s[0] == s[1] && s[1] == s[2]) cout << "No" << endl;
    else cout << "Yes" << endl;
}