#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep1(i, n) for (int i = 1; i < (n); i++)
#define all(v) (v).begin(), (v).end()
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
using namespace std;
typedef long long LL;
const int INF = 999999999;

int main(){
    string l = "qazwsxedcrfvtgb";
    string s;
    cin >> s;
    while(s != "#"){
        int ans = 0;
        rep1(i, s.size()){
            if(l.find(s[i]) != string::npos && l.find(s[i-1]) == string::npos) ans++;
            if(l.find(s[i]) == string::npos && l.find(s[i-1]) != string::npos) ans++;
        }
        cout << ans << endl;
        cin >> s;
    }


}


