#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<n;i++)
using namespace std;
typedef long long ll;


int main(){
    int n, ALP[26];
    rep(i,26) ALP[i] = 100;
    cin >> n;
    rep(i,n){
        int alp[26] = {};
        string s;
        cin >> s;
        rep(j,s.size()){
            int cn = s[j] - 97;
            alp[cn] ++;
        }
        rep(k,26){
            ALP[k] = min(ALP[k], alp[k]);
        }
    }
    string ans = "";
    rep(i,26){
        char c = i + 97;
        if(ALP[i] > 0) rep(j, ALP[i]) ans += c;
    }
    cout << ans << endl;
}